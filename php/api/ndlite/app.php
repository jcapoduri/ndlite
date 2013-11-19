<?php

namespace nd;

class app {

	raw_data = initdata;
    solution = sol;

    //set up storage
    QJsonArray storage = raw_data.toObject().value("storage").toArray();
    QString storage_name = storage.at(0).toString();

    QJsonObject storage_info = solution->getStorageInfo(storage_name);
    define(app::storage, storage_name, storage_info);
    QJsonObject map_info = raw_data.toObject().value("map").toObject();

    // init API
    manager = new nd::api(storage_info.value("url").toString() + storage_info.value("base_uri").toString());

    // load relation
    QStringList keys;
    int i, length;
    keys = solution->allRelations();
    length = keys.count();
    for (i = 0; i < length; i++) {
        define(relation, keys.at(i), solution->getRelationInfo(keys.at(i)));
    };
    length = map_info.count();
    keys = map_info.keys();

    for (i = 0; i < length; i++) {
        QString entity = keys.at(i);
        QJsonObject entity_obj = solution->getObjectInfo(entity);

        manager->addMap(entity, map_info.value(entity).toString());
        define(object, entity, entity_obj);
    };

    nd::app::default_app = this;

    public static function startApp($json) {
    	$app = new app();
    	return $app;
    }

	private function __contruct($json){
		$this->models = [];
		$this->storages = [];
		$this->relations = [];
		//load json

		$storage = $json["storage"][0];
		$mapping = $json["map"];		
		$relations = self::$solution["relations"];

		$this->manager = new api();

		define("storage", $storage, self::$solution["storages"][$storage]);

		$len = count($relations);
		$relations_names = array_keys($relations);

		for ($i = 0; $i < $len; $i++) {
			define("relation", $relations_names[$i], $relations[$i]);
		};

		$len = count($mapping);
		$mapping_names = array_keys($mapping);

		for ($i = 0; $i < $len; $i++) {
			$entity = self::$solution["objects"][];
			$this->manager->addMap();
		};


		self::$default_app = $this;
	}

	public function definition($type, $name, $json){}
	public function getDefinition($type, $name){}

	protected $models;
	protected $storages;
	protected $relations;

	protected $manager;

	protected static $solution;
	protected static $default_app;

	public static function loadSolution($json) {
		self::$solution =  $json;
	}
};

?>