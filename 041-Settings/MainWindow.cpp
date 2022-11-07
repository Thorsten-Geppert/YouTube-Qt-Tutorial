#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QSettings>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QCoreApplication::setApplicationName("YouTube-Tutorial");
	QCoreApplication::setOrganizationName("DynSoft");
	QCoreApplication::setOrganizationDomain("dynsoft.com");
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::log()
{
	ui->logPlainTextEdit->appendPlainText("");
}

void MainWindow::log(const QString &message)
{
	ui->logPlainTextEdit->appendPlainText(message);
}

void MainWindow::log(const QString &prefix, const QString &message)
{
	ui->logPlainTextEdit->appendPlainText(prefix + ": " + message);
}


void MainWindow::on_savePushButton_clicked()
{
	//QSettings settings("C:\\Users\\thorsten\\Desktop\\Tutorial.ini", QSettings::IniFormat);
	//QSettings settings("DynSoft", "QtTutorialSettings");
	QSettings settings;

	settings.setValue("Window/PositionX", pos().x());
	settings.setValue("Window/PositionY", pos().y());
	settings.setValue("Window/Width", size().width());
	settings.setValue("Window/Height", size().height());
	settings.setValue("Window/Size", size());

	settings.beginGroup("UserSettings");
	settings.setValue("Username", "Thorsten");
	settings.endGroup();
}


void MainWindow::on_loadPushButton_clicked()
{
	//QSettings settings("C:\\Users\\thorsten\\Desktop\\Tutorial.ini", QSettings::IniFormat);
	//QSettings settings("DynSoft", "QtTutorialSettings");
	QSettings settings;

	log("Window");
	log("PositionX", settings.value("Window/PositionX").toString());
	log("PositionY", settings.value("Window/PositionY").toString());
	log("Width", settings.value("Window/Width").toString());
	log("Height", settings.value("Window/Height").toString());
	qDebug() << settings.value("Window/Size").toSize();

	log();

	log("UserSettings");
	settings.beginGroup("UserSettings");
	log("Username", settings.value("Username").toString());
	settings.endGroup();
}

