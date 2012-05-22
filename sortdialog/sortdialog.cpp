#include<QtGui>
#include"sortdialog.h"

SortDialog::SortDialog(QWidget *parent)
	:QDialog(parent)
{
	setupUi(this);

	secondarygroupbox->hide();
	tertialygroupbox->hide();
	layout()->setSizeConstraint(QLayout::SetFixedSize);
	
	setColumnRange('A','Z');
}

void SortDialog::setColumnRange(QChar first, QChar last)
{
	primarycolumncombo->clear();
	sencondarycolumncombo->clear();
	tertiarycolumncombo->clear();

	sencondarycolumncombo->addItem(tr("Nome"));
	tertiarycolumncombo->addItem(tr("Nome"));
	primarycolumncombo->setMinimumSize(sencondarycolumncombo->sizeHint());

	QChar ch = first;
	while(ch != last)
	{
		primarycolumncombo->addItem(QString(ch));
		sencondarycolumncombo->addItem(QString(ch));
		tertiarycolumncombo->addItem(QString(ch));
		ch = ch.unicode() + 1;
	}
}
