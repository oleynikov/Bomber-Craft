#ifndef AMATERIAL_H
#define AMATERIAL_H

#include "ATexture.h"

enum MaterialType
{

    MATERIAL_STONE,
    MATERIAL_WOOD

};

class AMaterial
{

    public:
                    AMaterial(QString textureFile = "" , int hp = 0)
        {

            QPixmap* pixmap = new QPixmap(":/resources/textures/" + textureFile);
            ATexture* texture = new ATexture(pixmap);

            this->texture = texture;
            this->hp = hp;

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
