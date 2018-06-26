#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "database.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
//    dataBase Da1;
//    Da1.selectLevelDir("123firstDir");
    qmlRegisterType<dataBase>("DataBase",1,0,"DataBase");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    engine.rootContext()->setContextProperty("dataBase",new dataBase(database));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
