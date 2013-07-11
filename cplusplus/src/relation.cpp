#include "relation.h"

nd::relation::relation(QJsonValue &initdata, QObject *parent) : QObject(parent)
{
    raw_data = initdata;
}

nd::relationship::relationship(QJsonValue & initdata, QObject * parent) : QObject(parent) {
	this->_raw_data = initdata;
}

nd::relationship::init(){
	
}