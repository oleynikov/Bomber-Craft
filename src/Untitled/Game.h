#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "AConfigurable.h"
#include "GraphicsScene.h"
#include "Map.h"
#include "SpritePlayer.h"
#include "MaterialManager.h"

#include <QDebug>

class Game : public QObject , public AConfigurable
{

    Q_OBJECT

    public:
                                Game(void)
                                    :   AConfigurable("configuration/game.config")
        {

            this->materialManager = new MaterialManager();

            this->map = new Map();

        }
        void                    mapLoad(const QString mapId)
        {

            this->map->setFilePath("maps/" + mapId + ".map");
            this->map->setMaterialManager(this->materialManager);
            this->map->parse();
            this->map->show(this->graphicsScene);

            qreal mapWidth = this->map->getParameter("width").toInt();
            qreal mapHeight = this->map->getParameter("height").toInt();

            this->graphicsScene.setSceneRect(0,0,mapWidth,mapHeight);

        }
        GraphicsScene&          getScene(void)const
        {

            return this->graphicsScene;

        }

    public slots:
        void                    keyPress(int keyCode)
        {

            switch (keyCode)
            {
/*
                case Qt::Key_Up:    this->playerMove(QPoint(0,-1)); break;
                case Qt::Key_Right: this->playerMove(QPoint(1,0)); break;
                case Qt::Key_Down:  this->playerMove(QPoint(0,1)); break;
                case Qt::Key_Left:  this->playerMove(QPoint(-1,0)); break;
                default:            break;
*/
            }

        }

    private:
        MaterialManager*        materialManager;
        Map*                    map;
        mutable GraphicsScene   graphicsScene;

};

#endif // GAME_H
