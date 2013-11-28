{
	"meta": {},
	"config": {
		"version": "0.1.1",
		"system_name": "bluesystem"
	},
	"objects": [
		{
			"name": "business",
			"nd_fields": true,
			"fields": [
				{
					"name": "name",
					"type": "string"
				},
				{
					"name": "ownername",
					"type": "string"
				},
				{
					"name": "folder",
					"type": "array",
					"relation_name": "relBusinsessBooks"
				},
			]
		},
		{
			"name": "book",
			"tablename": "books",
			"nd_fields": true,
			"fields": [
				{
					"name": "name",
					"type": "string"
				},
				{
					"name": "description",
					"type": "string"
				},
				{
					"name": "folder",
					"type": "array",
					"relation_name": "books"
				},
			]
		}
	],
	"relations": [
		{
			"name": "reBusinessBooks",
			"object_from": "business",
			"object_to": "book"
		}
	],
	"storage": {
		"name": "mysql",
		"type": "database", // ["database", "local", "external", "mongodb"]
		"db_host": "localhost",
		"db_name": "fotocasi_bluesystem",
		"db_user": "fotocasi_user",
		"db_pass": "lokithor",
		"db_port": 3061,
		"db_type": "mysql"
	}
}