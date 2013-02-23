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

            for ( ; materialItr!=this->materials.end() ; materialItr++)
            {

                delete *materialItr;

            }

        }
        AMaterial*      getMaterial(MaterialType materialType)
        {

            // Checking if the material is already created
            if ( ! this->materials.contains(materialType) )
            {

                //  Configuring the factory and making a material
                factory.setup(materialType);
                factory.make();
                AMaterial* material = *factory.getProduct();

                //  Saving created material;
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
