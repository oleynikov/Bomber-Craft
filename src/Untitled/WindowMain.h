#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ui_WindowMain.h>
#include "GraphicsScene.h"
#include "AMap.h"

#include <QDebug>

class MainWindow : public QMainWindow
{

    Q_OBJECT
    
    public:
        explicit            MainWindow(QWidget *parent = 0) : QMainWindow(parent)
        {

            this->ui.setupUi(this);
            this->ui.graphicsView->setScene(&this->scene);

            AMap map;
            map.setFilePath("maps/001.map");
            map.parse();
            map.show(this->scene);

            QObject::connect(&this->scene,SIGNAL(newEvent(QEvent*)),this,SLOT(newEvent(QEvent*)));

        }
                           ~MainWindow()
        {


        }

    private:
        Ui::WindowMain      ui;
        GraphicsScene       scene;

    private slots:
        void                newEvent(QEvent* event)
        {

            qDebug() << event->type();

        }

};

#endif // MAINWINDOW_H
