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
        bool tileIsInside(QPointF point)
        {

            if ( point.x() < 0 || point.y() < 0 )
            {

                return false;

            }

            return true;

        }

        bool tileIsEmpty(QPointF point)
        {

            QTransform transform;

            QGraphicsItem* item = this->itemAt(point.x(),point.y(),transform);

            //  Empty tile = passable tile
            if ( !item )
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

        bool tilePassable(QPointF point)
        {

            if ( this->tileIsInside(point) && this->tileIsEmpty(point) )
            {

                return true;

            }

            return false;

        }

};

#endif // GRAPHICSSCENE_H
