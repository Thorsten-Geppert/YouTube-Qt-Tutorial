#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include <QDebug>

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


void MainWindow::on_commandLinkButton_clicked()
{
	qDebug() << "Schwarz wurde gewaehlt";
    
}


void MainWindow::on_commandLinkButton_2_clicked()
{
	qDebug() << "Rot wurde gewaehlt";
}


void MainWindow::on_commandLinkButton_3_clicked()
{
    qDebug() << "Weiss wurde gewaehlt";
}

