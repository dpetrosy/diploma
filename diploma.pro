QT       += core gui
QT       += multimedia
QT       += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    sources/clickablelabel.cpp \
    sources/main.cpp \
    sources/mainwindow.cpp \
    sources/menus_sources/algo_menu.cpp \
    sources/menus_sources/tree_menu.cpp \
    sources/namespaces.cpp \
    sources/utils.cpp \
    sources/menus_sources/mainmenu.cpp \


HEADERS += \
    headers/clickablelabel.hpp \
    headers/helpers.hpp \
    headers/mainmenu.hpp \
    headers/mainwindow.hpp \
    headers/menus_headers/algo_menu.hpp \
    headers/menus_headers/tree_menu.hpp \
    headers/predefined_classes.hpp \
    headers/utils.hpp \
    headers/menus_headers/mainmenu.hpp \


INCLUDEPATH += \
    headers/ \
    headers/menus_headers/ \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    res.qrc
