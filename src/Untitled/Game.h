#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "AConfigurable.h"
#include "GraphicsScene.h"
#include "Map.h"
#include "SpritePlayer.h"

#include <QDebug>

class Game : public QObject , public AConfigurable
{

    Q_OBJECT

    public:
                                Game(void)
        {

            //  Configuration loaded successfully
                                    this->loadConfiguration("qwe");

                                    /*if (this->loadConfiguration("configuration/game.config"))
            {

                this->player = this->playerCreate();
                this->graphicsScene.addItem(this->player);

            }*/

        }
        void                    mapLoad(const QString mapId)
        {

            this->map.setFilePath("maps/" + mapId + ".map");
            this->map.parse();
            this->map.show(this->graphicsScene);

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

                case Qt::Key_Up:    this->playerMove(QPoint(0,-1)); break;
                case Qt::Key_Right: this->playerMove(QPoint(1,0)); break;
                case Qt::Key_Down:  this->playerMove(QPoint(0,1)); break;
                case Qt::Key_Left:  this->playerMove(QPoint(-1,0)); break;
                default:            break;

            }

        }

    private:
        SpritePlayer*           playerCreate(void)
        {

            SpritePlayer* player = NULL;

            this->materialFactory.setup(MATERIAL_PLAYER);

            if(materialFactory.make())
            {

                AMaterial* material = *materialFactory.getProduct();
                player = new SpritePlayer(material,this->configuration);

            }

            return player;

        }
        bool                    playerMove(QPoint delta)
        {

            int tileSize = this->configuration->getParameter("MAP_TILE_SIZE").toInt();
            QPointF positionNew = this->player->pos() + delta * tileSize;

            if(this->map.pointIsPassable(positionNew))
            {

                this->player->moveBy(tileSize*delta.x(),tileSize*delta.y());
                return true;

            }

            return false;

        }
        mutable GraphicsScene   graphicsScene;
        MaterialFactory         materialFactory;
        SpritePlayer*           player;
        Map                     map;

};

#endif // GAME_H
