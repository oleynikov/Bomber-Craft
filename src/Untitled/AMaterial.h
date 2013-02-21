#ifndef AMATERIAL_H
#define AMATERIAL_H

#include "ATexture.h"

enum MaterialType
{

    MATERIAL_STONE,
    MATERIAL_WOOD,
    MATERIAL_PLAYER

};

class AMaterial
{

    public:
                    AMaterial
                    (
                        QString textureFile = "",
                        int hp = 0
                    )
                    :   texture(NULL),
                        hp(hp)
        {

            QPixmap* pixmap = new QPixmap();

            //  Handling pixmap load failure
            if ( ! pixmap->load(":/resources/textures/" + textureFile) )
                throw "MateriaCreationFailure";

            this->texture = new ATexture(pixmap);

        }

                    ~AMaterial()
        {

            if (this->texture)
            {

                delete this->texture;

            }

        }

        int         getHp(void) const
        {

            return this->hp;

        }

        ATexture*   getTexture(void) const
        {

            return this->texture;

        }

    private:
        ATexture*   texture;
        int         hp;

};

#endif // AMATERIAL_H
