#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QShortcut>
#include <QTimer>

#include <triangle.h>

#include <stick.h>

namespace Ui {
	class Widget;
}

class Widget : public QWidget
{
	Q_OBJECT

public:
	explicit Widget(QWidget *parent = 0);
	~Widget();
	void slotJump(boolean brushed);
	void slotFail();
	void slotMoveAll();
	void slotCreateStick();     // Слот для создания яблок, срабатывает по таймеру
	void slotDeleteStick(QGraphicsItem * item);     // Слот для создания яблок, срабатывает по таймеру
	void slotStopMoveTimer();
	void brushInRed(QGraphicsRectItem *item);


private:
	QList<QGraphicsItem *> sticks;  // Список со всеми яблоками, присутствующими в игре
	double score;   // Переменная, которая хранит счёт игре
	Ui::Widget      *ui;
	QGraphicsScene  *scene;     /// Объявляем графическую сцену
	Triangle        *triangle;  /// и треугольник
	Stick        *stick;  /// и треугольник
	QTimer          *timer, *timerStick;     /* Объявляем игровой таймер, благодаря которому
								* будет производиться изменения положения объекта на сцене
								* При воздействии на него клавишами клавиатуры
								* */
};

#endif // WIDGET_H