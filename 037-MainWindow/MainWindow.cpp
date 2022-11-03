#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QLineEdit>
#include <QDebug>
#include "MyDockWidget.h"

MainWindow::MainWindow(
	QWidget *parent
) : QMainWindow(
	parent
), ui(
	new Ui::MainWindow
) {
	ui->setupUi(this);
	
	button1 = new QPushButton("Button 1");
	button2 = new QPushButton("Button 2");
	
	setCentralWidget(button1);
	
	MyDockWidget *myDockWidget = new MyDockWidget(this);
	myDockWidget->setAllowedAreas(
		Qt::LeftDockWidgetArea
		|
		Qt::RightDockWidgetArea
	);
	
	addDockWidget(Qt::LeftDockWidgetArea, myDockWidget);
	
	// Slots
	connect(ui->actionMeldung_anzeigen, &QAction::triggered, this, &MainWindow::messageSlot);
	
	// StatusBar
	statusBar()->addPermanentWidget(new QLineEdit("Suche..."));
}

MainWindow::~MainWindow() {
	delete ui;
}


void MainWindow::on_actionDebug_Meldung_triggered() {
	qDebug() << "Der Menuepunkt wurde geklickt";
}

void MainWindow::messageSlot() {
	ui->statusbar->showMessage("Message angekickt", 2000);
}


void MainWindow::on_actionMinimieren_triggered() {
	showMinimized();
}


void MainWindow::on_actionMaximieren_triggered() {
    showMaximized();
}


void MainWindow::on_actionWiederherstellen_triggered() {
    showNormal();
}


void MainWindow::on_actionWechseln_triggered() {
    QWidget *widget = takeCentralWidget();
    if(widget == button1)
		setCentralWidget(button2);
	else
		setCentralWidget(button1);
}

