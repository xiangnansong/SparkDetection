//
// Created by song on 5/13/16.
//

#include <QtGui/QPen>
#include "Point.h"
#include <QPainter>
Point::Point(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{

}

QRectF Point::boundingRect() const
{
    return QRectF(-5.5, -5.5, 11, 11);
}

void Point::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    QPen pen(QColor("#5CAA15"));
    QBrush brush(QColor("#5CAA15"));
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(-5, -5, 10, 10);
}

