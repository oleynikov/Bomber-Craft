#ifndef CONFIGURATIONFATORY_H
#define CONFIGURATIONFATORY_H

#include "AFactory.h"
#include "AXmlFileParser.h"
#include "AConfiguration.h"

class ConfigurationFactory : public AFactory<QString,AConfiguration*> , public AXmlFileParser
{

    public:
        virtual bool        make(void)
        {

            bool success = this->parse();
            this->product = &this->configuration;

            return success;

        }

    protected:
        virtual bool        configure(void)
        {

            this->configuration = new AConfiguration();

            this->setFilePath(this->feedstock);
            this->setNodeName("parameter");

            return true;

        }
        virtual void        parseNode(QXmlStreamReader& xmlReader)
        {

            QString parameterName = xmlReader.attributes().value("name").toString();
            QString parameterValue = xmlReader.attributes().value("value").toString();

            this->configuration->setParameter(parameterName,parameterValue);

        }

    private:
        AConfiguration*     configuration;
};

#endif // CONFIGURATIONFATORY_H
