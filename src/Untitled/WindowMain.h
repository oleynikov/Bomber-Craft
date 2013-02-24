#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ui_WindowMain.h>
#include <QApplication>
#include <QMainWindow>
#include <WindowError.h>
#include "GraphicsView.h"
#include "Game.h"

#include <QDebug>
#include <iostream>


class MainWindow : public QMainWindow
{

    Q_OBJECT
    
    public:
        explicit            MainWindow(QWidget *parent = 0) : QMainWindow(parent)
        {

            try
            {

                this->game = new Game();

            }
            catch(AXmlFileParser::XmlFileOpenFailure)
            {

                Ui::WindowError uiError;
                uiError.setupUi(this);
                return;

            }

            //  Setting GUI up
            this->ui.setupUi(this);

            //  Configuring graphics view
            this->display.setParent(ui.centralWidget);
            this->display.setScene(&this->game->getScene());

            QObject::connect(&this->display,SIGNAL(keyPress(int)),this->game,SLOT(keyPress(int)));

            //  Starting the game
            this->game->mapLoad("001");

        }
                           ~MainWindow()
        {

        }

    private:
        Ui::WindowMain      ui;
        Game*               game;
        GraphicsView        display;

};

#endif // MAINWINDOW_H
