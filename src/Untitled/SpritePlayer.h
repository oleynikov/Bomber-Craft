#ifndef SPRITEPLAYER_H
#define SPRITEPLAYER_H

#include "ASprite.h"
#include "AConfigurable.h"

class SpritePlayer : public ASprite , public AConfigurable
{

    public:
        SpritePlayer()
        {

        }
        SpritePlayer(AMaterial* material, AConfiguration* configuration)
        {

            this->configuration = configuration;
            int gridSize = this->configuration->getParameter("MAP_TILE_SIZE").toInt();

            QPainterPath shape;
            shape.addRect(0,0,gridSize,gridSize);

            this->setShape(shape);
            this->setMaterial(material);

        }

};

#endif // SPRITEPLAYER_H
