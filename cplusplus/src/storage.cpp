#include "storage.h"

nd::storage::storage(QJsonValue &initdata, QObject *parent) : QObject(parent)
{
    raw_data = initdata;
}
