#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	
	connect(
		ui->pushButton,
		&QPushButton::clicked,
		this,
		&MainWindow::pushButtonSlot
	);
	
	connect(
		this,
		&MainWindow::mySignal,
		this,
		&MainWindow::mySignalSlot
	);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::pushButtonSlot()
{
	qDebug() << "pushButtonSlot aufgerufen";
	
	emit mySignal();
}

void MainWindow::mySignalSlot() {
	qDebug() << "mySignalSlot aufgerufen";
}

