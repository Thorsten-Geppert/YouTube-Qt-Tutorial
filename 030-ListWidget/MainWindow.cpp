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


void MainWindow::on_lineEdit_returnPressed()
{
	QListWidgetItem *item = new QListWidgetItem(
		ui->lineEdit->text(),
		ui->listWidget
	);
	
	item->setCheckState(Qt::CheckState::Checked);
    
    
    //ui->listWidget->addItem(ui->lineEdit->text());
    ui->lineEdit->clear();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
}


void MainWindow::on_pushButton_clicked()
{
    /*foreach(QListWidgetItem *item, ui->listWidget->selectedItems()) {
		ui->listWidget->removeItemWidget(item);
		delete item;
    }*/
    
    qDeleteAll(ui->listWidget->selectedItems());
}


void MainWindow::on_pushButton_3_clicked()
{
    QListWidgetItem *item = nullptr;
    for(int i = 0; i < ui->listWidget->count(); i++) {
		item = ui->listWidget->item(i);
		if(item)
			qDebug() << item->text();
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    foreach(QListWidgetItem *item, ui->listWidget->selectedItems()) {
		if(item)
			qDebug() << item->text();
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    QListWidgetItem *item = ui->listWidget->selectedItems().count() > 0 ? ui->listWidget->selectedItems()[0] : nullptr;
    if(item) {
		if(ui->listWidget->isPersistentEditorOpen(item))
			ui->listWidget->closePersistentEditor(item);
		else
			ui->listWidget->openPersistentEditor(item);
    }
}

