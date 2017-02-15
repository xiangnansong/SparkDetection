//
// Created by song on 5/19/16.
//

#ifndef GRAPHICS_1_CIRCLE_H
#define GRAPHICS_1_CIRCLE_H

#include <QGraphicsObject>
class Circle: public QGraphicsObject
{
public:

    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    Circle(QGraphicsItem *parent = 0, const QSizeF &size = QSizeF(96, 96), const QColor &color = QColor("#50BAEE"));
    QSizeF size;
    QColor color;
    void setColor(QColor);
};


#endif //GRAPHICS_1_CIRCLE_H
