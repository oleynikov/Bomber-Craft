#ifndef WINDOWERROR_H
#define WINDOWERROR_H

#include <QWidget>
#include <ui_WindowError.h>

class WindowError : public QWidget
{

public:
    WindowError(QWidget* parent = NULL) : QWidget(parent)
    {

        Ui::WindowError ui;
        ui.setupUi(this);

        //QObject::connect(ui.buttonApplicationExit,SIGNAL(clicked()),this,SLOT(applicationExit()));

    }

    public slots:
        void applicationExit();

};

#endif // WINDOWERROR_H
