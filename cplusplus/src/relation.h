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


private:
	QList<relation> _relationList;
	QJsonValue		_raw_data;
};

#endif // RELATION_H
