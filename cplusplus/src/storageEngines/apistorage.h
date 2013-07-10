#ifndef APISTORAGE_H
#define APISTORAGE_H

#include "../storage.h"
#include <QNetworkAccessManager>

namespace nd {

class apiStorage : public storage
{
    Q_OBJECT
public:
    explicit apiStorage(QJsonValue &initdata, QObject *parent = 0);
    bool commit(nd::object & obj);
    bool update(nd::object & obj);
    bool erase(nd::object & obj);
    bool unerase(nd::object & obj);
    bool touch(nd::object & obj);

    bool commit(nd::relation & rel);
    bool update(nd::relation & rel);
    
signals:
    
public slots:

private:
    QJsonValue              raw_data;
    QNetworkAccessManager*  accessMgr;
    QString                 url;
};

}
#endif // APISTORAGE_H
