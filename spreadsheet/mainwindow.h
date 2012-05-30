#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>

class QAction;
class QLabel;
class FindDialog;
class Spreadsheet;

class MainWindow: public QMainWindow
{
	Q_OBJECT
	public:
		MainWindow();
	protected:
		void closeEvent(QCloseEvent *event);
	private slots:
		void newFile();
		void open();
		bool save();
		bool saveas();
		void find();
		void goToCell();
		void sort();
		void about();
		void openRecentFile();
		void updateStatusBar();
		void spreadsheetModified();
	private:
		void createActions();
		void createMenu();
		void createContextMenu();
		void createToolBars();
		void createStatusBar();
		void readSettings();
		void writeSettings();
		bool okToContinue();
		bool loadFile(const QString &fileName);
		bool saveFile(const QString &fileName);
		void setCurrentFile(const QString &fileName);
		void updateRecenFileActions();
		QString strippedName(const QString &fullFileName);
		Spreadsheet *spreadsheet;
		FindDialog *findDialog;
		QLabel *locationLabel;
		QLabel *formulaLabel;
		QStringList recenFiles;
		QString curFile;
		
		enum {MaxRecentFiles = 5};
		QAction *recenFileActions[MaxRecentFiles];
		QAction *separatorAction;

		QMenu *fileMenu;
		QMenu *editMenu;
		QMenu *selectSubMenu;
		QMenu *toolsMenu;
		QMenu *optionsMenu;
		QMenu *helpMenu;

		QToolBar *fileToolBar;
		QToolBar *editToolBar;

		QAction *newAction;
		QAction *openAction;
		QAction *saveAction;
		QAction *saveAsAction;
		QAction *exitAction;
		QAction *cutAction;
		QAction *copyAction;
		QAction *pasteAction;
		QAction *deleteAction;
		QAction *selectRowAction;
		QAction *selectColumnAction;
		QAction *selectAllAction;
		QAction *findAction;
		QAction *goToCellAction;
		QAction *recalculateAction;
		QAction *sortAction;
		QAction *showGridAction;
		QAction *autoRecalculateAction;
		QAction *aboutAction;
		QAction *aboutqtAction;
};
#endif
