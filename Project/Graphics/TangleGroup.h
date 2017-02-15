//
// Created by song on 5/19/16.
//

#ifndef GRAPHICS_1_TANGLEGROUP_H
#define GRAPHICS_1_TANGLEGROUP_H
#include <QGraphicsItemGroup>
#include "ItemT.h"
typedef enum
{
    start,
    stop
} Status;
class TangleGroup: public QObject, public QGraphicsItemGroup
{
Q_OBJECT

public:

    QList<ItemT *> list;
    Status getStatus();
    TangleGroup(QGraphicsItem *parent = 0, Status status = stop);
    void startAnima();
private:
    virtual QRectF boundingRect() const override;
    Status status;
public slots:
    void inverse();
};


#endif //GRAPHICS_1_TANGLEGROUP_H
