
QT       += core  widgets
#QT += gui
QT += network
#Qt += #Qapplication



CONFIG   += console

TARGET = BtModul
TEMPLATE = app


include(src/qextserialport.pri)

SOURCES += main.cpp\
    nxtclass.cpp \
    filework.cpp \
    qsocket.cpp \
    Transfer.cpp \
    mainwindow.cpp

HEADERS += nxtclass.h \
    filework.h \
    qsocket.h \
    Transfer.h \
    mainwindow.h

FORMS   +=   mainwindow.ui


win32:{
#INCLUDEPATH += $$PWD/win_src
DEPENDPATH += $$PWD/win_src
INCLUDEPATH += $$PWD/win_src
HEADERS += win_src/BtPCModul.h
SOURCES += win_src/BtPCModul.cpp
LIBS+= -L.\ -lBthprops #BTmodul
LIBS+= -L.\ -lOleaut32#BTmodul
HEADERS += win_src/SearchCom.h
LIBS += -L$$PWD/win_src/ -lSearchCom
}


