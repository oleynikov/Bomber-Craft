#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QKeyEvent>
#include "ASprite.h"

#include <QDebug>

class GraphicsScene : public QGraphicsScene
{

    public:
        GraphicsScene()
        {


        }
        bool tilePassable(QPointF point)
        {

            /*

                Checking map bounds

            */
            if (point.x() < 0 || point.y() < 0)
            {

                return false;

            }





            /*

                Checking tile passability

            */

            QGraphicsItem* item = this->itemAt(point);

            //  Empty tile = passable tile
            if(!item)
            {

                return true;

            }

            //  Passable tile
            ASprite* sprite = static_cast<ASprite*>(item);
            if(sprite->getPassable())
            {

                return true;

            }

            return false;

        }

};

#endif // GRAPHICSSCENE_H
