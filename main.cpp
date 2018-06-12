#include <QApplication>
#include <VPApplication>
#include "database.h"
#include <QQmlApplicationEngine>
#include <iostream>
#include <QtQml>
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>
#include <QDebug>
#include <QSqlError>
using std::cin;
using std::cout;
using std::endl;

int main(int argc,char *argv[])
{
    QApplication app(argc, argv);
    VPApplication vplay;
    // Use platform-specific fonts instead of V-Play's default font
    vplay.setPreservePlatformFonts(true);
    QSqlDatabase database;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("DataBase",new dataBase(database));

    vplay.initialize(&engine);
    vplay.setMainQmlFileName(QStringLiteral("qml/Main.qml"));

    engine.load(QUrl(vplay.mainQmlFileName()));

    return app.exec();
}
