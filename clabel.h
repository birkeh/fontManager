#ifndef CLABEL_H
#define CLABEL_H


#include <QLabel>
#include <QEvent>


class cLabel : public QLabel
{
	Q_OBJECT

public:
	cLabel(const QString &text, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
	cLabel(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

protected:
	void enterEvent(QEvent *ev) override;
	void leaveEvent(QEvent *ev) override;

signals:
	void					windowEntered();
	void					windowLeft();
};

#endif // CLABEL_H
