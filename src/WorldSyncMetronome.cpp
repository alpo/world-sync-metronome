#include "WorldSyncMetronome.h"

WorldSyncMetronome::WorldSyncMetronome(QWidget *parent) :
	QDialog(parent)
{
	ui.setupUi(this);

	bpm = ui.bpm_spinbox->value();
	meter = ui.meter_spinbox->value();
	anchor = ui.anchor_timeEdit->time();
	sound = ui.sound_checkBox->isChecked();

	QTimer *updateTimer = new QTimer(this);
	connect(updateTimer, SIGNAL(timeout()), this, SLOT(time_update()));
	updateTimer->start(10);
}

WorldSyncMetronome::~WorldSyncMetronome()
{

}

void WorldSyncMetronome::on_bpm_spinbox_valueChanged(int p_bpm)
{
	bpm = p_bpm;
}

void WorldSyncMetronome::on_meter_spinbox_valueChanged(int p_meter)
{
	meter = p_meter;
}

void WorldSyncMetronome::on_anchor_timeEdit_timeChanged(QTime p_anchor)
{
	anchor = p_anchor;
}

void WorldSyncMetronome::on_sound_checkBox_stateChanged(int p_sound)
{
	sound = p_sound;
}

void WorldSyncMetronome::time_update()
{
	QString stime = QDateTime::currentDateTime().toUTC().toString(
			"hh:mm:ss UTC");
	if (stime != old_stime) {
		ui.time_label->setText(stime);
		old_stime = stime;
	}
}
