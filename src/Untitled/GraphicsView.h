#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QKeyEvent>

#include <QDebug>

class GraphicsView : public QGraphicsView
{

    Q_OBJECT

    public:
        GraphicsView()
        {


        }

    protected:
        virtual void keyPressEvent(QKeyEvent* event)
        {

            emit this->keyPress(event->key());

        }

    signals:
        void keyPress(int);

};


#endif // GRAPHICSVIEW_H
