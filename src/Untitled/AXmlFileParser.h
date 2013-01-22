#ifndef AXMLFILEPARSER_H
#define AXMLFILEPARSER_H

#include <QFile>
#include <QXmlStreamReader>

#include <QDebug>

class AXmlFileParser
{

    public:
                        AXmlFileParser(QString filePath = "")
        {

            this->setFilePath(filePath);

        }
        void            setFilePath(QString filePath)
        {

            this->xmlFilePath = filePath;

        }
        QString         getFilePath(void) const
        {

            return this->xmlFilePath;

        }
        void            setNodeName(QString nodeName)
        {

            this->nodeName = nodeName;

        }
        QString         getNodeName(void) const
        {

            return this->nodeName;

        }
        bool            parse(void)
        {


            if (this->configure() && this->parseDocument())
            {

                return true;

            }

            return false;

        }

    protected:
        virtual bool    configure(void)
        {

            return true;

        }
        virtual void    parseNode(QXmlStreamReader& xmlReader) = 0;

    private:
        bool            parseDocument(void)
        {

            QFile xmlFile(this->xmlFilePath);

            if (xmlFile.open(QIODevice::ReadOnly|QIODevice::Text))
            {

                QXmlStreamReader xmlReader(&xmlFile);

                while(!xmlReader.atEnd() && !xmlReader.hasError())
                {

                    if (xmlReader.readNext() == QXmlStreamReader::StartElement && this->nodeName == xmlReader.name())
                    {

                        this->parseNode(xmlReader);

                    }

                }

                xmlFile.close();
                xmlReader.clear();

                return true;

            }

            return false;

        }
        QString         xmlFilePath;
        QString         nodeName;

};

#endif // AXMLFILEPARSER_H
