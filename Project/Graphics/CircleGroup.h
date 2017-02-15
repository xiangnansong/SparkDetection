//
// Created by song on 5/13/16.
//

#ifndef GRAPHICS_1_CIRCLEGROUP_H
#define GRAPHICS_1_CIRCLEGROUP_H

#include <QGraphicsItemGroup>
#include <QObject>
#include "Point.h"
class CircleGroup: public QObject, public QGraphicsItemGroup
{
Q_OBJECT
public:
    typedef enum
    {
        busy_s,
        idle_s
    } Status;
    Status status;
    virtual QRectF boundingRect() const override;
    CircleGroup(QGraphicsItemGroup *parent = 0,Status status =busy_s);
    QPointF angleTrans(double angle);
    QPointF circlePoint(double angle);
    QList<Point *> list;
public slots:
    void busy();
    void idle();
};


#endif //GRAPHICS_1_CIRCLEGROUP_H
