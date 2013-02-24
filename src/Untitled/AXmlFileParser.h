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
        QString         getFilePath(void) const
        {

            return this->xmlFilePath;

        }
        void            setFilePath(QString filePath)
        {

            this->xmlFilePath = filePath;

        }
        bool            parse(void)
        {


            if (this->configure() && this->parseDocument())
            {

                return true;

            }

            return false;

        }
        class           XmlFileOpenFailure
        {

            public:
                XmlFileOpenFailure(QString fileName)
                    :   fileName(fileName)
                {

                }

                QString fileName;

        };

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

            if ( xmlFile.open(QIODevice::ReadOnly|QIODevice::Text) )
            {

                QXmlStreamReader xmlReader(&xmlFile);

                while(!xmlReader.atEnd() && !xmlReader.hasError())
                {

                    if (xmlReader.readNext() == QXmlStreamReader::StartElement)
                    {

                        this->parseNode(xmlReader);

                    }

                }

                xmlFile.close();
                xmlReader.clear();

                return true;

            }

            else
                throw XmlFileOpenFailure(this->xmlFilePath);

            return false;

        }
        QString         xmlFilePath;

};

#endif // AXMLFILEPARSER_H
