<?php

namespace nd;


modelFieldDefinition field;
    QString type = def.value("type").toString().toLower();
    QString name = def.value("name").toString();

    if (type == "object" || type == "array") {
        if (type == "object") {
            //obj->setProperty(name.toLatin1(), QVariant::fromValue((new protoObject(this))));
            field.type = object;
            field.objectName = def.value("object_name").toString();            
        } else {
            //qDebug() << "is array";
            field.type = array;
            field.objectName = def.value("relation_name").toString();
            //qDebug() << field.objectName;
            QJsonObject rel_info = this->application()->getDefinition(app::relation, field.objectName);
            //qDebug() << rel_info;
            field.objectName = rel_info.value("object_to").toString();
            //qDebug() << name << field.type << field.objectName;
        };
    } else {
        //obj->setProperty(name.toLatin1(), QVariant(field.value("default")));
        if (type == "string") field.type = string;
        if (type == "decimal") field.type = decimal;
        if (type == "number") field.type = number;
        if (type == "enum") field.type = enumeration;
        if (type == "date") field.type = date;
        if (type == "time") field.type = time;
        if (type == "datetime") field.type = datetime;
        if (type == "bool") field.type = boolean;
    };
    field.name = name;
    return field;

class modelFieldDefinition {
	public $name;
    public $type;
    public $objectName = "";
    public $enum_values = [];

    public function  __construct($json) {
    	$type = $json["type"];
    	$name = $json["name"];
    	if ($type == 'object' || $type == 'array') {
    		if ($type == 'object') {
    			$this->objectName = $json["object_name"];
    		} else {
    			$this->objectName = $json["relation_name"];
    			$this->objectName = $this->objectName[""];
    			$this->objectName
    		};
    	};

    	$this->type = $type;
    };
};

class modelDefinition {
	/*public class fieldType {
this->_application = appllication;
    if (this->parent() == 0) setParent(appllication);
    this->modelName = modelname;
    QJsonArray fields_array = definition.value("fields").toArray();
    int i = 0, len = fields_array.count();
    for(; i < len; i++) {
        QJsonObject field_def = fields_array.at(i).toObject();
        fields.insert(field_def.value("name").toString(), createFieldDefinition(field_def));
    };

    if (definition.value("nd_fields").toBool()) {
        fields_array = nd::nd_fields;
        i = 0, len = fields_array.count();
        for(; i < len; i++) {
            QJsonObject field_def = fields_array.at(i).toObject();
            fields.insert(field_def.value("name").toString(), createFieldDefinition(field_def));
        };
    };	}*/

	public function __construct($name, $json, app $app) {
		$this->app = $app;
		$this->name = $name;
		$fields_array = $json["fields"];
		$len = count($fields_array);
		for($i = 0; $i < $len; $i++) {
			$item = $fields_array[$i];
			$fields[$item["name"]] = new modelFieldDefinition($item);
		};

		if ($json["nd_fields"]) {

		};
	}

	public function create($json) {}  //TODO

	public function field($name) { return $fields[$name]; }

	public function isValid() { return $this->valid; }
	public function name() { return $this->name; }
	public function fieldNames() { return array_keys($fields); }
	public function application() { return $app; } 

	protected $fields;
	protected $raw;
	protected $name;
	protected $nd_fields = false;
	protected $valid = true;
	protected $app;
};

?>
