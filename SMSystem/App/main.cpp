#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QDebug>
#include "Framework/Framework.h"
#include "Framework/framelesswindow.h"
#include "AppData/JHAppData.h"
#include "JHSqlite/JHDatabaseModule.h"
#include <QQmlContext>
#include <JHSMApi.h>
#include <QTextCodec>
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);


    Framework frame;
    frame.addModule(new JHDatabaseModule);
    frame.initialize();

    JHSMApi SMApi;
    SMApi.initialize();

    qmlRegisterType<FramelessWindow>("an.window", 1, 0, "FramelessWindow");
    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("JHApp",&frame);
    engine.rootContext()->setContextProperty("SMApi",&SMApi);
    engine.addImportPath(app.applicationDirPath() + "/JHPlugin");
    engine.addImportPath(app.applicationDirPath());

    const QUrl url(QStringLiteral("qrc:/main/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
