#include "MyDockWidget.h"
#include <QVBoxLayout>
#include <QPushButton>

MyDockWidget::MyDockWidget(
	QWidget *parent
) : QDockWidget(
	parent
) {
	setFeatures(QDockWidget::DockWidgetMovable);
	
	QWidget *widget = new QWidget;
	widget->setLayout(new QVBoxLayout);
	widget->layout()->addWidget(new QPushButton("Press me A"));
	widget->layout()->addWidget(new QPushButton("Press me B"));
	
	qobject_cast<QVBoxLayout *>(widget->layout())->addStretch();
	
	setWidget(widget);
}
