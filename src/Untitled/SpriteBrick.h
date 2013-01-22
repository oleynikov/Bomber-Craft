#ifndef SPRITEBRICK_H
#define SPRITEBRICK_H

#include "ASprite.h"
#include "AConfigurable.h"

class SpriteBrick : public ASprite , public AConfigurable
{

    public:
        SpriteBrick()
        {

        }
        SpriteBrick(AMaterial* material, AConfiguration* configuration)
        {

            this->configuration = configuration;
            int gridSize = this->configuration->getParameter("GRID_SIZE").toInt();

            QPainterPath shape;
            shape.addRect(0,0,gridSize,gridSize);

            this->setShape(shape);
            this->setMaterial(material);

        }

};

#endif // SPRITEBRICK_H
