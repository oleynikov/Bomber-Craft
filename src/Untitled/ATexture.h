#ifndef ATEXTURE_H
#define ATEXTURE_H

#include <QPixmap>

enum ATextureType
{

    A_TEXTURE_TYPE_REPEAT,
    A_TEXTURE_TYPE_STRETCH,
    A_TEXTURE_TYPE_COUNT

};

class ATexture
{

    public:
                        ATexture
                        (
                            QPixmap* pixmap,
                            ATextureType type = A_TEXTURE_TYPE_STRETCH
                        )
        {

            this->pixmap = pixmap;
            this->type = type;

        }

        QPixmap*        getPixmap(void) const
        {

            return this->pixmap;

        }

        ATextureType    getType(void) const
        {

            return this->type;

        }

    private:
        QPixmap*        pixmap;
        ATextureType    type;

};

#endif // ATEXTURE_H
