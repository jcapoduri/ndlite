<?php

namespace nd;

// To Do
class Relation extends Persistent{
	public function __construct($data, Persistent $father){		
		parent::__construct($data);
		//load fields: TODO
		$obj1 = NdLite::get($data["object_from"]);
		$obj2 = NdLite::get($data["object_to"]);
		array_merge($this->fields, $obj1->keys());
		array_merge($this->fields, $obj2->keys());		
	}

//	private $obj
};

class Relationship {
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
		
		//load fields: TODO
		$this->father_name = $data["object_from"];
		$this->son_name = $data["object_to"];		
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

?>
