<?php

namespace nd;

class App {
	function __construct($json) {
		$this->raw_data = $json
	}

	private function init() {
		$this->storage = Nd::getStorage($raw_data["storage"][0]);
	}

	//raw data passed in the constructor
	private $raw_data;
	//map of storages
	private $storage;
	//map of objects
	private $objects;
	//map of object relations
	private $relations;
};

?>