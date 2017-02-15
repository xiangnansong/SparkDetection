//
// Created by song on 5/19/16.
//

#include "ItemT.h"
#include <QPainter>

ItemT::ItemT(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{

}

QRectF ItemT::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(-3 - penWidth / 2, -25 - penWidth / 2, 6 + penWidth, 50 + penWidth);
}

void ItemT::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::SmoothPixmapTransform);
    painter->setBrush(QColor("#FFD20D"));
    QPen pen;

    pen.setBrush(QColor("#FFD20D"));
    painter->setPen(pen);
    painter->drawRect(QRectF(-5, -25, 6, 50));
}

