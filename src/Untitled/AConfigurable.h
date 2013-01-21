#ifndef ACONFIGURABLE_H
#define ACONFIGURABLE_H

#include "AConfiguration.h"

class AConfigurable
{

    public:
        void            setConfiguration(AConfiguration* configuration)
        {

            this->configuration = configuration;

        }
        QVariant        getParameter(QString parameterId)
        {

            return this->configuration->getParameter(parameterId);

        }

    protected:
        AConfiguration* configuration;

};

#endif // ACONFIGURABLE_H
