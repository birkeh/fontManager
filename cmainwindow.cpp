#include "cmainwindow.h"
#include "ui_cmainwindow.h"

#include "cfontview.h"

#include <QSettings>

#include <QDebug>


cMainWindow::cMainWindow(cSplashScreen* lpSplashScreen, QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::cMainWindow),
	m_lpSplashScreen(lpSplashScreen)
{
	initUI();
	createActions();

	m_fontDatabase.addApplicationFont("C:\\Temp\\Fonts\\a song for jennifer.ttf");
	m_fontDatabase.addApplicationFont("C:\\Temp\\Fonts\\Grunge Handwriting.ttf");

	QStringList		families	= m_fontDatabase.families();

	for(const QString& family : families)
	{
		cFontView*	lpFontView	= new cFontView(this);
		lpFontView->setText(family);
		lpFontView->setFont(QFont(family, 16));
		lpFontView->setBackground(Qt::white);
		lpFontView->setForeground(Qt::black);
		ui->m_lpLayout->addWidget(lpFontView);
	}
}

cMainWindow::~cMainWindow()
{
	delete ui;
}

void cMainWindow::closeEvent(QCloseEvent *event)
{
	QSettings	settings;
	settings.setValue("main/width", QVariant::fromValue(size().width()));
	settings.setValue("main/height", QVariant::fromValue(size().height()));
	settings.setValue("main/x", QVariant::fromValue(x()));
	settings.setValue("main/y", QVariant::fromValue(y()));
	if(this->isMaximized())
		settings.setValue("main/maximized", QVariant::fromValue(true));
	else
		settings.setValue("main/maximized", QVariant::fromValue(false));

	event->accept();
}

void cMainWindow::initUI()
{
	QSettings	settings;

	ui->setupUi(this);

	if(!settings.value("main/maximized").toBool())
	{
		qint32		iX		= settings.value("main/x", QVariant::fromValue(-1)).toInt();
		qint32		iY		= settings.value("main/y", QVariant::fromValue(-1)).toInt();
		qint32		iWidth	= settings.value("main/width", QVariant::fromValue(-1)).toInt();
		qint32		iHeight	= settings.value("main/height", QVariant::fromValue(-1)).toInt();

		if(iWidth != -1 && iHeight != -1)
			resize(iWidth, iHeight);
		if(iX != -1 && iY != -1)
			move(iX, iY);
	}

//	m_lpProgressBar			= new QProgressBar(this);
//	m_lpProgressBar->setVisible(false);
//	ui->m_lpStatusBar->addPermanentWidget(m_lpProgressBar);
}

void cMainWindow::createActions()
{
	setToolButtonStyle(Qt::ToolButtonFollowStyle);

	createFileActions();
	createContextActions();

//	connect(ui->m_lpFileList,		&cTreeView::deleteEntrys,	this,		&cMainWindow::onDeleteEntrys);
//	connect(ui->m_lpThumbnailSize,	&QSlider::valueChanged,		this,		&cMainWindow::onThumbnailSize);
}

void cMainWindow::createContextActions()
{
}

void cMainWindow::createFileActions()
{
//	m_lpFileToolBar	= addToolBar("file");

//	const QIcon	openIcon			= QIcon::fromTheme("document-open");
//	m_lpOpenFileAction				= m_lpFileToolBar->addAction(openIcon, tr("&Open..."), this, &cMainWindow::onAddFile);
//	m_lpOpenFileAction->setShortcut(QKeySequence::Open);

//	const QIcon	openDirectoryIcon	= QIcon::fromTheme("folder");
//	m_lpOpenDirectoryAction			= m_lpFileToolBar->addAction(openIcon, tr("&Open Folder..."), this, &cMainWindow::onAddFolder);


//	m_lpListToolBar	= addToolBar("list");

//	const QIcon	deleteIcon			= QIcon::fromTheme("edit-delete");
//	m_lpDeleteAction				= m_lpListToolBar->addAction(deleteIcon, tr("&Delete"), this, &cMainWindow::onDeleteEntrys);
//	m_lpDeleteAction->setShortcut(QKeySequence::Delete);

//	const QIcon	clearIcon			= QIcon::fromTheme("edit-clear");
//	m_lpClearAction					= m_lpListToolBar->addAction(clearIcon, tr("&Clear"), this, &cMainWindow::onClearList);


//	m_lpActionToolBar	= addToolBar("action");

//	const QIcon	convertIcon			= QIcon::fromTheme("system-run");
//	m_lpConvertAction				= m_lpActionToolBar->addAction(convertIcon, tr("&Convert"), this, &cMainWindow::onConvert);
//	m_lpConvertAction->setShortcut(QKeySequence::Delete);

//	const QIcon	stopIcon			= QIcon::fromTheme("process-stop");
//	m_lpStopAction					= m_lpActionToolBar->addAction(stopIcon, tr("&Stop"), this, &cMainWindow::onStop);
}
