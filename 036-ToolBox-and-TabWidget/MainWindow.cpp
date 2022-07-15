#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QPushButton>

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


void MainWindow::on_pushButton_2_clicked()
{
    if(ui->toolBox->currentIndex() + 1 < ui->toolBox->count())
		ui->toolBox->setCurrentIndex(ui->toolBox->currentIndex() + 1);
	else
		ui->toolBox->setCurrentIndex(0);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->toolBox->insertItem(0, new QPushButton("Hello World"), "Erste Seite");
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->tabWidget->addTab(new QWidget, "Mein eigener Tab");
}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

