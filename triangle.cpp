#include "triangle.h"
#include "stick.h"
#include <vector>

Triangle::Triangle(QObject *parent) : QGraphicsItem()
{
	angle = 0;     // Задаём угол поворота графического объекта
	setRotation(angle);     // Устанавилваем угол поворота графического объекта
}

Triangle::~Triangle()
{

}

QRectF Triangle::boundingRect() const
{
	return QRectF(-25, -40, 50, 80);   /// Ограничиваем область, в которой лежит треугольник
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QPolygon polygon;   /// Используем класс полигона, чтобы отрисовать треугольник
						/// Помещаем координаты точек в полигональную модель
	polygon << QPoint(0, 0) << QPoint(0, 5) << QPoint(5, 5) << QPoint(5, 10) << QPoint(0, 10) << QPoint(0, 15) << QPoint(-5, 15) << QPoint(-5, 10) << QPoint(-10, 10) << QPoint(-10, 5) << QPoint(-5, 5) << QPoint(-5, 0);
	painter->setBrush(Qt::red);     /// Устанавливаем кисть, которой будем отрисовывать объект
	painter->drawPolygon(polygon);  /// Рисуем треугольник по полигональной модели
	Q_UNUSED(option);
	Q_UNUSED(widget);
}

void Triangle::slotGameTimer()
{

	if (COUNTER > 0) {
		if (COUNTER < 20) setPos(mapToParent(0, -3));
		if (COUNTER >= 20 && COUNTER < 40) setPos(mapToParent(0, -2));
		if (COUNTER >= 40) setPos(mapToParent(0, -1));
		COUNTER++;
	}
	else {
		if (COUNTER > -20) setPos(mapToParent(0, 1));
		if (COUNTER > -40 && COUNTER <= -20 ) setPos(mapToParent(0, 2));
		if (COUNTER <= -40) setPos(mapToParent(0, 3));
		COUNTER--;

		QList<QGraphicsItem *> foundItems = scene()->items(QPolygonF()
			<< mapToParent(-5,-20)
			<< mapToParent(0,-20));

		foreach(QGraphicsItem *item, foundItems) {
			if (item == this) continue;
			
			COUNTER = 1;
			Stick* stick = dynamic_cast<Stick*> (foundItems[1]);
			if (stick->brushed) emit signalCheckItem(false);
			else {
				stick->setBrush();
				emit signalCheckItem(true);
			}
		}
	}

	if (COUNTER == 60) {
		COUNTER = 0;
	}
	/* Поочерёдно выполняем проверку на нажатие клавиш
	* с помощью функции асинхронного получения состояния клавиш,
	* которая предоставляется WinAPI
	* */


	

	if (GetAsyncKeyState(VK_LEFT)) {
		setPos(mapToParent(-3, 0));
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		setPos(mapToParent(3, 0));
		
	}


	/* Проверка выхода за границы поля
	* Если объект выходит за заданные границы, то возвращаем его назад
	* */
	if (this->y() + 10 > 250) {
		emit signalFail();
	}

	if (this->y() < -200) {
		COUNTER = 0;
		emit signalMoveStick();
	}
}

void Triangle::move() {
	setPos(mapToParent(0, 1));
	COUNTER2++;

	if (COUNTER2 % 50 == 0) emit signalCreateStick();

	if (COUNTER2 > 300) {
		COUNTER2 = 0;
		emit signalStopMoveTimer();
	}

}