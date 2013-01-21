#ifndef CONFIGURATIONFATORY_H
#define CONFIGURATIONFATORY_H

#include <QFile>
#include <QXmlStreamReader>
#include "AConfiguration.h"
#include "AConfigurable.h"
#include "AXmlFileParser.h"
#include "AFactory.h"

class ConfigurationFactory : public AFactory<QString,AConfiguration*> , public AXmlFileParser, public AConfigurable
{

    public:
        virtual AConfiguration* make(void)
        {

            this->parse();

            return this->configuration;

        }

    protected:
        virtual bool            configure(void)
        {

            this->configuration = new AConfiguration();
            this->setFilePath(this->feedstock);
            this->setNodeName("parameter");

            return true;

        }
        virtual void            parseNode(QXmlStreamReader& xmlReader)
        {

            QString parameterName = xmlReader.attributes().value("name").toString();
            QString parameterValue = xmlReader.attributes().value("value").toString();

            configuration->setParameter(parameterName,parameterValue);

        }

};

#endif // CONFIGURATIONFATORY_H
