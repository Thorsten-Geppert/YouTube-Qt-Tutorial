#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include <QDebug.h>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_quitPushButton_clicked()
{
    qDebug() << "Programm beenden";
    close();
}


void MainWindow::on_pushButton_clicked()
{
	qDebug() << "pushButton_clicked";
    
}


void MainWindow::on_checkablePushButton_clicked()
{
	qDebug() << "checkablePushButton_clicked";
}


void MainWindow::on_repeatPushButton_clicked()
{
	static int clicks = 0;
    qDebug() << "repeatPushButton_clicked" << ++clicks;
}


void MainWindow::on_testCheckablePushButton_clicked()
{
    qDebug() << "Checkable PushButton down" << ui->checkablePushButton->isChecked();
}

