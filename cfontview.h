#ifndef CFONTVIEW_H
#define CFONTVIEW_H

#include <QWidget>

namespace Ui {
class cFontView;
}

class cFontView : public QWidget
{
	Q_OBJECT

public:
	explicit cFontView(QWidget *parent = nullptr);
	~cFontView();

	void			setText(const QString& text);
	void			setFont(const QFont& font);

private:
	Ui::cFontView*	ui;
};

#endif // CFONTVIEW_H
