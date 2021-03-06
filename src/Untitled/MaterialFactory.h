#ifndef MATERIALFACTORY_H
#define MATERIALFACTORY_H

#include "AFactory.h"
#include "AMaterial.h"

class MaterialFactory : public AFactory<MaterialType,AMaterial*>
{

    public:
        virtual bool make(void)
        {

            AMaterial* material = NULL;

            switch (this->feedstock)
            {

                case MATERIAL_STONE: material = new AMaterial("brick.jpg",100); break;
                case MATERIAL_WOOD: material = new AMaterial("wood.jpg",50); break;
                case MATERIAL_PLAYER: material = new AMaterial("player.jpg",50); break;

            }

            this->product = &material;

            return material;

        }

};

#endif // MATERIALFACTORY_H
