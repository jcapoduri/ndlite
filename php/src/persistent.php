<?php

/*

*/

namespace nd;

// To Do
class PersistentField {
	public static $_nd_fields = array(
			array(
				"name" => "id",
				"isKey" => true,
				"unique" => true,
				"autoincremental" => true,
				"type" => "number"
			),
			array(
				"name" => "usrid",
				"type" => "number"
			),
			array(
				"name" => "ctime",
				"type" => "timestamp"
			),
			array(
				"name" => "mtime",
				"type" => "timestamp"
			),
			array(
				"name" => "dtime",
				"type" => "timestamp"
			),
			array(
				"name" => "deleted",
				"type" => "bool"
			),
		);

	public function __construct($json) {
		$this->_relationName = null;
		$this->_objectName = null;
		$this->_enums = null;

		$this->_name = $json["name"];
		$this->_type = $json["type"];
		$this->_isKey = isset($json["isKey"]) ? $json["isKey"] : false;
		$this->_unique = isset($json["unique"]) ? $json["unique"] : false;
		if(isset($json["enum_values"])) $this->_enums = $json["enum_values"];

		if(isset($json["object_name"])) $this->_objectName = $json["object_name"];
		if(isset($json["relation_name"])) $this->_relationName = $json["relation_name"];

		if(isset($json["default"])){
			$this->_default = $json["default"];
		}else{
			switch($this->_type){
				case "string":
					$this->_default = "";		
					break;
				case "decimal":
					$this->_default = 0.0;
					break;
				case "number":
					$this->_default = 0;
					break;
				case "bool":
					$this->_default = false;
					break;
				case "array":
					$this->_default = array();
					break;
				case "time";
				case "date";
				case "timestamp";
					$this->_default = "now";
					break;
				default;
					$this->_default = -1;
					break;
			};
		};

		$this->_value = $this->_default;
	}

	public function name() { return $this->_name; }
	public function type() { return $this->_type; }
	public function storeValue() { 
		switch($this->_type){
			case "string":
				return "'" . $this->_value . "'";		
				break;
			case "bool":
				$ret = ($this->_value) ? 1 : 0;
				return $ret;
				break;
			case "time":
				if ( $this->_value == "now"){
					return "CURTIME()";
				}else{
					return "'" . date("", $this->_value) . "'";
				};
				break;
			case "date":
			if ( $this->_value == "now"){
					return "CURDATE()";
				}else{
					return "'" . date("", $this->_value) . "'";
				};
				break;
			case "timestamp":
				if ( $this->_value == "now"){
					return "NOW()";
				}else{
					return "'" . date("", $this->_value) . "'";
				};
				break;
				
			default:
				return $this->_value;
		};
	}
	public function isKey() { return $this->_isKey; }
	public function unique() { return $this->_unique; }
	public function defaultValue() { return $this->_default; }
	public function value() { return $this->_value; }
	public function setValue($value) { 
		//To Do emuns
		$this->_value = $value; 
		$this->_seal = false;
	}  
	public function enums() { 
		//ToDo
		return $this->_enums;
	}

	public function relationName() { return $this->_relationName; }
	public function objectName() { return $this->_objectName; }

	public function toDefault() { $this->_value = $this->_default; } 

	public function toJsValue() {
		$val = '';

		switch($this->_type){
			case "string":
				$val = '"' . $this->_value . '"';
				break;
			case "bool":
				$val = ($this->_value) ? '"true"' : '"false"';
				break;
			case "time":
				$val = "'" . date("", $this->_value) . "'";
				break;
			case "date":
				$val = "'" . date("", $this->_value) . "'";
				break;
			case "timestamp":
				$val = "'" . date("", $this->_value) . "'";
				break;
			default:
				$val = '"' . $this->_value . '"';
		};

		return $val;
	}

	public function seal() { $this->_seal = true; }
	public function isSealed() { return $this->_seal; }

	private $_type;
	private $_name;
	private $_isKey;
	private $_unique;
	private $_default;
	private $_enums;
	private $_relationName;
	private $_objectName;

	private $_value;
	private $_seal = false;
};

// To Do
class Persistent{
	public function __construct($json, $id = 0){
		$this->_name = $json["name"];
		$this->_tablename = isset($json["tablename"]) ? $json["tablename"] : $json["name"];
		$this->_fields = array();

		if(isset($json["nd_fields"]) && $json["nd_fields"]) {
			$i = count(PersistentField::$_nd_fields);
			$field_name;
			while ($i--) {				
				$field_name = PersistentField::$_nd_fields[$i]["name"];
				$this->_fields[$field_name] = new PersistentField(PersistentField::$_nd_fields[$i]);
			};
		};

		$i = count($json["fields"]);
		while ($i--) {
			$this->_fields[$json["fields"][$i]["name"]] = new PersistentField($json["fields"][$i]);
		};

		$this->setAttr("id", $id);
		if($id != 0) $this->update();
	}

	public function storeAttr($key){
		if(array_key_exists($key, $this->_fields))
			return $this->_fields[$key]->storeValue();
		else
			return null;
	}

	public function attr($key){
		if(array_key_exists($key, $this->_fields))
			return $this->_fields[$key]->value();
		else
			return null;
	}

	public function setAttr($key, $val){
		if(array_key_exists($key, $this->_fields)){
			$this->_fields[$key]->setValue($val);
			return true;
		} else
			return false;		
	}

	public function field($key){
		if(array_key_exists($key, $this->_fields))
			return $this->_fields[$key];
		else
			return null;	
	}

	public function keys() {
		$i = count($this->_fields);
		$keys = array();
		while($i--) if($this->_fields[$i]->isKey()) $keys[] = $this->_fields[$i];
		return $keys;
	}

	/* Controller Ops*/
	public function toJSON(){
		$ret = array();
		$len = count($json["fields"]);
		for ($i = 0; $i < $len; $i++) {
			$ret[$this->_fields[$i]->name()] = $this->_fields[$i]->toJsValue();
		};
		return json_encode($ret);
	}

	public function fromJSON($json){
		$len = $len_after = count($this->_attr);
		$len_before = count($json);
		$json_keys = array_keys($json);
		$ok = true;
		$key_value = "";
		$loaded = array();
		while($len--){
			$loaded[$this->_attr[$len]] = false;
		};
		while ($len_before-- && $ok) {
			$key_value = $json_keys[$len_before];
			$ok = $this->setAttr($key_value, $json_keys[$key_value]);
			$loaded[$this->_attr[$len]] = true; 
		};
		while($len_after-- && $ok) $ok = $ok && $loaded[$len_after];
		return $ok;
	}

	public function seal() {
		$ok = true;
		$i = 0;
		$len = count($this->_fields);
		while ($ok && $i < $len) {
			$this->_fields[$i]->seal();
			$i++;
		}; 
	}

	public function isSealed() {
		$ok = true;
		$i = 0;
		$len = count($this->_fields);
		while ($ok && $i < $len) {
			$ok = $ok && $this->_fields[$i]->isSealed();
			$i++;
		}; 
	}

	/* CRUD operations*/
	public function commit(){
		NdLite::storage()->commit($this);
	}

	public function update(){
		NdLite::storage()->update($this);
	}

	public function erase(){
		NdLite::storage()->erase($this);
	}

	public function unerase(){
		NdLite::storage()->unerase($this);
	}

	public function touch(){
		NdLite::storage()->touch($this);
	}

	private $_name;
	private $_tablename;
	private $_fields;

};

?>