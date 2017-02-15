//
// Created by song on 5/19/16.
//

#ifndef GRAPHICS_1_ITEMT_H
#define GRAPHICS_1_ITEMT_H

#include <QGraphicsObject>
class ItemT: public QGraphicsObject
{

public:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    ItemT(QGraphicsItem *parent = 0);
};


#endif //GRAPHICS_1_ITEMT_H
