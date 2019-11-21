#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H


#include "csplashscreen.h"

#include <QMainWindow>
#include <QFontDatabase>
#include <QCloseEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class cMainWindow; }
QT_END_NAMESPACE

class cMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	cMainWindow(cSplashScreen* lpSplashScreen, QWidget *parent = nullptr);
	~cMainWindow();

private:
	Ui::cMainWindow*				ui;
	cSplashScreen*					m_lpSplashScreen;
	QFontDatabase					m_fontDatabase;

	void							initUI();
	void							createActions();
	void							createFileActions();
	void							createContextActions();

protected:
	void							closeEvent(QCloseEvent* event);
};
#endif // CMAINWINDOW_H
