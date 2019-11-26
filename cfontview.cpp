#include "cfontview.h"
#include "ui_cfontview.h"

#include "common.h"

#include <QDebug>


cFontView::cFontView(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::cFontView)
{
	ui->setupUi(this);
	ui->m_lpSampleText->setAutoFillBackground(true);
	this->setMouseTracking(true);
	this->setAttribute(Qt::WA_Hover);

	QPalette	palette	= this->palette();
//	m_defaultColor	= palette.color(this->backgroundRole());
	m_defaultColor	= palette.color(QPalette::Window);
	m_selectedColor	= palette.color(QPalette::Highlight);

	connect(ui->m_lpFontName,	&cCheckBox::windowEntered,	this,	&cFontView::windowEntered);
	connect(ui->m_lpFontName,	&cCheckBox::windowLeft,	this,	&cFontView::windowLeft);

	connect(ui->m_lpSampleText,	&cLabel::windowEntered,	this,	&cFontView::windowEntered);
	connect(ui->m_lpSampleText,	&cLabel::windowLeft,	this,	&cFontView::windowLeft);
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
	ui->m_lpFontName->setText(font.family());
	ui->m_lpSampleText->setFont(font);
}

void cFontView::setBackground(const QColor& color)
{
	m_backgroundColor	= color;
	setColor();
}

void cFontView::setForeground(const QColor& color)
{
	m_foregroundColor	= color;
	setColor();
}

void cFontView::setColor()
{
	QString	foreground;
	QString	background;

	if(m_foregroundColor.isValid())
		foreground	= "color: " + color2rgba(m_foregroundColor) + "; ";

	if(m_backgroundColor.isValid())
		background	= "background-color: " + color2rgba(m_backgroundColor) + "; ";

	if(!foreground.isEmpty() || !background.isEmpty())
		ui->m_lpSampleText->setStyleSheet("QLabel { " + foreground + background + " }");
}

void cFontView::enterEvent(QEvent* /*ev*/)
{
	windowEntered();
}

void cFontView::leaveEvent(QEvent* /*ev*/)
{
	windowLeft();
}

void cFontView::windowEntered()
{
	ui->m_lpFontName->setStyleSheet("QCheckBox { background-color: " + color2rgba(m_selectedColor) + "; }");
}

void cFontView::windowLeft()
{
	ui->m_lpFontName->setStyleSheet("QCheckBox { background-color: " + color2rgba(m_defaultColor) + "; }");
}
