<?php

namespace nd;

// To Do
class Relation extends Persistent{
	public function __construct($data, Persistent $father){
		$this->name = $data["name"];
		$this->tablename = $data["tablename"];
		$this->nd_fields = $data["nd_fields"];
		switch ($data["type"]) {
			case "1-to-many":
				$this->type = 1;
				break;
			case "many-to-1":
				$this->type = 2;
				break;
			default:
				$this->type = 3;
				break;
		}
		$this->father_name = $data["object_from"]; 
		$this->son_name = $data["object_to"];
		$this->father = $father;
		$this->sons = array();
		//load fields: TODO
		$obj1 = NdLite::get($this->father_name);
		$obj2 = NdLite::get($this->son_name);
		array_merge($this->fields, $obj1->keys());
		array_merge($this->fields, $obj2->keys());
		/*$len = count($this->fields);
		while($len--){
			$this->fields
		};*/
	}

	public function link(Persistent $obj){

	}

	public function unlink(Persistent $obj){

	}

	public function one(){}

	public function all(){}

	public function first(){}

	public function last(){}

	public function next(){}

	private $name;
	private $father_name;
	private $son_name;
	private $father;
	private $sons;
	private $linked_items;
	private $fields;

	private $current;
};

/*
{
	"name" : "inner_name", //required
	"tablename": "name insdide table", //optional
	"nd_fields": false, //optional, include base neodymium fields
	"type": "many-to-many", // values [1-to-many, many-to-1, many-to-many]
	"object_from": "object_name",
	"object_to": "object_name"	
}
*/

?>
