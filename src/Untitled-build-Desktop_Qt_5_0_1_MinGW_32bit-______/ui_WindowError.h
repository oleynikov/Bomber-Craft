/********************************************************************************
** Form generated from reading UI file 'WindowError.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWERROR_H
#define UI_WINDOWERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowError
{
public:
    QPushButton *buttonApplicationExit;
    QLabel *labelErrorMessage;

    void setupUi(QWidget *WindowError)
    {
        if (WindowError->objectName().isEmpty())
            WindowError->setObjectName(QStringLiteral("WindowError"));
        WindowError->resize(479, 268);
        buttonApplicationExit = new QPushButton(WindowError);
        buttonApplicationExit->setObjectName(QStringLiteral("buttonApplicationExit"));
        buttonApplicationExit->setEnabled(true);
        buttonApplicationExit->setGeometry(QRect(140, 200, 161, 41));
        labelErrorMessage = new QLabel(WindowError);
        labelErrorMessage->setObjectName(QStringLiteral("labelErrorMessage"));
        labelErrorMessage->setGeometry(QRect(40, 30, 201, 71));

        retranslateUi(WindowError);

        QMetaObject::connectSlotsByName(WindowError);
    } // setupUi

    void retranslateUi(QWidget *WindowError)
    {
        WindowError->setWindowTitle(QApplication::translate("WindowError", "Form", 0));
        buttonApplicationExit->setText(QApplication::translate("WindowError", "\320\222\321\213\320\271\321\202\320\270", 0));
        labelErrorMessage->setText(QApplication::translate("WindowError", "\320\232\321\200\320\270\321\202\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\276\320\261\320\270\321\210\320\272\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class WindowError: public Ui_WindowError {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWERROR_H
