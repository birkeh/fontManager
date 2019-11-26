#include "ccheckbox.h"

#include <QDebug>


cCheckBox::cCheckBox(const QString &text, QWidget *parent) :
	QCheckBox(text, parent)
{
	this->setMouseTracking(true);
	this->setAttribute(Qt::WA_Hover);
}

cCheckBox::cCheckBox(QWidget *parent) :
	QCheckBox(parent)
{
	this->setMouseTracking(true);
	this->setAttribute(Qt::WA_Hover);
}

void cCheckBox::enterEvent(QEvent* /*ev*/)
{
	emit(windowEntered());
}

void cCheckBox::leaveEvent(QEvent* /*ev*/)
{
	emit(windowLeft());
}
