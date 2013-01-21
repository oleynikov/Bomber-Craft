#ifndef MATERIALMANAGER_H
#define MATERIALMANAGER_H

#include <QMap>
#include "AMaterial.h"
#include "MaterialFactory.h"

typedef QMap<MaterialType,AMaterial*>   Materials;
typedef Materials::Iterator             MaterialItr;

class MaterialManager
{

    public:
        AMaterial*      getMaterial(MaterialType materialType)
        {

            // Checking if the material is already created
            if (!this->materials.contains(materialType))
            {

                factory.setup(materialType);
                AMaterial* material = factory.make();
                this->materials.insert(materialType,material);
                return material;

            }

            return this->materials.find(materialType).value();

        }

    private:
        Materials       materials;
        MaterialFactory factory;

};

#endif // MATERIALMANAGER_H
