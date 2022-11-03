#include <QApplication>
#include <QPushButton>
#include <QTranslator>
#include <QLocale>
#include <QObject>
#include <QDebug>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	qDebug() << QLocale();

	QTranslator translator;
	if(translator.load(QLocale(), "Translate", "_"))
		app.installTranslator(&translator);
	else
		qDebug() << "Could not load translation file";

	int language = { 0 }; // 0 = German, 1 = French

	QPushButton pushButton(QPushButton::tr("Hello World"));

	QObject::connect(&pushButton, &QPushButton::clicked, [&]() {
		qDebug() << "Change language" << language;
	
		app.removeTranslator(&translator);

		if(language == 0) {
			translator.load("Translate_fr");
			language = 1;
		} else {
			translator.load("Translate_de");
			language = 0;
		}

		app.installTranslator(&translator);
		pushButton.setText(QPushButton::tr("Hello World"));
	});

	pushButton.show();

	return app.exec();
}
