#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QKeyEvent>

namespace Ui {
	class Dialog;
}

class Dialog : public QDialog
{
		Q_OBJECT
		
	public:
		explicit Dialog(QWidget *parent = nullptr);
		~Dialog();
		
		void keyPressEvent(QKeyEvent *event) override;
		
	private slots:
		void on_pushButton_clicked();
		
		void on_pushButton_2_clicked();
		
		void on_pushButton_3_clicked();
		
	private:
		Ui::Dialog *ui;
};

#endif // DIALOG_H
