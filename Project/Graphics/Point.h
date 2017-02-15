//
// Created by song on 5/13/16.
//

#ifndef GRAPHICS_1_POINT_H
#define GRAPHICS_1_POINT_H

#include <QGraphicsObject>
class Point: public QGraphicsObject
{

public:
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    Point(QGraphicsItem *parent = 0);
};


#endif //GRAPHICS_1_POINT_H
