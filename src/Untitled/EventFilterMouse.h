#ifndef EVENTFILTERMOUSE_H
#define EVENTFILTERMOUSE_H

#include "AEventFilter.h"

class EventFilterMouse : public AEventFilter
{

    public:
        EventFilterMouse()
        {

            this->addEvent(QEvent::GraphicsSceneMouseMove);
            this->addEvent(QEvent::GraphicsSceneMousePress);
            this->addEvent(QEvent::GraphicsSceneMouseRelease);

        }

};

#endif // EVENTFILTERMOUSE_H
