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

#include <QDebug>

typedef QList<ASprite*>         SpriteList;
typedef SpriteList::Iterator    SpriteListItr;


class Map : public SpriteList , public AXmlFileParser , public AConfigurable
{

    public:
                            Map(QString filePath = "")
        {

            this->setFilePath(filePath);

        }
        void                show(QGraphicsScene& scene)
        {

            SpriteListItr spriteItr = this->begin();

            for (spriteItr ; spriteItr != this->end() ; spriteItr++)
            {

                qDebug() << (*spriteItr)->x()  << " " << (*spriteItr)->y();

                scene.addItem(*spriteItr);

            }

        }
        bool                pointBelongsToMap(QPointF point)
        {

            if  (

                    point.x() < 0
                        ||
                    point.y() < 0
                        ||
                    point.x() > 640
                        ||
                    point.y() > 480

                 )
            {

                return false;

            }

            return true;

        }
        bool                pointIsPassable(QPointF point)
        {

            /*

                Checkign if the point belongs to the map

            */

            if (!this->pointBelongsToMap(point))
            {

                return false;

            }





            /*

                Checking if the point is passable


            */

            SpriteListItr spriteItr = this->begin();

            for (spriteItr ; spriteItr != this->end() ; spriteItr++)
            {

                ASprite* sprite = *spriteItr;

                if (sprite->scenePos() == point && !sprite->getPassable())
                {

                    return false;

                }

            }

            return true;

        }

    protected:
        virtual bool        configure(void)
        {

            ConfigurationFactory configurationFactory;
            configurationFactory.setup("configuration/game.config");

            if(configurationFactory.make())
            {

                this->configuration = *configurationFactory.getProduct();
                this->setNodeName("brick");
                return true;

            }

            return false;

        }
        virtual void        parseNode(QXmlStreamReader& xmlReader)
        {

            int brickX = xmlReader.attributes().value("x").toString().toInt();
            int brickY = xmlReader.attributes().value("y").toString().toInt();
            int brickMaterial = xmlReader.attributes().value("material").toString().toInt();

            MaterialFactory materialFactory;
            materialFactory.setup((MaterialType)brickMaterial);

            if(materialFactory.make())
            {

                AMaterial* material = *(materialFactory.getProduct());
                SpriteBrick* brick = new SpriteBrick(material,this->configuration);

                int gridSize = this->configuration->getParameter("GRID_SIZE").toInt();
                brick->setPos(gridSize*brickX,gridSize*brickY);

                this->push_back(brick);

            }

        }

    private:
        QString             mapFilePath;

};

#endif // MAP_H
