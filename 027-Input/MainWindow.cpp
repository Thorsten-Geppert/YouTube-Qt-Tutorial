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


void MainWindow::on_pushButton_clicked()
{
    //ui->lineEdit->setText("Hello World");
    qDebug() << ui->lineEdit->text();
}


void MainWindow::on_lineEdit_returnPressed()
{
    qDebug() << "Enter wurde gedrückt:" << ui->lineEdit->text();
}


void MainWindow::on_pushButton_3_clicked()
{
    //ui->plainTextEdit->setPlainText("Hallo YouTube\nHier bin ich\nViele Gruesse");
    qDebug() << ui->plainTextEdit->toPlainText();
}


void MainWindow::on_pushButton_2_clicked()
{
    //ui->textEdit->setText("Hallo <b>Welt</b><br><i>Hier bin <u>ich</u></i>");
    
    QTextCharFormat format;
    format.setFontWeight(QFont::Bold);
    ui->textEdit->textCursor().mergeCharFormat(format);
}

