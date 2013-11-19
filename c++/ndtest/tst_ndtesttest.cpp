#include <QString>
#include <QtTest>
#include <QJsonDocument>
#include <QDebug>
#include <QEventLoop>
#include "../src/solution.h"
#include "../src/app.h"
#include "../src/protoobject.h"

class NdtestTest : public QObject
{
    Q_OBJECT

public:
    NdtestTest();

private Q_SLOTS:
    void initTestCase();

private:
    nd::solution*   solution;
    nd::app*        app;

};

NdtestTest::NdtestTest()
{
    solution = 0;
    app = 0;
}

void NdtestTest::initTestCase()
{
    QJsonDocument doc;
    QFile file("./bluesystem.json");
    qDebug() << file.open(QIODevice::ReadOnly);
    QByteArray json_data = file.readAll();
    doc = QJsonDocument::fromJson(json_data);
    QJsonValue value(doc.object());

    // generate solution
    solution = new nd::solution(value);
    // start an application and set up enviroment
    app = solution->startApp("pc");
    qDebug() << "app result:" << app;

    nd::model* book = nd::app::model("book")->create();
    qDebug() << "model result: " << book;
    qDebug() << "json from model" << book->toJSON();
}

QTEST_APPLESS_MAIN(NdtestTest)

#include "tst_ndtesttest.moc"
