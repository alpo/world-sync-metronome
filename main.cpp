#include "WorldSyncMetronome.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WorldSyncMetronome w;
    w.show();
    return a.exec();
}
