QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    login.cpp \
    loginfield.cpp \
    main.cpp \
    staticcodeanalyzer.cpp

HEADERS += \
    login.h \
    loginfield.h \
    staticcodeanalyzer.h

FORMS += \
    login.ui \
    loginfield.ui \
    staticcodeanalyzer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    CapstoneProject480.pro.user \
    CapstoneProject480.pro.user.d50ad73 \
    loginfield.txt
