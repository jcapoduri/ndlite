<?php

namespace nd;

require 'object.php';
require 'relationship.php';
require 'storage.php';

class Nd {

	public static function start($json) {
		if (!Nd::$instance) Nd::$instance = new Nd($json);

	}

	public static function getApp($appname) {
		if (!Nd::$instance) return false;
		if(!isset(Nd::$instance->apps[$appname])) {
			Nd::$instance->$default_app = Nd::$instance->apps[$appname];
			return Nd::$instance->$default_app;
		} else return false;
	}

	public static function getStorage($storagename) {
		if (!Nd::$instance) return false;
		if(!isset(Nd::$instance->storages[$storagename])) {
			return Nd::$instance->storages[$storagename];
		} else return false;
	}

	public static function getObject($objectname) {
		if (!Nd::$instance) return false;
		if(!isset(Nd::$instance->objects[$objectname])) {
			return Nd::$instance->objects[$objectname];
		} else return false;
	}

	public static function getRelation($relationame) {
		if (!Nd::$instance) return false;
		if(!isset(Nd::$instance->relations[$relationame])) {
			return Nd::$instance->relations[$relationame];
		} else return false;
	}

	public static function get($item, $itemname, $init_value) {
		switch ($item) {
			case 'app':
				return Nd::$instance->apps[$itemname];
				break;
			case 'object':
				return new Nd::$instance->objects[$itemname];
			case 'storage':
				return new Nd::$instance->storages[$itemname];
			case 'relation':
				return new Nd::$instance->relations[$itemname];
			default:
				return null;
				break;
		}
	}

	public static function app() {
		return Nd::$instance->$default_app;
	}

	private function __construct($json) {
		$this->raw_data = $json;

		$this->init();
	}

	private function init() {
		$temp_val = null;
		$i = 0;
		$json_arr = $this->raw_data["objects"];
		$len = count($json_arr);

		for ($i = 0; $i < $len; $i++) {
			$temp_val = $json_arr[$i];
			$this->objects[$temp_val["name"]] = new Object($temp_val);
		};
	}

	private $raw_data;

	private $apps;
	private $objects;
	private $relations;
	private $storages;
	private $default_app;

	private static $instance = null;
}

?>