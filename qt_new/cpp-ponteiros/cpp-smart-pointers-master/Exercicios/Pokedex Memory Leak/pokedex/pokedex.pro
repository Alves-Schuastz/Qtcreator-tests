QT += quick concurrent qml

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        controller/pokemoncontroller.cpp \
        converter/pokemonconverter.cpp \
        main.cpp \
        model/pokemonspritemodel.cpp \
        model/pokemonmodel.cpp \
        network/endpoint/pokemonendpoint.cpp \
        network/response/pokemonreferenceresponse.cpp \
        network/response/pokemonresponse.cpp \
        network/response/pokemonspriteresponse.cpp \
        utils/retrytask.cpp \
        utils/synctask.cpp \
        view/pokemonabstractmodel.cpp

HEADERS += \
        controller/pokemoncontroller.h \
        converter/pokemonconverter.h \
        model/pokemonspritemodel.h \
        model/pokemonmodel.h \
        network/endpoint/pokemonendpoint.h \
        network/response/pokemonreferenceresponse.h \
        network/response/pokemonresponse.h \
        network/response/pokemonspriteresponse.h \
        utils/retrytask.h \
        utils/synctask.h \
        view/pokemonabstractmodel.h

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = $$PWD/components

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

CONFIG( debug, debug|release ) {
    DESTDIR = build/debug
}

CONFIG( release, debug|release ) {
    DESTDIR = build/release
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.u

BASE_PATH = $$PWD/..

INCLUDEPATH += $$BASE_PATH

LIBRARY_DEPENDENCIES = \
    HTTP-REQUEST

unix {
    target.path = /usr/bin
    INSTALLS += target
}

contains( LIBRARY_DEPENDENCIES, HTTP-REQUEST ) {

    message( "HTTP_REQUEST dependencie including...")

    HTTP_REQUEST_DIR = $$BASE_PATH/http-request

    INCLUDEPATH += $$BASE_PATH/http-request

    LIBS += -L$$HTTP_REQUEST_DIR/$$DESTDIR -lhttp-request

    unix {
        QMAKE_RPATHDIR += $$HTTP_REQUEST_DIR/$$DESTDIR
    }

}
