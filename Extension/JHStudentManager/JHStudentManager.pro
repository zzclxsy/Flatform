TEMPLATE = lib
TARGET = JHStudentManager
QT += qml quick
CONFIG += plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = JHStudentManager

# Input
SOURCES += \
        JHStudentManagerPlugin.cpp \
        JHStudentManager.cpp

HEADERS += \
        JHStudentManagerPlugin.h \
        JHStudentManager.h

DISTFILES = qmldir \
    Config.json \
    install.bat \
    installd.bat

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) "$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)" "$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}

RESOURCES += \
    JHStudentManager.qrc

msvc{
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}
