QT += quick sql

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    JHAccountManager.cpp \
    JHSMApi.cpp \
    JHStudentListModel.cpp \
    main.cpp
include($$PWD/../../Basic/Framework/Framework.pri)
include($$PWD/../../Basic/AppData/AppData.pri)
include($$PWD/../../Basic/JHApi/JHApi.pri)
include($$PWD/JHSqlite/JHSqlite.pri)
include($$PWD/../../Basic/JHDataModel/JHDataModel.pri)
RESOURCES += qml.qrc \
    ../../Basic/JHQmlApp/main/main.qrc

INCLUDEPATH += $$PWD/../../Basic/
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH +=  $$PWD/release
QML_IMPORT_PATH +=  $$PWD/debug

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    install.bat \
    installd.bat

HEADERS += \
    JHAccountManager.h \
    JHSMApi.h \
    JHStudentListModel.h

msvc{
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS+= /utf-8
}
