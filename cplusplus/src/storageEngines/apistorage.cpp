#include "apistorage.h"

nd::apiStorage::apiStorage(QJsonValue &initdata, QObject *parent) :
    storage(initdata, parent)
{
    accessMgr = new QNetworkAccessManager(this);
    url = initdata.toObject().value("base_uri").toString();
    raw_data = initdata;
}

bool nd::apiStorage::commit(nd::object &obj)
{

}

bool nd::apiStorage::update(nd::object &obj)
{
}

bool nd::apiStorage::erase(nd::object &obj)
{
}

bool nd::apiStorage::unerase(nd::object &obj)
{
}

bool nd::apiStorage::touch(nd::object &obj)
{
}

bool nd::apiStorage::commit(nd::relation &rel)
{
}

bool nd::apiStorage::update(nd::relation &rel)
{
}
