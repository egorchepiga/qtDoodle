#include "widget.h"
#include "ui_widget.h"



Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	ui->setupUi(this);
	this->resize(600, 600);          /// Задаем размеры виджета, то есть окна
	this->setFixedSize(600, 600);    /// Фиксируем размеры виджета

	score = 1;
	ui->lcdNumber->display(score);

	scene = new QGraphicsScene();   /// Инициализируем графическую сцену
	triangle = new Triangle(); 

	ui->graphicsView->setScene(scene);  /// Устанавливаем графическую сцену в graphicsView
	ui->graphicsView->setRenderHint(QPainter::Antialiasing);    /// Устанавливаем сглаживание
	ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// Отключаем скроллбар по вертикали
	ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// Отключаем скроллбар по горизонтали

	scene->setSceneRect(-250, -250, 500, 500); /// Устанавливаем область графической сцены

	scene->addItem(triangle);   /// Добавляем на сцену треугольник
	triangle->setPos(0, 0);      /// Устанавливаем треугольник в центр сцены

	timer = new QTimer();	
	timerStick = new QTimer();

	connect(timer, &QTimer::timeout, triangle, &Triangle::slotGameTimer);
	connect(timerStick, &QTimer::timeout, triangle, &Triangle::move);
	connect(triangle, &Triangle::signalCheckItem, this, &Widget::slotJump);
	connect(triangle, &Triangle::signalFail, this, &Widget::slotFail);
	connect(triangle, &Triangle::signalMoveStick, this, &Widget::slotMoveAll);
	connect(triangle, &Triangle::signalStopMoveTimer, this, &Widget::slotStopMoveTimer);
	connect(triangle, &Triangle::signalCreateStick, this, &Widget::slotCreateStick);


	//---------------------------------------------------------------------------------------------------------------------------------
	
	Stick *stick = new Stick(); // Создаём яблоко

	scene->addItem(stick);      // Помещаем его в сцену со случайной позицией
	stick->setPos((qrand() % (251)) * ((qrand() % 2 == 1) ? 1 : -1), 0);
	stick->setZValue(-1);
	sticks.append(stick);       // Добавляем Яблоко в Список

	connect(timerStick, &QTimer::timeout, stick, &Stick::slotMoveStickTimer);
	connect(timer, &QTimer::timeout, stick, &Stick::slotGameTimer);
	connect(stick, &Stick::signalDeleteItem, this, &Widget::slotDeleteStick);
	connect(stick, &Stick::signalStopMoveTimer, this, &Widget::slotStopMoveTimer);

	Stick *stick2 = new Stick(); // Создаём яблоко

	scene->addItem(stick2);      // Помещаем его в сцену со случайной позицией
	stick2->setPos((qrand() % (251)) * ((qrand() % 2 == 1) ? 1 : -1), 50);
	stick2->setZValue(-1);
	sticks.append(stick2);       // Добавляем Яблоко в Список

	connect(timerStick, &QTimer::timeout, stick2, &Stick::slotMoveStickTimer);
	connect(timer, &QTimer::timeout, stick2, &Stick::slotGameTimer);
	connect(stick2, &Stick::signalDeleteItem, this, &Widget::slotDeleteStick);
	connect(stick2, &Stick::signalStopMoveTimer, this, &Widget::slotStopMoveTimer);

	Stick *stick3 = new Stick(); // Создаём яблоко

	scene->addItem(stick3);      // Помещаем его в сцену со случайной позицией
	stick3->setPos((qrand() % (251)) * ((qrand() % 2 == 1) ? 1 : -1), 100);
	stick3->setZValue(-1);
	sticks.append(stick3);       // Добавляем Яблоко в Список

	connect(timerStick, &QTimer::timeout, stick3, &Stick::slotMoveStickTimer);
	connect(timer, &QTimer::timeout, stick3, &Stick::slotGameTimer);
	connect(stick3, &Stick::signalDeleteItem, this, &Widget::slotDeleteStick);
	connect(stick3, &Stick::signalStopMoveTimer, this, &Widget::slotStopMoveTimer);

	Stick *stick4 = new Stick(); // Создаём яблоко

	scene->addItem(stick4);      // Помещаем его в сцену со случайной позицией
	stick4->setPos((qrand() % (251)) * ((qrand() % 2 == 1) ? 1 : -1), -50);
	stick4->setZValue(-1);
	sticks.append(stick4);       // Добавляем Яблоко в Список

	connect(timerStick, &QTimer::timeout, stick4, &Stick::slotMoveStickTimer);
	connect(timer, &QTimer::timeout, stick4, &Stick::slotGameTimer);
	connect(stick4, &Stick::signalDeleteItem, this, &Widget::slotDeleteStick);
	connect(stick4, &Stick::signalStopMoveTimer, this, &Widget::slotStopMoveTimer);

	Stick *stick5 = new Stick(); // Создаём яблоко

	scene->addItem(stick5);      // Помещаем его в сцену со случайной позицией
	stick5->setPos((qrand() % (251)) * ((qrand() % 2 == 1) ? 1 : -1), -100);
	stick5->setZValue(-1);
	sticks.append(stick5);       // Добавляем Яблоко в Список

	connect(timerStick, &QTimer::timeout, stick5, &Stick::slotMoveStickTimer);
	connect(timer, &QTimer::timeout, stick5, &Stick::slotGameTimer);
	connect(stick5, &Stick::signalDeleteItem, this, &Widget::slotDeleteStick);
	connect(stick5, &Stick::signalStopMoveTimer, this, &Widget::slotStopMoveTimer);

	Stick *stick6 = new Stick(); // Создаём яблоко

	scene->addItem(stick6);      // Помещаем его в сцену со случайной позицией
	stick6->setPos((qrand() % (251)) * ((qrand() % 2 == 1) ? 1 : -1), -200);
	stick6->setZValue(-1);
	sticks.append(stick6);       // Добавляем Яблоко в Список

	connect(timerStick, &QTimer::timeout, stick6, &Stick::slotMoveStickTimer);
	connect(timer, &QTimer::timeout, stick6, &Stick::slotGameTimer);
	connect(stick6, &Stick::signalDeleteItem, this, &Widget::slotDeleteStick);
	connect(stick6, &Stick::signalStopMoveTimer, this, &Widget::slotStopMoveTimer);
	//-----------------------------------------------------------------------------

	Stick *stick7 = new Stick(); // Создаём яблоко

	
	scene->addItem(stick7);      // Помещаем его в сцену со случайной позицией
	stick7->setPos((qrand() % (251)) * ((qrand() % 2 == 1) ? 1 : -1), -250);
	stick7->setZValue(-1);
	sticks.append(stick7);       // Добавляем Яблоко в Список

	connect(timerStick, &QTimer::timeout, stick7, &Stick::slotMoveStickTimer);
	connect(timer, &QTimer::timeout, stick7, &Stick::slotGameTimer);
	connect(stick7, &Stick::signalDeleteItem, this, &Widget::slotDeleteStick);
	connect(stick7, &Stick::signalStopMoveTimer, this, &Widget::slotStopMoveTimer);


	Stick *stick8 = new Stick(); // Создаём яблоко
	scene->addItem(stick8);      // Помещаем его в сцену со случайной позицией
	stick8->setPos((qrand() % (251)) * ((qrand() % 2 == 1) ? 1 : -1), -150);
	stick8->setZValue(-1);
	sticks.append(stick8);       // Добавляем Яблоко в Список

	connect(timerStick, &QTimer::timeout, stick8, &Stick::slotMoveStickTimer);
	connect(timer, &QTimer::timeout, stick8, &Stick::slotGameTimer);
	connect(stick8, &Stick::signalDeleteItem, this, &Widget::slotDeleteStick);
	connect(stick8, &Stick::signalStopMoveTimer, this, &Widget::slotStopMoveTimer);
	//---------------------------------------------------------------------------------------------------------------------------------

	timer->start(1000 / 150);
}

Widget::~Widget()
{
	delete ui;
}

void Widget::slotJump(boolean brushed)
{
	if(brushed) ui->lcdNumber->display(score++);
};

void Widget::slotFail()
{
	score = 1;
	ui->lcdNumber->display(score);
	triangle->setPos(0, -150);
};

void Widget::slotCreateStick()
{
	Stick *stick = new Stick(); // Создаём яблоко

	scene->addItem(stick);      // Помещаем его в сцену со случайной позицией
	stick->setPos((qrand() % (251)) * ((qrand() % 2 == 1) ? 1 : -1),-300);
	stick->setZValue(-1);      

	connect(timerStick, &QTimer::timeout, stick, &Stick::slotMoveStickTimer);
	connect(timer, &QTimer::timeout, stick, &Stick::slotGameTimer);
	connect(stick, &Stick::signalDeleteItem, this, &Widget::slotDeleteStick);
	connect(stick, &Stick::signalStopMoveTimer, this, &Widget::slotStopMoveTimer);

}

void Widget::slotDeleteStick(QGraphicsItem *item)
{
	foreach(QGraphicsItem *stick, sticks) {
		if (stick == item) {
			scene->removeItem(stick);   // Удаляем со сцены
			delete stick;               // Вообще удаляем
		}
	}

}

void Widget::slotStopMoveTimer() {
	timerStick->stop();
}


void Widget::slotMoveAll() {
	timerStick->start();
}


