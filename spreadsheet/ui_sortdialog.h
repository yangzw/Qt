/********************************************************************************
** Form generated from reading UI file 'sortdialog.ui'
**
** Created: Tue May 22 13:36:14 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTDIALOG_H
#define UI_SORTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *primarygroupbox;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *primarycolumncombo;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QComboBox *primaryordercombo;
    QVBoxLayout *verticalLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *moreButton;
    QSpacerItem *verticalSpacer;
    QGroupBox *secondarygroupbox;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QComboBox *sencondarycolumncombo;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QComboBox *secondaryordercombo;
    QGroupBox *tertialygroupbox;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QComboBox *tertiarycolumncombo;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_6;
    QComboBox *tertiaryordercombo;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(389, 409);
        gridLayout_4 = new QGridLayout(Dialog);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        primarygroupbox = new QGroupBox(Dialog);
        primarygroupbox->setObjectName(QString::fromUtf8("primarygroupbox"));
        gridLayout = new QGridLayout(primarygroupbox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(primarygroupbox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        primarycolumncombo = new QComboBox(primarygroupbox);
        primarycolumncombo->setObjectName(QString::fromUtf8("primarycolumncombo"));

        gridLayout->addWidget(primarycolumncombo, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(125, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_2 = new QLabel(primarygroupbox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        primaryordercombo = new QComboBox(primarygroupbox);
        primaryordercombo->setObjectName(QString::fromUtf8("primaryordercombo"));

        gridLayout->addWidget(primaryordercombo, 1, 1, 1, 2);


        gridLayout_4->addWidget(primarygroupbox, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        okButton = new QPushButton(Dialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setDefault(true);

        verticalLayout->addWidget(okButton);

        cancelButton = new QPushButton(Dialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        verticalLayout->addWidget(cancelButton);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        moreButton = new QPushButton(Dialog);
        moreButton->setObjectName(QString::fromUtf8("moreButton"));
        moreButton->setCheckable(true);

        verticalLayout->addWidget(moreButton);


        gridLayout_4->addLayout(verticalLayout, 0, 1, 2, 1);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 1, 0, 1, 1);

        secondarygroupbox = new QGroupBox(Dialog);
        secondarygroupbox->setObjectName(QString::fromUtf8("secondarygroupbox"));
        gridLayout_2 = new QGridLayout(secondarygroupbox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(secondarygroupbox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        sencondarycolumncombo = new QComboBox(secondarygroupbox);
        sencondarycolumncombo->setObjectName(QString::fromUtf8("sencondarycolumncombo"));

        gridLayout_2->addWidget(sencondarycolumncombo, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(125, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        label_4 = new QLabel(secondarygroupbox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        secondaryordercombo = new QComboBox(secondarygroupbox);
        secondaryordercombo->setObjectName(QString::fromUtf8("secondaryordercombo"));

        gridLayout_2->addWidget(secondaryordercombo, 1, 1, 1, 2);


        gridLayout_4->addWidget(secondarygroupbox, 2, 0, 1, 1);

        tertialygroupbox = new QGroupBox(Dialog);
        tertialygroupbox->setObjectName(QString::fromUtf8("tertialygroupbox"));
        gridLayout_3 = new QGridLayout(tertialygroupbox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_5 = new QLabel(tertialygroupbox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        tertiarycolumncombo = new QComboBox(tertialygroupbox);
        tertiarycolumncombo->setObjectName(QString::fromUtf8("tertiarycolumncombo"));

        gridLayout_3->addWidget(tertiarycolumncombo, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(125, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        label_6 = new QLabel(tertialygroupbox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        tertiaryordercombo = new QComboBox(tertialygroupbox);
        tertiaryordercombo->setObjectName(QString::fromUtf8("tertiaryordercombo"));

        gridLayout_3->addWidget(tertiaryordercombo, 1, 1, 1, 2);


        gridLayout_4->addWidget(tertialygroupbox, 3, 0, 1, 1);

        QWidget::setTabOrder(okButton, cancelButton);
        QWidget::setTabOrder(cancelButton, primarycolumncombo);
        QWidget::setTabOrder(primarycolumncombo, primaryordercombo);
        QWidget::setTabOrder(primaryordercombo, moreButton);
        QWidget::setTabOrder(moreButton, sencondarycolumncombo);
        QWidget::setTabOrder(sencondarycolumncombo, secondaryordercombo);
        QWidget::setTabOrder(secondaryordercombo, tertiaryordercombo);
        QWidget::setTabOrder(tertiaryordercombo, tertiarycolumncombo);

        retranslateUi(Dialog);
        QObject::connect(okButton, SIGNAL(clicked()), Dialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), Dialog, SLOT(reject()));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), secondarygroupbox, SLOT(setVisible(bool)));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), tertialygroupbox, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Sort Dialog", 0, QApplication::UnicodeUTF8));
        primarygroupbox->setTitle(QApplication::translate("Dialog", "&Primary Key", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Column", 0, QApplication::UnicodeUTF8));
        primarycolumncombo->clear();
        primarycolumncombo->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "none", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("Dialog", "Order", 0, QApplication::UnicodeUTF8));
        primaryordercombo->clear();
        primaryordercombo->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "Ascending", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "Descending", 0, QApplication::UnicodeUTF8)
        );
        okButton->setText(QApplication::translate("Dialog", "OK", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("Dialog", "Cancel", 0, QApplication::UnicodeUTF8));
        moreButton->setText(QApplication::translate("Dialog", "&More", 0, QApplication::UnicodeUTF8));
        secondarygroupbox->setTitle(QApplication::translate("Dialog", "&Secondary Key", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "Column", 0, QApplication::UnicodeUTF8));
        sencondarycolumncombo->clear();
        sencondarycolumncombo->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "none", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("Dialog", "Order", 0, QApplication::UnicodeUTF8));
        secondaryordercombo->clear();
        secondaryordercombo->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "Ascending", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "Descending", 0, QApplication::UnicodeUTF8)
        );
        tertialygroupbox->setTitle(QApplication::translate("Dialog", "&Tertiary Key", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Dialog", "Column", 0, QApplication::UnicodeUTF8));
        tertiarycolumncombo->clear();
        tertiarycolumncombo->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "none", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("Dialog", "Order", 0, QApplication::UnicodeUTF8));
        tertiaryordercombo->clear();
        tertiaryordercombo->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "Ascending", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "Descending", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTDIALOG_H
