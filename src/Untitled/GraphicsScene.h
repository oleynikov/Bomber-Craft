#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include "AEventReciever.h"
#include "EventFilterMouse.h"

class GraphicsScene : public QGraphicsScene, public AEventReciever
{

    public:
        GraphicsScene()
        {

            this->filterAdd(new EventFilterMouse());

        }

};

#endif // GRAPHICSSCENE_H
