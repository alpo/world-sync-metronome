#include "VisMetro.h"
#include "WorldSyncMetronome.h"

VisMetro::VisMetro(QWidget *parent) :
	QWidget(parent), beat(0), strong("strong.wav"), weak("weak.wav")
{
	QTimer *updateTimer = new QTimer(this);
	connect(updateTimer, SIGNAL(timeout()), this, SLOT(beat_update()));
	updateTimer->start(10);
}

VisMetro::~VisMetro()
{

}

void VisMetro::beat_update()
{
	WorldSyncMetronome *p = (WorldSyncMetronome *) parentWidget();
	int bpm = p->bpm;
	int meter = p->meter;
	QTime anchor = p->anchor;
	bool sound = p->sound;

	QDateTime current_DT = QDateTime::currentDateTime().toUTC();
	QDateTime anchor_DT = current_DT;
	anchor_DT.setTime(anchor);

	int msecs_to_anchor = anchor_DT.time().msecsTo(current_DT.time());

	/*	QDateTime anchor_DT = QDateTime::currentDateTimeUtc();
	 anchor_DT.setTime(anchor);
	 qint64 msecs_to_anchor = QDateTime::currentMSecsSinceEpoch() -
	 anchor_DT.toMSecsSinceEpoch();*/

	double bpms = bpm / 60000.0;
	double cur_beat_double = msecs_to_anchor * bpms;
	int cur_beat = int(floor(cur_beat_double)) % meter;
	if (cur_beat < 0) {
		cur_beat += meter;
	}

	if (cur_beat != beat) {
		beat = cur_beat;
		if (sound) {
			if (beat) {
				weak.play();
			} else {
				strong.play();
			}
		}
		update();
	}
}

void VisMetro::paintEvent(QPaintEvent * /*event*/)
{
	WorldSyncMetronome *p = (WorldSyncMetronome *) parentWidget();
	int meter = p->meter;
	QTime anchor = p->anchor;

	QPainter painter(this);

	int eheight = beat ? height() / 2 : height();
	int ey = beat ? height() / 2 : 0;

	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
	painter.drawEllipse(width() / meter * beat, ey, width() / meter, eheight);

	int tx = int((beat + 0.5) * width() / meter);
	int ty = beat ? int(0.75 * height()) : height() / 2;

	painter.setPen(QPen(Qt::black, 1));
	QFont font;
	font.setPixelSize(32);
	painter.setFont(font);
	painter.drawText(tx - 50, ty - 50, 100, 100, Qt::AlignVCenter
			| Qt::AlignHCenter, QString::number(beat + 1));

}

