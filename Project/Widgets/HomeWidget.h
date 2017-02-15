//
// Created by song on 4/1/16.
//

#ifndef PROGECT_HOMEWIDGET_H
#define PROGECT_HOMEWIDGET_H

#include <QWidget>
#include <QtWidgets/QGraphicsWidget>
#include "ImageButton.h"
#include "StateItem.h"
#include "Thread/ProcessThread.h"
#include <QGraphicsTextItem>
#include "Graphics/Circle.h"
#include <QtWidgets/QGraphicsScene>
#include "Graphics/CircleGroup.h"
#include "Graphics/TangleGroup.h"

#include "Graphics/NumCircle.h"
class HomeWidget: public QWidget
{
Q_OBJECT
protected:
    virtual void timerEvent(QTimerEvent *event) override;

protected :
//    virtual void timerEvent(QTimerEvent *event) override;


public:
    HomeWidget(QWidget *parent = 0);

public slots:
    void setconfirm(int);
private:
    int rotation;
    double pointangle;
    ImageButton *button;
    QGraphicsWidget *graphicsWidget;
    QGraphicsWidget *greenWidget;
    QGraphicsWidget *redWidget;
    StateItem *stateItem;
    QGraphicsEllipseItem *item;
    SysConfig sysConfig;
    ImageButton *greenItem;
    ImageButton *redItem;
    int state;
    QGraphicsTextItem *videonum;
    QGraphicsTextItem *time;
    QGraphicsTextItem *firenum;
    ProcessThread* processThread;
    ImageButton *clickButton;
    CircleGroup *circleGroup;
    TangleGroup *tangleGroup;
    NumCircle* numCircle;
    NumCircle* checkCircle;


    int fireNum;
protected slots:
    void animal1();
    void test();
    void finish();
    void onClick();
    void busy();
    void idle();
    void setFirNum(int);
signals:
    void endThread();
};
#endif //PROGECT_HOMEWIDGET_H
