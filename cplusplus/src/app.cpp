#include "app.h"
#include "storageEngines/apistorage.h"

nd::app::app(QJsonValue &initdata, QObject *parent) :
    QObject(parent)
{
    QJsonObject tmp_obj;
    _raw_data = initdata;
    if (initdata.isObject()){
        tmp_obj = initdata.toObject();
        if (tmp_obj.contains("config")) _config = tmp_obj.value("config");
        if (tmp_obj.contains("meta")) _meta = tmp_obj.value("meta");
        if (tmp_obj.contains("objects")) _objects = tmp_obj.value("objects");
        if (tmp_obj.contains("relations")) _relations = tmp_obj.value("relations");
        if (tmp_obj.contains("storages")) _storages = tmp_obj.value("storage");
    };

    init();
    //_storage = new apiStorage(initdata., this);
}

nd::app::~app()
{
    // clean the memory
}

void nd::app::init()
{
    QJsonArray      tmp_arr;
    QJsonValue      tmp_val;
    QJsonObject     tmp_obj;
    uint            len, i;

    //check each object and add a objects into the map
    tmp_arr = _objects.toArray();
    len = tmp_arr.count();
    for (i = 0; i < len; i++) {
        tmp_obj = tmp_arr.at(i).toObject();
        _objectsMap.insert(tmp_obj.value("name").toString(), tmp_obj);
    };

    //check each object and add a relation into the map
    tmp_arr = _relations.toArray();
    len = tmp_arr.count();
    for (i = 0; i < len; i++) {
        tmp_obj = tmp_arr.at(i).toObject();
        _relationsMap.insert(tmp_obj.value("name").toString(), tmp_obj);
    };

    //check for storage and start it
    tmp_val = _storages.toArray().at(0);
    //tmp_obj = tmp_val.toObject();
    _storage = new apiStorage(tmp_val, this);

}
