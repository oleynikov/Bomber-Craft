#ifndef MATERIALMANAGER_H
#define MATERIALMANAGER_H

#include <QMap>
#include "AMaterial.h"
#include "MaterialFactory.h"

#include <QDebug>
#include <iostream>

typedef QMap<MaterialType,AMaterial*>   Materials;
typedef Materials::Iterator             MaterialItr;

class MaterialManager
{

    public:
                        ~MaterialManager()
        {

            MaterialItr materialItr = this->materials.begin();

            std::cout << "qwe";

            for ( ; materialItr!=this->materials.end() ; materialItr++)
            {

                //delete (*materialItr)->value;
                std::cout << materialItr.key();

            }

        }
        AMaterial*      getMaterial(MaterialType materialType)
        {

            // Checking if the material is already created
            if (!this->materials.contains(materialType))
            {

                factory.setup(materialType);
                factory.make();
                AMaterial* material = *factory.getProduct();
                this->materials.insert(materialType,material);
                return material;

            }

            return this->materials.find(materialType).value();

        }

    private:
        Materials           materials;
        MaterialFactory     factory;

};

#endif // MATERIALMANAGER_H
