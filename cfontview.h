#ifndef CFONTVIEW_H
#define CFONTVIEW_H


#include <QWidget>
#include <QColor>
#include <QMouseEvent>


namespace Ui {
class cFontView;
}

class cFontView : public QWidget
{
	Q_OBJECT

public:
	explicit cFontView(QWidget *parent = nullptr);
	~cFontView() override;

	void			setText(const QString& text);
	void			setFont(const QFont& font);
	void			setBackground(const QColor& color);
	void			setForeground(const QColor& color);

private:
	Ui::cFontView*	ui;
	QColor			m_backgroundColor;
	QColor			m_foregroundColor;
	QColor			m_defaultColor;

	void			setColor();

protected:
	void			mouseMoveEvent(QMouseEvent* event) override;
};

#endif // CFONTVIEW_H
