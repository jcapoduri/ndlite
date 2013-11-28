#ifndef API_H
#define API_H

#include <QObject>
#include "ajax.h"
#include <QJsonObject>
#include <QJsonValue>
#include <QMap>

namespace nd {

class NDLITESHARED_EXPORT protoObject;

class NDLITESHARED_EXPORT api : public QObject
{
    Q_OBJECT
public:
    explicit api(QString baseurl, QObject *parent = 0);
    api(const api & other);
    ~api();

    void    addMap(const QString name, const QString route);
    void    delMap(const QString name);
    ajax*   xhr() { return jqXhr; }

signals:
    
public slots:
    bool        save(protoObject * obj);
    bool        save(const  QString & objname, const QJsonObject & obj);

    QJsonValue  get(const QString & objname, int id = 0);
    void        get(protoObject * obj);
    QJsonValue  get(const QString & objname, const QString & route);

    bool        erase(protoObject * obj);
    bool        erase(const QString & objname, int id);
    bool        erase(const QString & objname, const QJsonObject & obj);

protected:
    ajax    *jqXhr;
    QMap<QString, QString> routeMap;
};

}

#endif // API_H
