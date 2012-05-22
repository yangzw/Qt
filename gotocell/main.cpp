#include<QApplication>
#include<QDialog>
#include"gotocelldialog.h"

int main(int argc, char *argv[])
{
	QApplication app(argc,argv);

	GoToCellDialog *dialog = new GoToCellDialog;
	dialog->show();
	return app.exec();
}

//#include<QApplication>
//#include<QDialog>
//#include"ui_gotocelldialog.h"

//int main(int argc, char *argv[])
//{
//	QApplication app(argc,argv);

//	Ui_Dialog ui;
//	QDialog *dialog = new QDialog;
//	ui.setupUi(dialog);
//	dialog->show();
//	return app.exec();
//}
