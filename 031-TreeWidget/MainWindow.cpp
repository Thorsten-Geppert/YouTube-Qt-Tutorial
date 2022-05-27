#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include <QSpinBox>

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
    ui->treeWidget->topLevelItem(0)->setFirstColumnSpanned(true);
}


void MainWindow::on_pushButton_2_clicked()
{
    QTreeWidgetItem *item = new QTreeWidgetItem;
    item->setText(0, "Erna");
    item->setText(1, "Geppert");
    item->setText(2, "5");
    
    ui->treeWidget->topLevelItem(0)->addChild(item);
}


void MainWindow::on_pushButton_3_clicked()
{
    QTreeWidgetItem *topLevelItem = new QTreeWidgetItem(
		ui->treeWidget,
		QStringList() << "Familie Meier (Eltern und Kinder)"
	);
	topLevelItem->setFirstColumnSpanned(true);
	
	for(int i = 0; i < 4; i++) {
		new QTreeWidgetItem(
			topLevelItem,
			QStringList()
				<< QString("Vorname %1").arg(i)
				<< QString("Nachname %1").arg(i)
				<< QString::number((i + 1) * 3)
		);
	}
}


void MainWindow::on_pushButton_4_clicked()
{
    for(int i = 0; i < ui->treeWidget->topLevelItemCount(); i++) {
		ui->treeWidget->expandItem(ui->treeWidget->topLevelItem(i));
    }
    
	//ui->treeWidget->expandAll();
}

void MainWindow::log(QTreeWidgetItem *item)
{
	if(item) {
		QString line;
		for(int i = 0; i < item->columnCount(); i++)
			line.append(item->text(i) + ":");
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


void MainWindow::on_pushButton_5_clicked()
{
    for(int i = 0; i < ui->treeWidget->topLevelItemCount(); i++)
		list(ui->treeWidget->topLevelItem(i));
}


void MainWindow::on_pushButton_6_clicked()
{
	QSpinBox *spinBox = nullptr;
	QTreeWidgetItem *item = nullptr;
    for(int i = 0; i < ui->treeWidget->topLevelItemCount(); i++) {
		for(int j = 0; j < ui->treeWidget->topLevelItem(i)->childCount(); j++) {
			item = ui->treeWidget->topLevelItem(i)->child(j);
			
			spinBox = new QSpinBox;
			spinBox->setMinimum(0);
			spinBox->setMaximum(130);
			spinBox->setValue(item->text(2).toInt());
			
			ui->treeWidget->setItemWidget(item, 2, spinBox);
		}
    }
}

