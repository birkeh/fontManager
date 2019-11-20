#include "cfontview.h"
#include "ui_cfontview.h"


cFontView::cFontView(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::cFontView)
{
	ui->setupUi(this);
}

cFontView::~cFontView()
{
	delete ui;
}

void cFontView::setText(const QString& text)
{
	ui->m_lpSampleText->setText(text);
}

void cFontView::setFont(const QFont& font)
{
	ui->m_lpSampleText->setFont(font);
}
