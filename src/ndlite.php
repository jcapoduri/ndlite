<?php

/**
* Neodymium Lite
* 2013
*
* minimalistic ORM library
*/

namespace nd;

require 'storage.php';
require 'persistent.php';
require 'relationship.php';

/**
* Singleton main class
*/

class Storage extends StorageEngine{
	private $_storages = array();

	public function __construct($json) {
		/*var_dump($json);
		if(is_array($json)){
			$len = count($json);
			while($len--){
				$this->addStorage($json[$len]);
			};
		}else{
			$this->addStorage($json);
		};*/
		$this->addStorage($json);
	}

	public function init(){
		$i = count($this->_storages);
		$ok = true;
		while ($i--) {
			$ok = $ok && $this->_storages[$i]->init();
		}
		return $ok;
	}

	private function addStorage($data) {
		if($data["type"] == "database"){
			if($data["db_type"] == "mysql"){
				$this->_storages[] = new MySqlEngine($data);
			};
		};
	}

	public function commit(Persistent $obj) {
		$i = count($this->_storages);
		$ok = true;
		while ($i--) {
			$ok = $ok && $this->_storages[$i]->commit($obj);
		}
		return $ok;
	}

	public function update(Persistent $obj) {
		$i = count($this->_storages);
		$ok = true;
		while ($i--) {
			$ok = $ok && $this->_storages[$i]->update($obj);
		}
		return $ok;
	}

	public function erase(Persistent $obj) {
		$i = count($this->_storages);
		$ok = true;
		while ($i--) {
			$ok = $ok && $this->_storages[$i]->erase($obj);
		}
		return $ok;
	}

	public function unerase(Persistent $obj) {
		$i = count($this->_storages);
		$ok = true;
		while ($i--) {
			$ok = $ok && $this->_storages[$i]->unerase($obj);
		}
		return $ok;
	}

	public function touch(Persistent $obj) {
		$i = count($this->_storages);
		$ok = true;
		while ($i--) {
			$ok = $ok && $this->_storages[$i]->touch($obj);
		}
		return $ok;
	}

	public function beginTransaction() {
		$i = count($this->_storages);
		$ok = true;
		while ($i--) {
			$ok = $ok && $this->_storages[$i]->beginTransaction();
		}
		return $ok;
	}
	public function commitTransaction() {
		$i = count($this->_storages);
		$ok = true;
		while ($i--) {
			$ok = $ok && $this->_storages[$i]->commitTransaction();
		}
		return $ok;
	}

	public function rollbackTransaction() {
		$i = count($this->_storages);
		$ok = true;
		while ($i--) {
			$ok = $ok && $this->_storages[$i]->rollbackTransaction();
		}
		return $ok;
	}

	public function generateStorageObject(Persistent $obj){
		$i = count($this->_storages);
		$ok = true;
		while ($i--) {
			$ok = $ok && $this->_storages[$i]->generateStorageObject($obj);
		}
		return $ok;
	}

	public function generateRelationObject(Relationship $obj){
		$i = count($this->_storages);
		$ok = true;
		while ($i--) {
			$ok = $ok && $this->_storages[$i]->generateRelationObject($obj);
		}
		return $ok;
	}

}

class NdLite {
	static private $instance = 0;

	private $_opts = array();
	private $_storage;
	private $_objects;

	private function __construct(array $opts){
		if(!empty($opts)) $this->_opts = $opts;
		$objs = $this->_opts["objects"];
		var_dump($objs);
		$len = count($objs);
		$obj;
		while($len--) {
			$obj = $objs[$len];
			$this->_objects[$obj["name"]] = $obj;
		};
	}

	public function __destruct(){

	}

	public static function init(array $opts){
		if(self::$instance) delete(self::$instance);
		self::$instance = new NdLite($opts);		
	}

	public static function initStorage(){
		self::$instance->_storage = new Storage(self::$instance->_opts["storage"]);
		return self::$instance->_storage->init();
	}

	public static function loadJSONfile($file) {
		$content = utf8_encode(file_get_contents($file));
		return json_decode($content, true);
	}

	public static function instance() { return self::$instance; }

	public static function storage() { return self::$instance->_storage; }

	public static function get($name, $id = 0){
		$ret = null;
		$objs = self::$instance->_objects;
		if(isset($objs[$name])){
			$ret = new Persistent($objs[$name]);
		};
		return $ret;
	}
	
};

?>