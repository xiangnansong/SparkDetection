//
// Created by song on 5/13/16.
//
#include <QPen>
#include "CircleGroup.h"
#include "Widgets/ImageButton.h"
#include <QAnimationGroup>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QDebug>
#include <math.h>
CircleGroup::CircleGroup(QGraphicsItemGroup *parent,Status status)
    : QGraphicsItemGroup(parent),status(status)
{

    QSequentialAnimationGroup *sequentialAnimationGroup = new QSequentialAnimationGroup(this);
    QParallelAnimationGroup *stretch = new QParallelAnimationGroup(this);

    QParallelAnimationGroup *parallelAnimationGroup = new QParallelAnimationGroup(this);
    QGraphicsRectItem *rectItem = new QGraphicsRectItem(-40, -40, 80, 80);
    QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem(-40, -40, 80, 80);
    //addToGroup(rectItem);
    ellipseItem->setPen(QPen(QColor("#FFFFFF")));
    //addToGroup(ellipseItem);



    for (int i = 0; i < 9; i++) {
        Point *point = new Point;
        list << point;
        addToGroup(point);
        point->setPos(angleTrans(-90 + i * 40));
        point->setTransformOriginPoint(circlePoint(-90 + i * 40));
        QPropertyAnimation *animation = new QPropertyAnimation(point, "rotation");
        animation->setDuration(5000);
        animation->setStartValue(0);
        animation->setEndValue(360);
        animation->setLoopCount(-1);
        animation->setEasingCurve(QEasingCurve::SineCurve);
        parallelAnimationGroup->addAnimation(animation);

//        QPropertyAnimation *animations = new QPropertyAnimation(point, "pos");
//        QPointF pointF;
//        pointF.setX(angleTrans(-90 + i * 40).x() / 2);
//        pointF.setY(angleTrans(-90 + i * 40).y() / 2);
//        animation->setDuration(3000);
//        animation->setStartValue(pointF);
//        animation->setEndValue(angleTrans(-90 + i * 40));
//        animation->setLoopCount(-1);
//        animation->setEasingCurve(QEasingCurve::SineCurve);
//        parallelAnimationGroup->addAnimation(animations);
    }
//    QPropertyAnimation *animation = new QPropertyAnimation(list[0], "pos");
//    QPointF pointF;
//    pointF.setX(angleTrans(-90).x()/2);
//    pointF.setY(angleTrans(-90).y()/2);
//    animation->setDuration(3000);
//    animation->setStartValue(pointF);
//    animation->setEndValue(QPointF(angleTrans(-90)));
//    animation->setLoopCount(-1);
//    animation->setEasingCurve(QEasingCurve::SineCurve);
//    parallelAnimationGroup->addAnimation(animation);
//
//    QPropertyAnimation *animation1 = new QPropertyAnimation(list[1], "pos");
//    QPointF pointF1;
//    pointF1.setX(angleTrans(-50).x()/2);
//    pointF1.setY(angleTrans(-50).y()/2);
//    animation1->setDuration(3000);
//    animation1->setStartValue(pointF1);
//    animation1->setEndValue(QPointF(angleTrans(-50)));
//    animation1->setLoopCount(-1);
//    animation1->setEasingCurve(QEasingCurve::SineCurve);
//    parallelAnimationGroup->addAnimation(animation1);
//
//    QPropertyAnimation *animation2 = new QPropertyAnimation(list[2], "pos");
//    QPointF pointF2;
//    pointF1.setX(angleTrans(-50).x()/2);
//    pointF1.setY(angleTrans(-50).y()/2);
//    animation1->setDuration(3000);
//    animation1->setStartValue(pointF1);
//    animation1->setEndValue(QPointF(angleTrans(-50)));
//    animation1->setLoopCount(-1);
//    animation1->setEasingCurve(QEasingCurve::SineCurve);
//    parallelAnimationGroup->addAnimation(animation1);

    for (int j = 0; j < list.size(); j++) {
        QPropertyAnimation *animation = new QPropertyAnimation(list[j], "pos");
        QPointF pointF;
        pointF.setX(angleTrans(-90 + j * 40).x() * 0.8);
        pointF.setY(angleTrans(-90 + j * 40).y() * 0.8);
        animation->setDuration(2500);
        animation->setStartValue(pointF);
        animation->setEndValue(QPointF(angleTrans(-90 + j * 40)));
        animation->setLoopCount(-1);
        animation->setEasingCurve(QEasingCurve::SineCurve);
        parallelAnimationGroup->addAnimation(animation);
    }


    parallelAnimationGroup->start();
//    point->setTransformOriginPoint(0, 40);
//    QPropertyAnimation *animation = new QPropertyAnimation(point, "rotation");
//    animation->setDuration(3000);
//    animation->setStartValue(0);
//    animation->setEndValue(360);
//    animation->setLoopCount(-1);
//    animation->setEasingCurve(QEasingCurve::BezierSpline);
//    animation->start();
}

QRectF CircleGroup::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(-40 - penWidth / 2, -40 - penWidth / 2,
                  80 + penWidth, 80 + penWidth);
}
QPointF CircleGroup::angleTrans(double angle)
{
    angle = (angle * 3.1415926) / 180;
    double x = (double) cos(angle) * 40;
    double y = (double) sin(angle) * 40;
    QPointF pointF(x, y);
    qDebug() << pointF;
    return pointF;
}
QPointF CircleGroup::circlePoint(double angle)
{
    angle = (angle * 3.1415926) / 180;
    double x = (double) cos(angle) * 40;
    double y = (double) sin(angle) * 40;
    QPointF pointF(-1 * x, -1 * y);
    qDebug() << pointF;
    return pointF;
}
void CircleGroup::busy()
{
    if(status==idle_s) {
        QParallelAnimationGroup *parallelAnimationGroup = new QParallelAnimationGroup(this);
        for (int i = 0; i < list.size(); i++) {
            QPropertyAnimation *animation = new QPropertyAnimation(list[i], "opacity");
            animation->setDuration(1000);
            animation->setStartValue(0);
            animation->setEndValue(1);
            parallelAnimationGroup->addAnimation(animation);
        }
        parallelAnimationGroup->start();
    }
    status=busy_s;

}
void CircleGroup::idle()
{
    if(status==busy_s) {
        QParallelAnimationGroup *parallelAnimationGroup = new QParallelAnimationGroup(this);
        for (int i = 0; i < list.size(); i++) {
            QPropertyAnimation *animation = new QPropertyAnimation(list[i], "opacity");
            animation->setDuration(1000);
            animation->setStartValue(1);
            animation->setEndValue(0);
            parallelAnimationGroup->addAnimation(animation);
        }
        parallelAnimationGroup->start();
    }
    status=idle_s;
}









