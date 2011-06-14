#ifndef WORLD_SYNC_METRONOME_H
#define WORLD_SYNC_METRONOME_H

#include <QtGui/QDialog>
#include "ui_WorldSyncMetronome.h"

class WorldSyncMetronome : public QDialog
{
    Q_OBJECT

public:
    WorldSyncMetronome(QWidget *parent = 0);
    ~WorldSyncMetronome();

    int	meter;
    int bpm;
    QTime anchor;
    QString old_stime;
    bool sound;

private slots:
	void time_update();
    void on_meter_spinbox_valueChanged(int);
    void on_bpm_spinbox_valueChanged(int);
    void on_anchor_timeEdit_timeChanged(QTime);
    void on_sound_checkBox_stateChanged(int);

private:
    Ui::WorldSyncMetronomeClass ui;
};

#endif // WORLD_SYNC_METRONOME_H
