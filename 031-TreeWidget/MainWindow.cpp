#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include <QLineEdit>

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
    QTreeWidgetItem *item = new QTreeWidgetItem;
    item->setText(0, "Erna");
    item->setText(1, "Meier");
    item->setText(2, "49");
    
    item->setCheckState(0, Qt::CheckState::Checked);
    item->setCheckState(1, Qt::CheckState::Checked);
    item->setCheckState(2, Qt::CheckState::Checked);
    
    ui->treeWidget->topLevelItem(1)->addChild(item);
}


void MainWindow::on_pushButton_2_clicked()
{
    for(int i = 0; i < ui->treeWidget->topLevelItemCount(); i++) {
		ui->treeWidget->expandItem(ui->treeWidget->topLevelItem(i));
    }
}


void MainWindow::on_pushButton_3_clicked()
{
	const int counter = ui->treeWidget->topLevelItemCount();
	for(int i = 0; i < counter; i++) {
		list(ui->treeWidget->topLevelItem(i));
	}
}

void MainWindow::log(QTreeWidgetItem *item)
{
	if(item) {
		QString line;
		for(int i = 0; i < item->columnCount(); i++)
			line.append(item->text(i) + " -> ");
		line.append("END");
		ui->plainTextEdit->appendPlainText(line);
	}
}

void MainWindow::list(QTreeWidgetItem *item)
{
	if(item) {
		log(item);
		for(int i = 0; i < item->childCount(); i++)
			list(item->child(i));
	}
}


void MainWindow::on_pushButton_4_clicked()
{
    QTreeWidgetItem *item = new QTreeWidgetItem;
    item->setText(0, "Das ist");
    item->setText(1, "eine Eingabe:");
    
	ui->treeWidget->topLevelItem(1)->addChild(item);
    ui->treeWidget->setItemWidget(item, 2, new QLineEdit);
    
    
}

