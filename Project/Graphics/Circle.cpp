//
// Created by song on 5/19/16.
//

#include "Circle.h"
#include <QPainter>
#include <QBrush>
Circle::Circle(QGraphicsItem *parent, const QSizeF &size, const QColor &color)
    : QGraphicsObject(parent), size(size), color(color)
{

}

QRectF Circle::boundingRect() const
{
    float x = (float) (-1 * size.width() / 2);
    float y = (float) (-1 * size.height() / 2);
    return QRectF(x, y, size.width(), size.height());
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    float x = (float) (-1 * size.width() / 2);
    float y = (float) (-1 * size.height() / 2);
    painter->setRenderHint(QPainter::SmoothPixmapTransform);
    painter->setBrush(color);
    QPen pen;
    pen.setBrush(color);
    painter->setPen(pen);
    painter->drawEllipse((int) x, (int) y, (int) size.width(), (int) size.height());

}
void Circle::setColor(QColor qColor)
{
    color = qColor;
    update();
}



