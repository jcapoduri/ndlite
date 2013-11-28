<?php

/**
* Neodymium Lite
* 2013
*
* minimalistic ORM library
*/

namespace nd;

class MySqlEngine extends StorageEngine {
	public function init(){
		$this->_handler = new \mysqli();
	}

	public function commit(Persistent $obj){
		$query;
		$keys = $t->keys();
		$len = count($keys);
		$values = array();
		$fields = array();
		$val;

		if ($obj->attr("id") == 0) {
			$query = "INSERT INTO " . $obj->tablename();	

			while($len--){
				$val = $obj->storeAttr($keys[$len]);
				array_push($fields, $keys[$len]);
				array_push($values, $val);
			};

			$query .= ' (' . implode(', ', $fields) . ') VALUES (' . implode(', ', $values) . ')';
		} else {
			$query = "UPDATE " . $this->_tablename . ' SET ';

			while($len--){
				$val = $obj->attr($keys[$len])->storeAttr();
				array_push($fields, $keys[$len] . " = " . $obj->fistoreAttr());
				$val = is_numeric($this->_attr[$keys[$len]]) ? $this->_attr[$keys[$len]] : '\'' . $this->_attr[$keys[$len]] . '\'';
				array_push($fields, '\'' . $keys[$len] . '\' = ' . $val);
			};

			$query .= implode(', ', $fields) . ' WHERE id = ' . $this->id();
		};
		$this->valid = $this->_handler->query($query);
		/*$this->valid = Connection::query($query);
		$this->setAttr("id", Connection::lastInsertedId());*/
	}

	public function update(Persistent $obj){
		$query = 'SELECT * FROM '. $obj->tablename() . ' WHERE ';
		$fields = $obj->keys();
		$where_closure = array();
		$len = count($fields);
		while($len--){
			$where_closure[] = '(' . $fields[$len]->name() . ' = ' . $fields[$len]->storeValue() . ')';
		};

		$query .= join(' AND ', $where_closure);
		$ret = $this->_handler->query($query);
		if ($value = $ret->fetch_assoc()) {
			return true;
			$obj->fromJSON($value);
		} else return false;

	}

	public function erase(Persistent $obj){
		$query = "UPDATE " . $this->_tablename . ' SET delete = 1 WHERE id = ' . $this->id();
		$this->setAttr("deleted", true);
		$this->valid = Connection::query($query);
	}

	public function unerase(Persistent $obj){
		$query = "UPDATE " . $this->_tablename . ' SET delete = 0 WHERE id = ' . $this->id();
		$this->setAttr("deleted", false);
		$this->valid = Connection::query($query);
	}

	public function touch(Persistent $obj){
		$query = "UPDATE " . $this->_tablename . ' SET mdate = CURDATE() WHERE id = ' . $this->id();
		$this->valid = Connection::query($query);		
	}

	public function commitRelation(Relation $rel){}

	public function updateRelation(Relation $rel){}

	public function beginTransaction(){
		//To Do
	}

	public function commitTransaction(){
		//To Do
	}

	public function rollbackTransaction(){
		//To Do
	}

	public function generateStorageObject(Persistent $obj){}

	public function generateRelationObject(Relationship $obj){}

	public function listByRelation(Relation $rel){}
	public function listByObject(Persistent $obj){}

	private $_handler;

};

?>