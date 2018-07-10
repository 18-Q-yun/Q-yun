#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "client.h"
#include "request.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<Client>("Client", 1, 0, "Client");
    qmlRegisterType<Request>("Request", 1, 0, "Request");
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
