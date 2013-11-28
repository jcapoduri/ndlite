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
				}
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
				}
			]
		}
	],
	"relations": [
		{
			"name": "relBusinessBooks",
			"object_from": "business",
			"object_to": "book"
		}
	],
	"storage": {
		"name": "mysql",
		"type": "database",
		"db_host": "localhost",
		"db_name": "bluesystem",
		"db_user": "root",
		"db_pass": "",
		"db_port": 3061,
		"db_type": "mysql"
	}
}