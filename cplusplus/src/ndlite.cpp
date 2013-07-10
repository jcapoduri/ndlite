#include "ndlite.h"

nd::app* nd::Ndlite::defaultApp = 0;

nd::Ndlite::Ndlite(QObject *parent) : QObject(parent)
{
}

/*template <class T = nd::app>
nd::Ndlite::startApp( QJsonDocument &doc, QObject parent)
{
    if (doc.isNull()) return 0;
    new T(doc.object(), parent);
}*/
