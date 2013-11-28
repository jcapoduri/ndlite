#ifndef APISTORAGE_H
#define APISTORAGE_H

#include "../storage.h"
#include <QNetworkAccessManager>
#include <QObject>
#include <QNetworkReply>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

namespace nd {

class ajax : public QObject
{
    Q_OBJECT
public:
    explicit ajax(QJsonValue &initdata, QObject *parent = 0);
    ~ajax();

    QJsonValue  get(QString url, quint16 id = 0);
    quint16     post(QString url, QJsonObject &val);
    bool        put(QString url, quint16 id, QJsonObject &val);
    bool        deleteObj(QString url, quint16 id);
    QByteArray  request(QString type, QString uri, QByteArray data = QByteArray());
    QByteArray  request(QString type, QString uri, QJsonObject & data);
    QByteArray  request(QString type, QString uri, QJsonArray & data);
    QByteArray  request(QString type, QString uri, QJsonValue & data);
    QByteArray  lastResponse();

signals:
    void        requestStart(QNetworkReply* reply);
    void        requestEnd(QNetworkReply* reply);
    void        progress(qint64 prg, qint64 tot);

public slots:


private:
    QJsonValue              raw_data;
    QNetworkAccessManager*  accessMgr;
    QString                 url;
    QByteArray              last_request;
    QNetworkReply::NetworkError last_error;
};


class apiStorage : public storage
{
    Q_OBJECT
public:
    explicit    apiStorage (QJsonValue &initdata, nd::app * application, QObject *parent = 0);
    bool        commit (nd::object & obj);
    bool        update (nd::object & obj, quint16 id);
    bool        erase (nd::object & obj, quint16 id);
    bool        unerase (nd::object & obj, quint16 id);
    bool        touch (nd::object & obj, quint16 id);

    QJsonValue  get (QString url, quint16 id = 0);
    quint16     post (QString url, QJsonObject &val);
    bool        put (QString url, quint16 id, QJsonValue & val);
    bool        deleteObj (QString url, quint16 id);

    bool        commit (nd::relation & rel);
    bool        update (nd::relation & rel);
    
signals:
    
public slots:

private:
    QJsonValue              raw_data;
    //QNetworkAccessManager*  accessMgr;
    ajax                    *jqXHR;
    QString                 url;
};

}
#endif // APISTORAGE_H
