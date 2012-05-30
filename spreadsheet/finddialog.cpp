#include<QtGui>
#include"finddialog.h"

FindDialog::FindDialog(QWidget *parent)
	: QDialog(parent)
{
	label = new QLabel(tr("Find &what:"));
	lineedit = new QLineEdit;
	label->setBuddy(lineedit);
	casecheckbox = new QCheckBox(tr("Match &case"));
	backwardcheckbox = new QCheckBox(tr("Search &backward"));
	findbutton = new QPushButton(tr("&Find"));
	findbutton->setDefault(true);
	findbutton->setEnabled(false);
	closebutton = new QPushButton(tr("close"));
	
	connect(lineedit,SIGNAL(textChanged(const QString&)),this,SLOT(enableFindButton(const QString &)));
	connect(findbutton,SIGNAL(clicked()),this,SLOT(findClicked()));
	connect(closebutton,SIGNAL(clicked()),this,SLOT(close()));

	QHBoxLayout *topleftlayout = new QHBoxLayout;
	topleftlayout->addWidget(label);
	topleftlayout->addWidget(lineedit);
	QVBoxLayout *leftlayout = new QVBoxLayout;
	leftlayout->addLayout(topleftlayout);
	leftlayout->addWidget(casecheckbox);
	leftlayout->addWidget(backwardcheckbox);
	QVBoxLayout *rightlayout = new QVBoxLayout;
	rightlayout->addWidget(findbutton);
	rightlayout->addWidget(closebutton);
	rightlayout->addStretch();
	QHBoxLayout *mainlayout = new QHBoxLayout;
	mainlayout->addLayout(leftlayout);
	mainlayout->addLayout(rightlayout);
	setLayout(mainlayout);
	
	setWindowTitle(tr("Find"));
	setFixedHeight(sizeHint().height());
}

void FindDialog::findClicked()
{
	QString text = lineedit->text();
	Qt::CaseSensitivity cs = casecheckbox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
	if(backwardcheckbox->isChecked())
	{
		emit findPrevious(text,cs);
	}
	else
	{
		emit findNext(text,cs);
	}
}

void FindDialog::enableFindButton(const QString &text)
{
	findbutton->setEnabled(!text.isEmpty());
}
