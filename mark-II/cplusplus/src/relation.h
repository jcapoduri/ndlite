#ifndef RELATION_H
#define RELATION_H

#include "ndlite_global.h"
#include <QObject>
#include <QJsonValue>
#include <QList>
#include "object.h"

namespace nd {

class NDLITESHARED_EXPORT relation : public object
{
    Q_OBJECT
public:
    relation(QJsonValue & initdata, QObject * parent = 0);
    ~relation();

private:

};

}


#endif // RELATION_H
