#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include "AEventReciever.h"
#include "EventFilterMouse.h"

#include <QDebug>

class GraphicsView : public QGraphicsView
{

    public:
        GraphicsView()
        {


        }

    protected:
        virtual void keyPressEvent(QKeyEvent *event)
        {

            qDebug() << "qwe";

        }



};


#endif // GRAPHICSVIEW_H
