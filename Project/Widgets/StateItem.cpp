//
// Created by song on 4/2/16.
//

#include "StateItem.h"
#include <QPainter>

StateItem::StateItem(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{

}

QRectF StateItem::boundingRect() const
{
    return QRectF(-48, -48, 96, 96);
}

void StateItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawEllipse(0, 0, 96, 96);
}

void StateItem::timerEvent(QTimerEvent *event)
{
    QObject::timerEvent(event);
}




