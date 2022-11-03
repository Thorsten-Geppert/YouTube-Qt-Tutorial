#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog)
{
	ui->setupUi(this);
}

Dialog::~Dialog()
{
	delete ui;
}

void Dialog::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Qt::Key_0)
		reject();
}

void Dialog::on_pushButton_clicked()
{
    accept();
}


void Dialog::on_pushButton_2_clicked()
{
    reject();
}


void Dialog::on_pushButton_3_clicked()
{
    done(23);
}

