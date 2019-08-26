#-------------------------------------------------
#
# Project created by QtCreator 2019-08-21T16:44:25
#
#-------------------------------------------------

QT       += core gui androidextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = USB_Example
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    android/src/org/usbexample/ftdi/MyClass.java \
    android/libs/j2xx.jar \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/libs/j2xx.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/res/xml/device_filter.xml \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/build.gradle \
    android/gradlew.bat \
    android/src/org/qtproject/usbexample/MyFTDIClass.java

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
