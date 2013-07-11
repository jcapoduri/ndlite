#ifndef RELATION_H
#define RELATION_H

#include "ndlite_global.h"
#include <QObject>
#include <QJsonValue>
#include <QList>

namespace nd {

class NDLITESHARED_EXPORT relation : public object
{
public:
    relation(QJsonValue & initdata, QObject * parent = 0);

private:
    QJsonValue raw_data;

};

class NDLITESHARED_EXPORT relationship : public QObject {
	Q_OBJECT
public:
	relationship(QJsonValue & initdata, QObject * parent = 0);

	/*public function __construct($data, Persistent $father){		
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
	}*/

	bool			link(object & obj);
	bool			unlink(object & obj);
	object 			one();
	QList<object> 	all();
	object 			first();
	object 			last();
	object 			next();

	

private:
	void			init();
	
	QList<relation> _relationList;
	QJsonValue		_raw_data;
	QString			_name;
	QString			_father_name;
	QString			_son_name;
	uint			_index;

	/*private $name;
	private $father_name;
	private $son_name;
	private $father;
	private $sons;
	private $linked_items;
	private $fields;

	private $current;*/

};

#endif // RELATION_H
