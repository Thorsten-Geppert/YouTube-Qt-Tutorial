#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->comboBox->setCurrentIndex(4);
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_lineEdit_returnPressed()
{
    ui->comboBox->addItem(ui->lineEdit->text());
    ui->lineEdit->clear();
    ui->comboBox->setCurrentIndex(ui->comboBox->count() - 1);
}


void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Index:" << ui->comboBox->currentIndex() << ", Text: " << ui->comboBox->currentText();
}


void MainWindow::on_pushButton_2_clicked()
{
    if(ui->comboBox->currentIndex() >= 0)
		ui->comboBox->removeItem(ui->comboBox->currentIndex());
}


void MainWindow::on_pushButton_3_clicked()
{
    for(int i = 0; i < ui->comboBox->count(); i++) {
		qDebug() << "Index:" << i << ", Text: " << ui->comboBox->itemText(i);
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->comboBox->setCurrentText("Hallo YouTube");
}

