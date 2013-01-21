#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ui_WindowMain.h>
#include "GraphicsScene.h"
#include "GraphicsView.h"
#include "AMap.h"

#include <QDebug>

class MainWindow : public QMainWindow
{

    Q_OBJECT
    
    public:
        explicit            MainWindow(QWidget *parent = 0) : QMainWindow(parent)
        {

            this->ui.setupUi(this);

            this->graphicsView = new GraphicsView();
            this->graphicsView->setParent(ui.centralWidget);
            this->graphicsView->setScene(&this->graphicsScene);
            this->graphicsView->setSceneRect(0,0,640,480);

            AMap map;
            map.setFilePath("maps/001.map");
            map.parse();
            map.show(this->graphicsScene);

        }
                           ~MainWindow()
        {


        }

    private:
        Ui::WindowMain      ui;
        GraphicsScene       graphicsScene;
        GraphicsView*       graphicsView;

    private slots:
        void                newEvent(QEvent* event)
        {

            qDebug() << event->type();

        }

};

#endif // MAINWINDOW_H
