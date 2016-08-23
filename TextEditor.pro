#-------------------------------------------------
#
# Project created by QtCreator 2016-08-18T01:08:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TextEditor
TEMPLATE = app


SOURCES +=  src/main.cpp \
    src/MainWindow.cpp \
    src/Text.cpp \
    src/AddTextDialog.cpp \
    src/ChoiceDialog.cpp

HEADERS  += include/MainWindow.hpp \
    include/Text.hpp \
    include/Language.hpp \
    include/AddTextDialog.hpp \
    include/ChoiceDialog.hpp

FORMS    += mainwindow.ui \
    addtextdialog.ui \
    choicedialog.ui
