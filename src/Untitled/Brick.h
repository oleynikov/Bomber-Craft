#ifndef BRICK_H
#define BRICK_H

#include "ASprite.h"
#include "AConfigurable.h"

class Brick : public ASprite , public AConfigurable
{

    public:
        Brick()
        {

        }
        Brick(AMaterial* material, AConfiguration* configuration)
        {

            this->configuration = configuration;
            int gridSize = this->configuration->getParameter("GRID_SIZE").toInt();

            QPainterPath shape;
            shape.addRect(0,0,gridSize,gridSize);

            this->setShape(shape);
            this->setMaterial(material);

        }

};

#endif // BRICK_H
