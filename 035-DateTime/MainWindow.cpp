#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	
	dt = QDateTime::currentDateTime();
	ui->dateTimeLineEdit->setText(dt.toString("dd.MM.yyyy hh:mm:ss"));
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_convertPushButton_clicked()
{
    dt = QDateTime::fromString(
		ui->dateTimeLineEdit->text(),
		"dd.MM.yyyy hh:mm:ss"
    );
    
	setDateTime(dt);
}

void MainWindow::setDateTime(const QDateTime &dt)
{
	ui->resultLineEdit->setText(dt.toString("dd.MM.yyyy hh:mm:ss"));
}


void MainWindow::on_addSubPushButton_clicked()
{
    bool ok = false;
    int value = ui->inputLineEdit->text().toInt(&ok);
    if(ok) {
		if(ui->addSubComboBox->currentIndex() != 0)
			value *= -1;
		
		switch(ui->kindComboBox->currentIndex()) {
			case 0: dt = dt.addSecs(value * 3600); break; // Stunden
			case 1: dt = dt.addSecs(value * 60); break; // Minuten
			case 2: dt = dt.addSecs(value); break; // Sekunden
			case 3: dt = dt.addDays(value); break; // Tage
			case 4: dt = dt.addMonths(value); break; // Monate
			case 5: dt = dt.addYears(value); break; // Jahre
		}
		
		setDateTime(dt);
    } else {
		ui->resultLineEdit->setText("Input error");
    }
}


void MainWindow::on_pushButton_clicked()
{
	ui->daysLineEdit->setText(
		QString::number(ui->fromDateEdit->date().daysTo(ui->toDateEdit->date()))
	);
}

