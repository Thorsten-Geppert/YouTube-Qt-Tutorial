#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Dialog.h"

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
    Dialog *dialog = new Dialog(this);
    
    connect(dialog, &QDialog::accepted, this, &MainWindow::acceptSlot);
    connect(dialog, &QDialog::rejected, this, &MainWindow::rejectSlot);
    connect(dialog, &QDialog::finished, this, &MainWindow::finishSlot);
    
    dialog->show();
}

void MainWindow::acceptSlot() {
	ui->lineEdit->setText("Accept");
}

void MainWindow::rejectSlot() {
	ui->lineEdit->setText("Reject");
}

void MainWindow::finishSlot(int result) {
	ui->lineEdit->setText("Finish: " + QString::number(result));
}

