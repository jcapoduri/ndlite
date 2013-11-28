#include "storage.h"

nd::storage::storage(QJsonValue &initdata, app *application, QObject *parent) : QObject(parent)
{
    raw_data = initdata;
    _app = application;
}
