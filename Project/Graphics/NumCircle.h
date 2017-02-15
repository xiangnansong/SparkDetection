//
// Created by song on 5/30/16.
//

#ifndef PROJECT_NUMCIRCLE_H
#define PROJECT_NUMCIRCLE_H

#include <QGraphicsItemGroup>
#include <QGraphicsTextItem>
#include "Circle.h"
class NumCircle: public QObject, public QGraphicsItemGroup
{
Q_OBJECT

public:
    NumCircle(QObject *parent = 0, QGraphicsItem *parent1 = 0);
    int num;
    Circle *circle;
    QColor color;
    QGraphicsTextItem *textItem;

    void setCircleColor(QColor);
    void setTextColor(QColor);

    void setNum(int);
private:
    virtual QRectF boundingRect() const override;
};
#endif //PROJECT_NUMCIRCLE_H
