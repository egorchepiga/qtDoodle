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
	/* Сигнал, который передаётся в ядро игры с элементом QGraphicsItem,
	* на который наткнулась муха, и требуется принять решение о том,
	* что с этим элементом делать.
	* */
	void signalDeleteItem(QGraphicsItem *item);
	void signalStopMoveTimer();

	public slots :
		void slotGameTimer(); // Слот, который отвечает за обработку перемещения палки
		void slotMoveStickTimer();
		

protected:
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


private:
	int COUNTER = 0;
};

#endif // TRIANGLE_H