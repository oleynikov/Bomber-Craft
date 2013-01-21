#ifndef AEVENTRECIEVER_H
#define AEVENTRECIEVER_H

#include <QObject>
#include "AEventFilter.h"

#include <QDebug>

class AEventReciever : virtual public QObject
{

    Q_OBJECT

    public:
                        AEventReciever(void)
        {

            this->installEventFilter(this);

        }
        void            filterAdd(AEventFilter* filter)
        {

            if (!this->filters.contains(filter))
            {

                this->filters.push_back(filter);

            }

        }
        void            filterRemove(AEventFilter* filter)
        {

            this->filters.removeOne(filter);

        }

    protected:
        virtual bool    eventFilter(QObject* watched, QEvent* event)
        {

            if (watched == this && this->filterPassed(event))
            {

                this->eventPassed(event);

            }

            return false;

        }
        virtual void    eventPassed(QEvent* event)
        {

        }
        bool            filterPassed(QEvent* event)
        {

            FilterItr filterItr;
            bool passed = true;

            for (filterItr=this->filters.begin() ; filterItr!=this->filters.end() ; filterItr++)
            {

                AEventFilter* filter = *filterItr;

                if (!filter->pass(event))
                {

                    passed = false;
                    break;

                }

            }

            return passed;

        }
        Filters         filters;

};

#endif // AEVENTRECIEVER_H
