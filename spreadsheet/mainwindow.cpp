#include<QtGui>

#include"finddialog.h"
#include"gotocelldialog.h"
#include"mainwindow.h"
#include"sortdialog.h"
#include"spreadsheet.h"

MainWindow::MainWindow()
{
	spreadsheet = new Spreadsheet;
	setCentralWidget(spreadsheet);

	createActions();
	createMenu();
	createContextMenu();
	createToolBars();
	createStatusBar();
	
	readSettings();

	findDialog = 0;
	
	setWindowIcon(QIcon(":/images/icon.png"));
	setCurrentFile("");
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	if(okToContinue())
	{
		writeSettings();
		event->accept();
	}
	else
		event->ignore();
}

void MainWindow::newFile()
{
	if(okToContinue())
	{
		spreadsheet->clear();
		setCurrentFile("");
	}
}

void MainWindow::open()
{
	if(okToContinue())
	{
		QString fileName = QFileDialog::getOpenFileName(this,tr("Open Spreadsheet"),".",tr("spreadsheet files(*.sp)"));
		if(!fileName.isEmpty())
			loadFile(fileName);
	}
}

bool MainWindow::save()
{
	if(curFile.isEmpty())
		return saveas();
	else
		return saveFile(curFile);
}

bool MainWindow::saveas()
{
	QString fileName = QFileDialog::getSaveFileName(this,tr("Save the spreadsheet"),".",tr("spreadsheet files(*.sp)"));
	if(fileName.isEmpty())
		return false;
	else
		return saveFile(fileName);
}

void MainWindow::find()
{
	if(!findDialog)
	{
		findDialog = new FindDialog(this);
		connect(findDialog,SIGNAL(findNext(const QString&,Qt::CaseSensitivity)),spreadsheet,SLOT(findNext(const QString&,Qt::CaseSensitivity)));
		connect(findDialog,SIGNAL(findPrevious(const QString&,Qt::CaseSensitivity)),spreadsheet,SLOT(findPrevious(const QString&,Qt::CaseSensitivity)));
	}

	findDialog->show();
	findDialog->raise();
	findDialog->activateWindow();
}

void MainWindow::goToCell()
{
	GoToCellDialog  dialog(this);
	if(dialog.exec())
	{
		QString str = dialog.lineEdit->text().toUpper();
		spreadsheet->setCurrentCell(str.mid(1).toInt()-1,str[0].unicode() - 'A');
	}
}

void MainWindow::sort()
{
	SortDialog  dialog(this);
	QTableWidgetSelectionRange range = spreadsheet->selectedRange();
	dialog.setColumnRange('A' + range.leftColumn(),'A'+range.rightColumn());
	if(dialog.exec())
	{
		SpreadsheetCompare compare;
		compare.keys[0]=dialog.primarycolumncombo->currentIndex();
		compare.keys[1]=dialog.sencondarycolumncombo->currentIndex() - 1;
		compare.keys[2]=dialog.tertiarycolumncombo->currentIndex() - 1;
		compare.ascending[0] = (dialog.primaryordercombo->currentIndex() ==0);
		compare.ascending[1] = (dialog.secondaryordercombo->currentIndex() == 0);
		compare.ascending[2] = (dialog.tertiaryordercombo->currentIndex() == 0);
		spreadsheet->sort(compare);
	}
}

void MainWindow::about()
{
	QMessageBox::about(this,tr("About Spreadsheet"),tr("<h2>spreadsheet</h2>"
				"<p>fuck coding!!</p>"));
}

void MainWindow::openRecentFile()
{
	if(okToContinue())
	{
		QAction *action = qobject_cast<QAction *>(sender());
		if(action)
			loadFile(action->data().toString());
	}
}

void MainWindow::updateStatusBar()
{
	locationLabel->setText(spreadsheet->currentLocation());
	formulaLabel->setText(spreadsheet->currentFormula());
}


void MainWindow::spreadsheetModified()
{
	setWindowModified(true);
	updateStatusBar();
}

void MainWindow::createActions()
{
	newAction = new QAction(tr("&New"),this);
	newAction->setIcon(QIcon(":/imags/new.png"));
	newAction->setShortcut(QKeySequence::New);
	newAction->setStatusTip(tr("Create a new spreadsheet file"));
	connect(newAction,SIGNAL(triggered()),this,SLOT(newFile()));
	openAction = new QAction(tr("&Open"),this);
	openAction->setIcon(QIcon(":/imags/open.png"));
	openAction->setShortcut(QKeySequence::Open);
	openAction->setStatusTip(tr("Open a new spreadsheet file"));
	connect(openAction,SIGNAL(triggered()),this,SLOT(open()));
	saveAction = new QAction(tr("&Save"),this);
	saveAction->setIcon(QIcon(":/imgs/save.png"));
	saveAction->setShortcut(QKeySequence::Save);
	saveAction->setStatusTip(tr("Save the file"));
	connect(saveAction,SIGNAL(triggered()),this,SLOT(save()));
	saveAsAction = new QAction(tr("Save &As"),this);
        saveAction->setStatusTip(tr("save as another file"));
	connect(saveAsAction,SIGNAL(triggered()),this,SLOT(saveas()));
	for(int i = 0; i < MaxRecentFiles;++i)
	{
		recenFileActions[i] = new QAction(this);
		recenFileActions[i]->setVisible(false);
		connect(recenFileActions[i],SIGNAL(triggered()),this,SLOT(openRecentFile()));
	}

	exitAction = new QAction(tr("E&xit"),this);
	exitAction->setShortcut(tr("Ctr+Q"));
	exitAction->setStatusTip(tr("Exit the applicatino"));
	connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));

	cutAction = new QAction(tr("Cu&t"),this);
	cutAction->setShortcut(QKeySequence::Cut);
	cutAction->setStatusTip(tr("Cut"));
	connect(cutAction,SIGNAL(triggered()),spreadsheet,SLOT(cut()));
	copyAction = new QAction(tr("&Copy"),this);
	copyAction->setShortcut(QKeySequence::Copy);
	copyAction->setStatusTip(tr("Copy"));
	connect(copyAction,SIGNAL(triggered()),spreadsheet,SLOT(copy()));
	pasteAction = new QAction(tr("&Paste"),this);
	pasteAction->setShortcut(QKeySequence::Paste);
	pasteAction->setStatusTip(tr("paste"));
	connect(pasteAction,SIGNAL(triggered()),spreadsheet,SLOT(paste()));
	deleteAction = new QAction(tr("&Delete"),this);
	deleteAction->setShortcut(QKeySequence::Delete);
	deleteAction->setStatusTip(tr("delete"));
	connect(deleteAction,SIGNAL(triggered()),spreadsheet,SLOT(del()));

	selectRowAction = new QAction(tr("&Row"),this);
	selectRowAction->setStatusTip(tr("select all the cell in the current row"));
	connect(selectRowAction,SIGNAL(triggered()),spreadsheet,SLOT(selectCurrentRow()));

	selectColumnAction = new QAction(tr("&Column"),this);
	selectColumnAction->setStatusTip(tr("Select all the cell in the current column"));
	connect(selectColumnAction,SIGNAL(triggered()),spreadsheet,SLOT(selectCurrentColumn()));

	selectAllAction = new QAction(tr("&All"),this);
	selectAllAction->setStatusTip(tr("Select all the cells"));
	connect(selectAllAction,SIGNAL(triggered()),spreadsheet,SLOT(selectAll()));
	
	findAction = new QAction(tr("&Find"),this);
	findAction->setIcon(QIcon(":/imags/find.png"));
	findAction->setShortcut(QKeySequence::Find);
	findAction->setStatusTip(tr("Find a matching cell"));
	connect(findAction,SIGNAL(triggered()),this,SLOT(find()));

	goToCellAction = new QAction(tr("&Go to cell"),this);
	goToCellAction->setIcon(QIcon(":/imags/gotocell.png"));
	goToCellAction->setShortcut(tr("Ctrl+G"));
	goToCellAction->setStatusTip(tr("Go to the specified file"));
	connect(goToCellAction,SIGNAL(triggered()),this,SLOT(goToCell()));

	recalculateAction = new QAction(tr("&Recalculate"),this);
	recalculateAction->setShortcut(tr("F9"));
	recalculateAction->setStatusTip(tr("Recalculate the spreadsheet's formula"));
	connect(recalculateAction,SIGNAL(triggered()),spreadsheet,SLOT(recalculate()));

	sortAction = new QAction(tr("&Sort"),this);
	sortAction->setStatusTip(tr("Sort the selected cells or all the cells"));
	connect(sortAction,SIGNAL(triggered()),this,SLOT(sort()));

	showGridAction = new QAction(tr("&Show Grid"),this);
	showGridAction->setCheckable(true);
	showGridAction->setChecked(spreadsheet->showGrid());
	showGridAction->setStatusTip(tr("Show or hide the spreadsheet's grid"));
	connect(showGridAction,SIGNAL(toggled(bool)),spreadsheet,SLOT(setShowGrid(bool)));
#if QT_VERSION < 0x040102
    // workaround for a QTableWidget bug in Qt 4.1.1
    connect(showGridAction, SIGNAL(toggled(bool)),
            spreadsheet->viewport(), SLOT(update()));
#endif

	autoRecalculateAction = new QAction(tr("&Auto-recalculate"),this);
	autoRecalculateAction->setCheckable(true);	
	autoRecalculateAction->setChecked(spreadsheet->autoRecalculate());
	autoRecalculateAction->setStatusTip(tr("Switch auto-recalculate on or off"));
        connect(autoRecalculateAction,SIGNAL(toggled(bool)),spreadsheet,SLOT(setAutoRecalculate(bool)));
	
	aboutAction = new QAction(tr("&About"),this);
	aboutAction->setStatusTip(tr("Show this application's about box"));
	connect(aboutAction,SIGNAL(triggered()),this,SLOT(about()));

	aboutqtAction = new QAction(tr("About &Qt"),this);
	aboutqtAction->setStatusTip(tr("Show the QT library's about box"));
	connect(aboutqtAction,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
}

void MainWindow::createMenu()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(newAction);
	fileMenu->addAction(openAction);
	fileMenu->addAction(saveAction);
	fileMenu->addAction(saveAsAction);
	separatorAction = fileMenu->addSeparator();
	for(int i = 0; i < MaxRecentFiles;++i)
		fileMenu->addAction(recenFileActions[i]);
	fileMenu->addSeparator();
	fileMenu->addAction(exitAction);	

	editMenu = menuBar()->addMenu(tr("&Edit"));
        editMenu->addAction(cutAction);
	editMenu->addAction(copyAction);
	editMenu->addAction(pasteAction);
	editMenu->addAction(deleteAction);
	
	selectSubMenu = menuBar()->addMenu(tr("&Select"));
        selectSubMenu->addAction(selectRowAction);
	selectSubMenu->addAction(selectColumnAction);
	selectSubMenu->addAction(selectAllAction);

	editMenu->addSeparator();
	editMenu->addAction(findAction);
	editMenu->addAction(goToCellAction);
	
	toolsMenu = menuBar()->addMenu(tr("Tools"));
	toolsMenu->addAction(recalculateAction);
	toolsMenu->addAction(sortAction);

	optionsMenu = menuBar()->addMenu(tr("&Option"));
	optionsMenu->addAction(showGridAction);
	optionsMenu->addAction(autoRecalculateAction);
	menuBar()->addSeparator();
	
	helpMenu = menuBar()->addMenu(tr("&Help"));	
	helpMenu->addAction(aboutAction);
	helpMenu->addAction(aboutqtAction);
}

void MainWindow::createContextMenu()
{
	spreadsheet->addAction(cutAction);
	spreadsheet->addAction(copyAction);
	spreadsheet->addAction(pasteAction);
	spreadsheet->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::createToolBars()
{
	fileToolBar = addToolBar(tr("&File"));
	fileToolBar->addAction(newAction);
	fileToolBar->addAction(openAction);
	fileToolBar->addAction(saveAction);

	editToolBar = addToolBar(tr("&Edit"));
	editToolBar->addAction(cutAction);
	editToolBar->addAction(copyAction);
	editToolBar->addAction(pasteAction);
	editToolBar->addSeparator();
	editToolBar->addAction(findAction);
	editToolBar->addAction(goToCellAction);
}

void MainWindow::createStatusBar()
{
	locationLabel = new QLabel("W999");
	locationLabel->setAlignment(Qt::AlignHCenter);
	locationLabel->setMinimumSize(locationLabel->sizeHint());

	formulaLabel = new QLabel;
	formulaLabel->setIndent(3);

	statusBar()->addWidget(locationLabel);
	statusBar()->addWidget(formulaLabel);

	connect(spreadsheet,SIGNAL(currentCellChanged(int,int,int,int)),SLOT(updateStatusBar()));
	connect(spreadsheet,SIGNAL(modified()),this,SLOT(spreadsheetModified()));

	updateStatusBar();
}

void MainWindow::readSettings()
{
	QSettings settings("Software Inc.", "Spreadsheet");
	restoreGeometry(settings.value("geometry").toByteArray());
	recenFiles = settings.value("recentfiles").toStringList();
	updateRecenFileActions();

	bool showGrid = settings.value("showGrid",true).toBool();
	showGridAction->setCheckable(showGrid);

	bool autoRecalc = settings.value("autoRecalc",true).toBool();
	autoRecalculateAction->setCheckable(autoRecalc);
}

void MainWindow::writeSettings()
{
	QSettings settings("Software Inc.","Spreadsheet");
	settings.setValue("geometry",saveGeometry());
	settings.setValue("recentfiles",recenFiles);
	settings.setValue("showGrid",showGridAction->isChecked());
	settings.setValue("autoRecalc",autoRecalculateAction->isChecked());
}

bool MainWindow::okToContinue()
{
	if(isWindowModified())
	{
		int r = QMessageBox::warning(this,tr("Spreadsheet"),tr("the document has been modified.\n"
					"Do you want to save your changes?"),
				QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
		if(r == QMessageBox::Yes)
		{
			return save();
		}
		else if(r == QMessageBox::Cancel)
		{
			return false;
		}
	}
	return true;
}

bool MainWindow::loadFile(const QString &fileName)
{
    if(!spreadsheet->readFile(fileName))
    {
        statusBar()->showMessage(tr("Loading canceled"),2000);
        return false;
    }

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File Loaded"),2000);
    return true;
}

bool MainWindow::saveFile(const QString &fileName)
{
    if(!spreadsheet->writeFile(fileName))
    {
        statusBar()->showMessage(tr("Saving canceld"),2000);
        return false;
    }
    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"),2000);
    return true;
}

void MainWindow::setCurrentFile(const QString &fileName)
{
    curFile = fileName;
    setWindowModified(false);

    QString shownName = tr("Untitled");
    if(!curFile.isEmpty())
    {
        shownName = strippedName(curFile);
	recenFiles.removeAll(curFile);
        recenFiles.prepend(curFile);
        updateRecenFileActions();
    }

    setWindowTitle(tr("%1[*]-%2").arg(shownName).arg(tr("Spreadsheet")));
}

void MainWindow::updateRecenFileActions()
{
	QMutableStringListIterator i(recenFiles);
	while(i.hasNext())
	{
		if(!QFile::exists(i.next()))
			i.remove();
	}

	for(int j = 0; j < MaxRecentFiles;++j)
	{
		if(j < recenFiles.count()){
		QString text = tr("&%1 %2").arg(j+1).arg(strippedName(recenFiles[j]));
		recenFileActions[j]->setText(text);
		recenFileActions[j]->setData(recenFiles[j]);
		recenFileActions[j]->setVisible(true);
		}
		else
			recenFileActions[j]->setVisible(false);
	}
}

QString MainWindow::strippedName(const QString &fullFileName)
{
	return QFileInfo(fullFileName).fileName();
}
