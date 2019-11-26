#include "clabel.h"

#include <QDebug>


cLabel::cLabel(const QString &text, QWidget *parent, Qt::WindowFlags f) :
	QLabel(text, parent, f)
{
	this->setMouseTracking(true);
	this->setAttribute(Qt::WA_Hover);
}

cLabel::cLabel(QWidget *parent, Qt::WindowFlags f) :
	QLabel(parent, f)
{
	this->setMouseTracking(true);
	this->setAttribute(Qt::WA_Hover);
}

void cLabel::enterEvent(QEvent* /*ev*/)
{
	emit(windowEntered());
}

void cLabel::leaveEvent(QEvent* /*ev*/)
{
	emit(windowLeft());
}
