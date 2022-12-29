QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    sources/main.cpp \
    sources/mainmenu.cpp \
    sources/mainwindow.cpp \
    sources/namespaces.cpp \
    sources/utils.cpp \


HEADERS += \
    headers/helpers.hpp \
    headers/mainmenu.hpp \
    headers/mainwindow.hpp \
    headers/main_menu_helpers.hpp \
    headers/predefined_classes.hpp \
    headers/utils.hpp \



INCLUDEPATH += \
    headers/ \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    res.qrc
