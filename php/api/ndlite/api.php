<?php

namespace nd;

class api {
	public function __construct() {
		$mapping = [];
	}

	public function addMap($name, $mapto) {
		$this->mapping[$name] = $mapto;
	}
	public function delMap($name) {
		unset($this->mapping[$name]);
	}

	protected $mapping;
};

?>