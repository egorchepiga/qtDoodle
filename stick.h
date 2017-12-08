#ifndef STICK_H
#define STICK_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>



class Stick : public QObject, public QGraphicsItem
{
	Q_OBJECT
public:
	bool brushed = false;
	explicit Stick(QObject *parent = 0);
	~Stick();
	void setBrush();

signals:
	/* ������, ������� ��������� � ���� ���� � ��������� QGraphicsItem,
	* �� ������� ���������� ����, � ��������� ������� ������� � ���,
	* ��� � ���� ��������� ������.
	* */
	void signalDeleteItem(QGraphicsItem *item);
	void signalStopMoveTimer();

	public slots :
		void slotGameTimer(); // ����, ������� �������� �� ��������� ����������� �����
		void slotMoveStickTimer();
		

protected:
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


private:
	int COUNTER = 0;
};

#endif // TRIANGLE_H