#ifndef VISMETRO_H
#define VISMETRO_H

#include <QtGui/QWidget>
#include <QPainter>
#include <QTimer>
#include <QTime>
#include <QSound>
#include <math.h>

class VisMetro: public QWidget
{
Q_OBJECT

public:
	VisMetro(QWidget *parent = 0);
	~VisMetro();

protected:
	void paintEvent(QPaintEvent *event);

private slots:
	void beat_update();

private:
	int beat;
	QSound strong;
	QSound weak;

};

#endif // VISMETRO_H
