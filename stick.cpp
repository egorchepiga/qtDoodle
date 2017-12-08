#include "Stick.h"
#include <iostream>

Stick::Stick(QObject *parent) : QGraphicsItem()
{

}

Stick::~Stick()
{

}

QRectF Stick::boundingRect() const
{
	return QRectF(-25, -40, 50, 80);   /// ������������ �������, � ������� ����� �����������
}

void Stick::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QPolygon polygon;   /// ���������� ����� ��������, ����� ���������� �����
						/// �������� ���������� ����� � ������������� ������
	polygon << QPoint(0, -10) << QPoint(-25, -10) << QPoint(-25, 0) << QPoint(0, 0);
	
	     /// ������������� �����, ������� ����� ������������ ������
	if (brushed) painter->setBrush(Qt::red);
	else painter->setBrush(Qt::blue);

	painter->drawPolygon(polygon);  /// ������ ����������� �� ������������� ������
	Q_UNUSED(option);
	Q_UNUSED(widget);
}

void Stick::slotGameTimer()
{
	if (this->y() + 10 > 300) {
		emit signalDeleteItem(this);
	}
}

void Stick::slotMoveStickTimer()
{
        setPos(mapToParent(0, 1));
		COUNTER++;
		if (COUNTER > 300) {
			COUNTER = 0;
			
		}
}

void Stick::setBrush()
{
	this -> brushed = true;
}

