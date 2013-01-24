/********************************************************************************
** Form generated from reading UI file 'WindowMain.ui'
**
** Created: Thu 24. Jan 16:07:46 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWMAIN_H
#define UI_WINDOWMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowMain
{
public:
    QAction *action;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WindowMain)
    {
        if (WindowMain->objectName().isEmpty())
            WindowMain->setObjectName(QString::fromUtf8("WindowMain"));
        WindowMain->resize(642, 523);
        action = new QAction(WindowMain);
        action->setObjectName(QString::fromUtf8("action"));
        centralWidget = new QWidget(WindowMain);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        WindowMain->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WindowMain);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 642, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        WindowMain->setMenuBar(menuBar);
        statusBar = new QStatusBar(WindowMain);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        WindowMain->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);

        retranslateUi(WindowMain);

        QMetaObject::connectSlotsByName(WindowMain);
    } // setupUi

    void retranslateUi(QMainWindow *WindowMain)
    {
        WindowMain->setWindowTitle(QApplication::translate("WindowMain", "MainWindow", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("WindowMain", "\320\235\320\276\320\262\320\260\321\217", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("WindowMain", "\320\230\320\263\321\200\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WindowMain: public Ui_WindowMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWMAIN_H
