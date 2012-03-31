TEMPLATE = app
TARGET = world_sync_metronome
QT += core \
    gui
HEADERS += VisMetro.h \
    WorldSyncMetronome.h
SOURCES += VisMetro.cpp \
    WorldSyncMetronome.cpp \
    main.cpp
FORMS += WorldSyncMetronome.ui
RESOURCES += 
win32 {
	QMAKE_LFLAGS += -static-libgcc
}