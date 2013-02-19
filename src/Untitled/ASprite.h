#ifndef ASPRITE_H
#define ASPRITE_H

#include <QGraphicsItem>
#include <QPainterPath>
#include <QPainter>
#include "AMaterial.h"

class ASprite : public QGraphicsItem
{

    public:
                        ASprite() : passable(false)
        {



        }
                        ASprite(QPainterPath shape,AMaterial* material) : passable(false)
        {

            this->setShape(shape);
            this->setMaterial(material);

        }
        virtual QRectF  boundingRect() const
        {

            return this->getShape().boundingRect();

        }
        virtual void    paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
        {

            QPen painterPen;
            painterPen.setStyle(Qt::NoPen);

            QBrush painterBrush;
            ATexture* texture = this->getMaterial()->getTexture();
            QPixmap pixmap = *texture->getPixmap();

            if (texture->getType() == A_TEXTURE_TYPE_STRETCH)
            {

                pixmap = pixmap.scaled(this->boundingRect().size().toSize());

            }

            painterBrush.setTexture(pixmap);

            painter->setBrush(painterBrush);
            painter->setPen(painterPen);

            painter->drawPath(this->getShape());

        }
        void            setShape(QPainterPath shape)
        {

            this->shape = shape;

        }
        void            setMaterial(AMaterial* material)
        {

            this->material = material;

        }
        QPainterPath    getShape(void) const
        {

            return this->shape;

        }
        AMaterial*      getMaterial(void) const
        {

            return this->material;

        }
        bool            getPassable(void) const
        {

            return this->passable;

        }

    private:
        QPainterPath    shape;
        AMaterial*      material;
        bool            passable;

};

#endif // ASPRITE_H
