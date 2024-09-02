#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "templatelistcontrol.h"

int main( int argc, char* argv[] ) {
    QGuiApplication app( argc, argv );

    qmlRegisterType<TemplateListControl>( "TemplateListControl", 1, 0, "TemplateListControl" );

    QQmlApplicationEngine engine;
    engine.load( QUrl( QStringLiteral( "qrc:/main.qml" ) ) );


    return app.exec();
}
