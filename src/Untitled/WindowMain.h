#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ui_WindowMain.h>
#include "GraphicsView.h"
#include "Game.h"

#include <QDebug>
#include <SpritePlayer.h>

class MainWindow : public QMainWindow
{

    Q_OBJECT
    
    public:
        explicit            MainWindow(QWidget *parent = 0) : QMainWindow(parent)
        {

            // Sutting GUI up
            this->ui.setupUi(this);

            //  Configuring graphics view
            this->display.setParent(ui.centralWidget);
            this->display.setScene(&this->game.getScene());
            this->display.setSceneRect(0,0,640,480);
            QObject::connect(&this->display,SIGNAL(keyPress(int)),&this->game,SLOT(keyPress(int)));

            //  Starting the game
            this->game.mapLoad("001");

        /*
            ConfigurationFactory configurationFactory;
            configurationFactory.setup("configuration/game.config");

            MaterialFactory materialFactory;
            materialFactory.setup(MATERIAL_PLAYER);
            AMaterial* material = materialFactory.make();
            SpritePlayer* player = new SpritePlayer(material,configurationFactory.make());

            this->graphicsScene.addItem(player);
*/
        }
                           ~MainWindow()
        {


        }

    private:
        Ui::WindowMain      ui;
        Game                game;
        GraphicsView        display;

    private slots:
        void                newEvent(QEvent* event)
        {

            qDebug() << event->type();

        }

};

#endif // MAINWINDOW_H
