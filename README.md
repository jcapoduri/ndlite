NdLite
======

Neodimium Lite is a POC of a object-relation mapping (ORM) for PHP, C++ and possible other languages, highly configurable and based in JSON.

The main idea is to design your model in a base JSON file with all the data needed by all the systems based on it and then use the library for each language to start to use it.

The directives are:
* Highly configurable
* non-intrusive with your code
* no other dependency needed
* highly extensible
* cross-plataform / cross-language
* small

The global JSON file to generate the system

	// global config
	{
		"meta": {},
		"config": {},
		"objects": [],
		"relations": [],
		"storage": [],
		"apps": []
	}

the Meta object contain info you want to preserve inside the system or keep in the file

	// meta
	{
		//whatever you want
	}

the Configuration file contain basic info of your system

	//config
	{
		"version": "0.1.1" //version, required
		"system_name": ""  //required
	}

the Objects array contains all the object you want to keep inside your system

	//objects
	{
		"name" : "inner_name", //required
		"tablename": "name insdide table", //optional
		"nd_fields": false, //optional, include base neodymium fields
		"fields": [],
		"inherit": "object_name", //optional, inherit object
		"storages": "" // optional, can be a single storage, multiple in a array or all by default
	}

the field contain the information of an attribute of the object

	//fields
	{
		"isKey": false, // optional, false as default
		"unique": false, // optional, false as default		"autoincremental": false, // optional, false as default
		"name": "value name", //required
		"default": -1, //optional
		"type": "", // ["string", "number", "decimal", "object", "array", "enum", "bool", "date", "time", "timestamp"]
		"enum_values": [], //values for enumeration, only enum type
		"relation_name": "relation", //only for arrays
		"object_name": "object" //only for object type
	}

the relation object contains the information of a relation between two objects

	//relations
	{
		"name" : "inner_name", //required
		"nd_fields": false, //optional, include base neodymium fields
		"type": "many-to-many", // values [1-to-many, many-to-1, many-to-many]
		"cascade": false, //optional, if delete and this is true, all related value are deleted
		"object_from": "object_name",
		"object_to": "object_name"	
	}

the storage array contains storage engines available to persist

	//storages
	{
		"name": "storage_name",
		"type": "", // ["database", "local", "external", "mongodb", "api"]
		"db_host": "",
		"db_name": "",
		"db_user": "",
		"db_pass": "",
		"db_port": 3061,
		"db_type": "", //["mysql", "psql", "litesql", "restapi"],
		"local_folder": "folder_name",
		"base_uri" : "", //only for api, basic url
		"map": {} //map between object/relation name and storage map
	}

the apps

	//apps
	["name"]: {
		"storage": [], // storages used by the app
		"map": {} //map between object/relation -> storage engine
	}
