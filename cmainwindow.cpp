#include "cmainwindow.h"
#include "ui_cmainwindow.h"

#include "cfontview.h"

#include <QFontDatabase>
#include <QDebug>


cMainWindow::cMainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::cMainWindow)
{
	ui->setupUi(this);

	QFontDatabase	fontDatabase;

	fontDatabase.addApplicationFont("C:\\Temp\\Fonts\\a song for jennifer.ttf");
	fontDatabase.addApplicationFont("C:\\Temp\\Fonts\\Grunge Handwriting.ttf");

	QStringList		families	= fontDatabase.families();

	for(const QString& family : families)
	{
		cFontView*	lpFontView	= new cFontView(this);
		lpFontView->setText(family);
		lpFontView->setFont(QFont(family, 16));
		ui->m_lpLayout->addWidget(lpFontView);
	}
}

cMainWindow::~cMainWindow()
{
	delete ui;
}
