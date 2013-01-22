#ifndef ACONFIGURABLE_H
#define ACONFIGURABLE_H

#include "AConfiguration.h"
#include "ConfigurationFactory.h"

class AConfigurable
{

    public:
                                AConfigurable(QString configurationFile = "")
        {

            if (configurationFile != "")
            {

                this->loadConfiguration(configurationFile);

            }

        }
                                ~AConfigurable(void)
        {

            if(this->configuration)
            {

                delete this->configuration;

            }

        }
        void                    loadConfiguration(QString configurationFile)
        {

            //  Creating and configuring conf. factory
            ConfigurationFactory configurationFactory;
            configurationFactory.setup(configurationFile);

            //  Saving new configuration
            this->setConfiguration(configurationFactory.make());

        }
        void                    setConfiguration(AConfiguration* configuration)
        {

            this->configuration = configuration;

        }
        AConfiguration*         getConfiguration(void) const
        {

            return this->configuration;

        }
        QVariant                getParameter(QString parameterId)
        {

            return this->configuration->getParameter(parameterId);

        }

    protected:
        mutable AConfiguration* configuration;

};

#endif // ACONFIGURABLE_H
