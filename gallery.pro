QT += declarative

TARGET = gallery

SOURCES += main.cpp \
    wmain.cpp \
    image.cpp

OTHER_FILES += \
    qml/main.qml \
    qml/ImageViewer.qml \
    qml/TopBar.qml \
    qml/BottomBar.qml \
    qml/BackButton.qml

RESOURCES += \
    resources.qrc

HEADERS += \
    wmain.h \
    image.h
