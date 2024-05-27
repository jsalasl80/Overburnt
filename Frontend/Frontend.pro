QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    overburnt.cpp \
    simulationmenu.cpp \
    simulationover.cpp \
    tastiestrestaurant.cpp

HEADERS += \
    overburnt.h \
    simulationmenu.h \
    simulationover.h \
    tastiestrestaurant.h

FORMS += \
    overburnt.ui \
    simulationmenu.ui \
    simulationover.ui \
    tastiestrestaurant.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Images/ButtonMenu.png \
    Images/ChopsticksMenu.png \
    Images/FoodMenu.png \
    Images/LogoRestaurant.png \
    Images/TitleMenu.png

RESOURCES += \
    images.qrc
