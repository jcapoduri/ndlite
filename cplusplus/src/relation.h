#ifndef RELATION_H
#define RELATION_H

#include "ndlite_global.h"
#include <QObject>
#include <QJsonValue>

namespace nd {

class NDLITESHARED_EXPORT relation : public QObject
{
public:
    relation(QJsonValue & initdata, QObject * parent = 0);

private:
    QJsonValue raw_data;

};

}

#endif // RELATION_H
