//
// Created by song on 4/2/16.
//

#ifndef PROGECT_STATEITEM_H
#define PROGECT_STATEITEM_H

#include <QGraphicsObject>


class StateItem: public QGraphicsObject
{

public:

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    virtual QRectF boundingRect() const override;
    StateItem(QGraphicsItem *parent = 0);
protected:
    virtual void timerEvent(QTimerEvent *event) override;

};


#endif //PROGECT_STATEITEM_H
