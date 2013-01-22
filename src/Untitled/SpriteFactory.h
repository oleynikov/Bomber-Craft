#ifndef SPRITEFACTORY_H
#define SPRITEFACTORY_H

#include "AFactory.h"
#include "AMaterial.h"
#include "ASprite.h"

class SpriteFactory : public AFactory<AMaterial*,ASprite*>
{

    public:
        virtual ASprite* make(void)
        {

            ASprite* sprite;

            switch (this->feedstock)
            {

                case MATERIAL_STONE: material = new AMaterial("brick.jpg",100); break;
                case MATERIAL_WOOD: material = new AMaterial("wood.jpg",50); break;
                case MATERIAL_PLAYER: material = new AMaterial("player.jpg",50); break;

            }

            return material;

        }

};

#endif // SPRITEFACTORY_H
