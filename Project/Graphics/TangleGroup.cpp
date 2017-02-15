//
// Created by song on 5/19/16.
//

#include "TangleGroup.h"
#include <QAnimationGroup>
#include <QPropertyAnimation>
#include <QDebug>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include "Circle.h"
TangleGroup::TangleGroup(QGraphicsItem *parent, Status status)
    : QGraphicsItemGroup(parent),status(status)
{

    qDebug()<<"stop_INIT";
    Circle *circle = new Circle;
    addToGroup(circle);
    circle->setPos(0, 0);


    for (int i = 0; i < 3; i++) {
        ItemT *itemT = new ItemT;
        list.append(itemT);
        addToGroup(itemT);
    }


    list[0]->setPos(-20, 0);
    list[1]->setPos(5, 13.5);
    list[2]->setPos(5, -13.5);
    list[1]->setRotation(-120);
    list[2]->setRotation(120);

}
QRectF TangleGroup::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(-40 - penWidth / 2, -40 - penWidth / 2,
                  80 + penWidth, 80 + penWidth);
}

void TangleGroup::inverse()
{
    if (status == start) {
        status = stop;
        qDebug()<<"stop_CHAN";
        QParallelAnimationGroup *parallelAnimationGroup = new QParallelAnimationGroup(this);
        QPropertyAnimation *animation1 = new QPropertyAnimation(list[2], "rotation");
        QPropertyAnimation *animation2 = new QPropertyAnimation(list[2], "pos");
        QPropertyAnimation *animation5 = new QPropertyAnimation(list[2], "scale");
        QPropertyAnimation *animation6 = new QPropertyAnimation(list[0], "opacity");
        QPropertyAnimation *animation3 = new QPropertyAnimation(list[1], "rotation");
        QPropertyAnimation *animation4 = new QPropertyAnimation(list[1], "pos");


        animation1->setDuration(1000);
        animation1->setStartValue(180);
        animation1->setEndValue(120);
        parallelAnimationGroup->addAnimation(animation1);

        animation2->setDuration(1000);
        animation2->setEndValue(QPointF(5, -13.5));
        animation2->setStartValue(QPointF(-13, 0));
        parallelAnimationGroup->addAnimation(animation2);

        animation3->setDuration(1000);
        animation3->setStartValue(-180);
        animation3->setEndValue(-120);


        parallelAnimationGroup->addAnimation(animation3);

        animation4->setDuration(1000);
        animation4->setEndValue(QPointF(5, 13.5));
        animation4->setStartValue(QPointF(13, 0));
        parallelAnimationGroup->addAnimation(animation4);
        animation5->setDuration(3000);
        animation5->setStartValue(1);
        animation5->setEndValue(0.5);
        animation5->setEasingCurve(QEasingCurve::SineCurve);
        parallelAnimationGroup->addAnimation(animation5);

        animation6->setDuration(1000);
        animation6->setStartValue(0);
        animation6->setEndValue(1);


        parallelAnimationGroup->addAnimation(animation6);

        parallelAnimationGroup->start();
    }
    else if (status == stop) {
        status = start;
        qDebug()<<"start_CH";
        startAnima();
    }

}
void TangleGroup::startAnima()
{
    QParallelAnimationGroup *parallelAnimationGroup = new QParallelAnimationGroup(this);
    QSequentialAnimationGroup *main = new QSequentialAnimationGroup(this);

    QPropertyAnimation *animation1 = new QPropertyAnimation(list[2], "rotation");
    QPropertyAnimation *animation2 = new QPropertyAnimation(list[2], "pos");
    QPropertyAnimation *animation5 = new QPropertyAnimation(list[2], "scale");
    QPropertyAnimation *animation6 = new QPropertyAnimation(list[0], "opacity");
    QPropertyAnimation *animation3 = new QPropertyAnimation(list[1], "rotation");
    QPropertyAnimation *animation4 = new QPropertyAnimation(list[1], "pos");


    animation1->setDuration(1000);
    animation1->setStartValue(120);
    animation1->setEndValue(180);
    parallelAnimationGroup->addAnimation(animation1);

    animation2->setDuration(1000);
    animation2->setStartValue(QPointF(5, -13.5));
    animation2->setEndValue(QPointF(-13, 0));
    parallelAnimationGroup->addAnimation(animation2);

    animation3->setDuration(1000);
    animation3->setStartValue(-120);
    animation3->setEndValue(-180);


    parallelAnimationGroup->addAnimation(animation3);

    animation4->setDuration(1000);
    animation4->setStartValue(QPointF(5, 13.5));
    animation4->setEndValue(QPointF(13, 0));
    parallelAnimationGroup->addAnimation(animation4);


    animation5->setDuration(3000);
    animation5->setStartValue(1);
    animation5->setEndValue(0.5);
    animation5->setEasingCurve(QEasingCurve::SineCurve);

    parallelAnimationGroup->addAnimation(animation5);

    animation6->setDuration(500);
    animation6->setStartValue(1);
    animation6->setEndValue(0);


    parallelAnimationGroup->addAnimation(animation6);

    parallelAnimationGroup->start();

}
Status TangleGroup::getStatus()
{
    return status;
}









