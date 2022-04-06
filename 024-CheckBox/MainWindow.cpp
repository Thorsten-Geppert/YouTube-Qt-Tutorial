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
    ui->lineEdit->setText(ui->checkBox1->isChecked() ? "Checked" : "Not checked");
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->checkBox2->setChecked(!ui->checkBox2->isChecked());
}

