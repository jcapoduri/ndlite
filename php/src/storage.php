<?php

/**
* Neodymium Lite
* 2013
*
* minimalistic ORM library
*/

namespace nd;

include 'StorageEngine/mysqlengine.php';

abstract class StorageEngine {
	public function __construct($data) {
		$this->_raw = $data;
	}
	public abstract function init();

	public abstract function commit(Persistent $obj);
	public abstract function update(Persistent $obj);
	public abstract function erase(Persistent $obj);
	public abstract function unerase(Persistent $obj);
	public abstract function touch(Persistent $obj);

	public abstract function commitRelation(Relation $rel);
	public abstract function updateRelation(Relation $rel);
	
	public abstract function listByRelation(Relation $rel);
	public abstract function listByObject(Persistent $obj);

	public function beginTransaction() {}
	public function commitTransaction() {}
	public function rollbackTransaction() {}

	public abstract function generateStorageObject(Persistent $obj);
	public abstract function generateRelationObject(Relationship $obj);


	private $_raw;
};

?>