#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime> // Vereinigt: QDate QTime

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
		Q_OBJECT
		
	public:
		MainWindow(QWidget *parent = nullptr);
		~MainWindow();
		
	private slots:
		void on_convertPushButton_clicked();
		
		void on_addSubPushButton_clicked();
		
		void on_pushButton_clicked();
		
	private:
		Ui::MainWindow *ui;
		QDateTime dt;
		
		void setDateTime(const QDateTime &dt);
		
};
#endif // MAINWINDOW_H
