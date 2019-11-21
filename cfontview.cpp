#include "cfontview.h"
#include "ui_cfontview.h"

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
	m_defaultColor	= palette.color(this->backgroundRole());
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
		foreground	= QString("color: rgba(%1, %2, %3, %4); ").arg(m_foregroundColor.red()).arg(m_foregroundColor.green()).arg(m_foregroundColor.blue()).arg(255);

	if(m_backgroundColor.isValid())
		background	= QString("background-color: rgba(%1, %2, %3, %4); ").arg(m_backgroundColor.red()).arg(m_backgroundColor.green()).arg(m_backgroundColor.blue()).arg(255);

	if(!foreground.isEmpty() || !background.isEmpty())
		ui->m_lpSampleText->setStyleSheet("QLabel { " + foreground + background + " }");
}

void cFontView::mouseMoveEvent(QMouseEvent* event)
{
qDebug() << event->type();

	if(event->type() == QEvent::Enter)
		ui->m_lpSampleText->setStyleSheet(QString("QLabel { background-color: rgba(0, 0, 255, 255); }"));
	else if(event->type() == QEvent::Leave)
		ui->m_lpSampleText->setStyleSheet(QString("QLabel { background-color: rgba(%1, %2, %3, %4); }").arg(m_defaultColor.red()).arg(m_defaultColor.green()).arg(m_defaultColor.blue()).arg(255));

	event->accept();
}
