#ifndef CCHECKBOX_H
#define CCHECKBOX_H


#include <QCheckBox>
#include <QMouseEvent>


class cCheckBox : public QCheckBox
{
	Q_OBJECT

public:
	cCheckBox(const QString &text, QWidget *parent = nullptr);
	cCheckBox(QWidget *parent = nullptr);

protected:
	void					enterEvent(QEvent *ev) override;
	void					leaveEvent(QEvent *ev) override;

signals:
	void					windowEntered();
	void					windowLeft();
};

#endif // CCHECKBOX_H
