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

	public abstract function commit(Object $obj);
	public abstract function update(Object $obj);
	public abstract function erase(Object $obj);
	public abstract function unerase(Object $obj);
	public abstract function touch(Object $obj);

	public abstract function commitRelation(Relationship $rel);
	public abstract function updateRelation(Relationship $rel);
	
	public abstract function listByRelation(Relationship $rel);
	public abstract function listByObject(Object $obj);

	public abstract function storeValue(Field $field);

	public function beginTransaction() {}
	public function commitTransaction() {}
	public function rollbackTransaction() {}

	public abstract function generateStorageObject(Object $obj);
	public abstract function generateRelationObject(Relationship $obj);


	private $_raw;
};

?>