#include "relation.h"

nd::relation::relation(QJsonValue &initdata, QObject *parent) : QObject(parent)
{
    raw_data = initdata;
}
