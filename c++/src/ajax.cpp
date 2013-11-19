#include "ajax.h"
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QEventLoop>
#include <QHttpMultiPart>

nd::ajax::ajax(QUrl baseUri, QObject *parent) :
    QObject(parent),
    thread(new QThread(this))
{
    accessMgr = new QNetworkAccessManager(this);    
    url = baseUri;
    moveToThread(thread);
    thread->start(QThread::HighestPriority);
}

nd::ajax::ajax(const nd::ajax &other) :
    thread(new QThread(this))
{
    accessMgr = new QNetworkAccessManager(this);
    url = other.url;
    moveToThread(thread);
    thread->start(QThread::HighestPriority);
}

nd::ajax::~ajax()
{
}

QJsonValue nd::ajax::get(QString url, quint16 id)
{
    QNetworkReply*  reply;
    QJsonValue      value;
    QString         uri = url;
    QJsonDocument   doc;

    if (id != 0) uri.append(QString("/%1").arg(id));
    qDebug() << "GET!" << uri;

    reply = this->accessMgr->get(QNetworkRequest(QUrl(this->url.toString() + uri)));
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SIGNAL(progress(qint64,qint64)));
    emit requestStart(reply);

    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()), Qt::QueuedConnection);
    loop.exec();
    emit requestEnd(reply);
    this->last_error = reply->error();
    this->last_request = reply->readAll();

    doc = QJsonDocument::fromJson(this->last_request);
    qDebug() << "last error: " << this->last_error;
    if (doc.isArray())  value = doc.array();
    if (doc.isObject()) value = doc.object();
    reply->deleteLater();

    return value;
}

quint16 nd::ajax::post(QString url, QJsonObject &val)
{
    QNetworkReply*  reply;
    QString         tmp_val;
    QString         uri = url;
    QJsonDocument   doc(val);
    bool            ok = true;
    quint16         returnValue = 0;

    reply = this->accessMgr->post(QNetworkRequest(QUrl(this->url.toString() + uri)), doc.toJson());
    connect(reply, SIGNAL(uploadProgress(qint64,qint64)), this, SIGNAL(progress(qint64,qint64)));
    emit requestStart(reply);
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    emit requestEnd(reply);
    this->last_error = reply->error();
    this->last_request = reply->readAll();    
    qDebug() << "last error: " << this->last_error;
    tmp_val = this->last_request;
    returnValue = tmp_val.toInt(&ok);
    reply->deleteLater();
    if (!ok) return 0;
    return returnValue;
}

bool nd::ajax::put(QString url, quint16 id, QJsonObject &val)
{
    QNetworkReply*  reply;
    QString         tmp_val;
    QString         uri = url;
    QJsonDocument   doc(val);
    bool            ok = true;
    quint16         returnValue = 0;


    uri.append(QString("/%1").arg(id));

    qDebug() << "PUT!" << uri;
    QNetworkRequest* req = new QNetworkRequest(QUrl(this->url.toString() + uri));
    req->setRawHeader("X-HTTP-Method-Override", "PUT");
    reply = this->accessMgr->post(*req, doc.toJson());
    //reply = this->accessMgr->put(*req, doc.toJson());
    connect(reply, SIGNAL(uploadProgress(qint64,qint64)), this, SIGNAL(progress(qint64,qint64)));
    emit requestStart(reply);
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    emit requestEnd(reply);
    this->last_error = reply->error();
    this->last_request = reply->readAll();
    qDebug() << "last error: " << this->last_error;
    qDebug() << "last request" << this->last_request;
    doc = QJsonDocument::fromJson(this->last_request);
    tmp_val = this->last_request;

    returnValue = tmp_val.toInt(&ok);
    reply->deleteLater();
    delete req;
    if (!ok) return 0;
    return returnValue;
}

bool nd::ajax::deleteObj(QString url, quint16 id)
{
    QNetworkReply*  reply;
    QString         uri = url;
    uri.append(QString("/%1").arg(id));

    reply = this->accessMgr->deleteResource(QNetworkRequest(QUrl(uri)));
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    emit requestStart(reply);
    reply->waitForReadyRead(0);
    emit requestEnd(reply);
    this->last_error = reply->error();
    this->last_request = reply->readAll();
    reply->deleteLater();
    return (this->last_error == QNetworkReply::NoError);
}

QByteArray nd::ajax::request(QString type, QString uri, QByteArray data)
{
    QNetworkReply*  reply;
    QString         url;
    bool            ok = false;

    url = this->url.toString() + uri;

    if (type.toLower() == "get") {
        qDebug() << "get!";
        reply = this->accessMgr->get(QNetworkRequest(QUrl(url)));
        ok = true;
    };

    if (type.toLower() == "post") {
        qDebug() << "POST!";
        reply = this->accessMgr->post(QNetworkRequest(QUrl(url)), data);
        ok = true;
    };

    if (type.toLower() == "put") {
        qDebug() << "put!";
        reply = this->accessMgr->put(QNetworkRequest(QUrl(url)), data);
        ok = true;
    };

    if (type.toLower() == "delete") {
        qDebug() << "delle ette!";
        reply = this->accessMgr->deleteResource(QNetworkRequest(QUrl(url)));
        ok = true;
    };

    if (!ok) {
        this->last_request = QByteArray();
        this->last_error = QNetworkReply::ProtocolUnknownError;
        return this->last_request;
    };

    qDebug() << "request! "  << type << " uri: " << uri << " data: " << data;

    connect(reply, SIGNAL(uploadProgress(qint64,qint64)), this, SIGNAL(progress(qint64,qint64)));
    emit requestStart(reply);

    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    emit requestEnd(reply);
    this->last_error = reply->error();
    this->last_request = reply->readAll();
    reply->deleteLater();
    qDebug() << "request ended: " << this->last_request;

    return this->last_request;
}

QByteArray nd::ajax::request(QString type, QString uri, QJsonObject &data)
{
    return this->request(type, uri, QJsonDocument(data).toJson());
}

QByteArray nd::ajax::request(QString type, QString uri, QJsonArray &data)
{
    return this->request(type, uri, QJsonDocument(data).toJson());
}

QByteArray nd::ajax::request(QString type, QString uri, QJsonValue &data)
{
    if (data.isArray()){
        QJsonArray tmp_arr = data.toArray();
        return this->request(type, uri, tmp_arr);
    };
    if (data.isObject()){
        QJsonObject tmp_obj = data.toObject();
        return this->request(type, uri, tmp_obj);
    };
    return this->request(type, uri, data.toVariant().toByteArray());
}

QByteArray nd::ajax::lastResponse()
{
    return this->last_request;
}
