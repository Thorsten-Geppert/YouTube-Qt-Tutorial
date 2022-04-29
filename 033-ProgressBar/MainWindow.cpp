#include "MainWindow.h"
#include "./ui_MainWindow.h"

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


void MainWindow::on_pushButton_clicked()
{
    ui->progressBar->setValue(ui->progressBar->value() + 1);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->progressBar->setValue(ui->progressBar->value() - 1);
}

