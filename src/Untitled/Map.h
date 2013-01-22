#ifndef MAP_H
#define MAP_H

#include <QList>
#include <QFile>
#include <QXmlStreamReader>
#include <QGraphicsScene>
#include <QDebug>

#include "AXmlFileParser.h"
#include "MaterialFactory.h"
#include "ConfigurationFactory.h"
#include "SpriteBrick.h"

class Map : private QList<ASprite*> , public AXmlFileParser , public AConfigurable
{

    public:
                            Map(QString filePath = "")
        {

            this->setFilePath(filePath);

        }
        void                show(QGraphicsScene& scene)
        {

            while (!this->empty())
            {

                scene.addItem(this->last());
                this->pop_back();

            }

        }

    protected:
        virtual bool        configure(void)
        {

            ConfigurationFactory configurationFactory;
            configurationFactory.setup("configuration/game.config");
            this->configuration = configurationFactory.make();

            this->setNodeName("brick");

            return true;

        }
        virtual void        parseNode(QXmlStreamReader& xmlReader)
        {

            int brickX = xmlReader.attributes().value("x").toString().toInt();
            int brickY = xmlReader.attributes().value("y").toString().toInt();
            int brickMaterial = xmlReader.attributes().value("material").toString().toInt();

            MaterialFactory materialFactory;
            materialFactory.setup((MaterialType)brickMaterial);
            AMaterial* material = materialFactory.make();
            SpriteBrick* brick = new SpriteBrick(material,this->configuration);

            int gridSize = this->configuration->getParameter("GRID_SIZE").toInt();
            brick->setPos(gridSize*brickX,gridSize*brickY);

            this->push_back(brick);

        }

    private:
        QString             mapFilePath;

};

#endif // MAP_H
