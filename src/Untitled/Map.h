#ifndef MAP_H
#define MAP_H

#include <QList>
#include <QFile>
#include <QXmlStreamReader>
#include <QGraphicsScene>
#include <QDebug>

#include "AXmlFileParser.h"
#include "ConfigurationFactory.h"
#include "MaterialManager.h"
#include "SpriteBrick.h"

#include <QDebug>

typedef QList<ASprite*>         SpriteList;
typedef SpriteList::Iterator    SpriteListItr;


class Map : public SpriteList , public AXmlFileParser , public AConfigurable
{

    public:
                            Map() : AConfigurable("configuration/map.config")
        {

        }
        void                show(QGraphicsScene& scene)
        {

            SpriteListItr spriteItr = this->begin();

            for ( ; spriteItr != this->end() ; spriteItr++)
            {

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

            for ( ; spriteItr != this->end() ; spriteItr++)
            {

                ASprite* sprite = *spriteItr;

                if (sprite->scenePos() == point && !sprite->getPassable())
                {

                    return false;

                }

            }

            return true;

        }
        void                setMaterialManager(MaterialManager* materialManager)
        {

            this->materialManager = materialManager;

        }

    protected:
        virtual bool        configure(void)
        {

            ConfigurationFactory configurationFactory;
            configurationFactory.setup("configuration/game.config");

            if(configurationFactory.make())
            {

                this->configuration = *configurationFactory.getProduct();
                return true;

            }

            return false;

        }
        virtual void        parseNode(QXmlStreamReader& xmlReader)
        {

            QString nodeName = xmlReader.name().toString();

            if ( nodeName == "brick" )
            {

                int brickX = xmlReader.attributes().value("x").toString().toInt();
                int brickY = xmlReader.attributes().value("y").toString().toInt();
                int brickMaterial = xmlReader.attributes().value("material").toString().toInt();

                MaterialType materialType = (MaterialType)brickMaterial;
                AMaterial* material = this->materialManager->getMaterial(materialType);
                SpriteBrick* brick = new SpriteBrick(material,this->configuration);

                int gridSize = this->configuration->getParameter("GRID_SIZE").toInt();
                brick->setPos(gridSize*brickX,gridSize*brickY);

                this->push_back(brick);

            }

            else if ( nodeName == "map" )
            {

                foreach ( QXmlStreamAttribute attribute , xmlReader.attributes() )
                {

                    QString attributeName = attribute.name().toString();
                    QString attributeValue = attribute.value().toString();

                    this->configuration->setParameter(attributeName,attributeValue);

                }

            }

        }

    private:
        MaterialManager*    materialManager;
        QString             mapFilePath;

};

#endif // MAP_H
