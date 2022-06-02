#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QLabel>
#include <QImage>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	
	// Katzenbild anzeigen
	QImage catImage(":/cat.jpg");
	
	QLabel *catLabel = new QLabel;
	catLabel->setPixmap(QPixmap::fromImage(catImage));
	
	ui->scrollArea->setWidget(catLabel);
}

MainWindow::~MainWindow()
{
	delete ui;
}

