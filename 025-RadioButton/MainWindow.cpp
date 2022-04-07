#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include <QRadioButton>

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
	QRadioButton *selectedRadioButton = nullptr;

    if(ui->womanRadioButton->isChecked())
		selectedRadioButton = ui->womanRadioButton;
	else if(ui->manRadioButton->isChecked())
		selectedRadioButton = ui->manRadioButton;
	else
		selectedRadioButton = ui->otherRadioButton;
	
	if(selectedRadioButton)
		ui->lineEdit->setText(selectedRadioButton->text());
}

