#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
	namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
		
	Q_OBJECT
		
	public:
		MainWindow(QWidget *parent = nullptr);
		~MainWindow();
		
	private slots:
		void on_actionDebug_Meldung_triggered();
		void messageSlot();
		
		void on_actionMinimieren_triggered();
		
		void on_actionMaximieren_triggered();
		
		void on_actionWiederherstellen_triggered();
		
		void on_actionWechseln_triggered();
		
	private:
		Ui::MainWindow *ui;
		
		QPushButton *button1;
		QPushButton *button2;
		
};

#endif // MAINWINDOW_H
