#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	
	// Spaltenbreiten setzen
	ui->tableWidget->setColumnWidth(0, 300);
	ui->tableWidget->setColumnWidth(1, 300);
	ui->tableWidget->setColumnWidth(2, 100);
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_pushButton_clicked()
{
	int rowCount = ui->tableWidget->rowCount();
	ui->tableWidget->setRowCount(rowCount + 1);
	
	QTableWidgetItem *items [] = {
		new QTableWidgetItem(QString("Vorname %1").arg(rowCount)),
		new QTableWidgetItem(QString("Nachname %1").arg(rowCount)),
		new QTableWidgetItem(QString("Alter %1").arg(rowCount)),
		new QTableWidgetItem
	};
	
	const size_t count = sizeof(items) / sizeof(QTableWidgetItem *);
	for(size_t column = 0; column < count; column++)
		ui->tableWidget->setItem(rowCount, column, items[column]);
	
	QComboBox *salutationComboBox = new QComboBox;
	salutationComboBox->addItems(QStringList() << "Herr" << "Frau" << "Divers");
	ui->tableWidget->setCellWidget(rowCount, 3, salutationComboBox);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

