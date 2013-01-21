#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include "AEventReciever.h"
#include "EventFilterMouse.h"

#include <QDebug>

class GraphicsScene : public QGraphicsScene , public AEventReciever
{

    public:
        GraphicsScene()
        {

            this->filterAdd(new EventFilterMouse());

        }

    protected:
        virtual void eventPassed(QEvent *event)
        {

            qDebug() << event->type();

        }

};

#endif // GRAPHICSSCENE_H
