//
// Created by song on 5/30/16.
//

#include <QtGui/QTextBlockFormat>
#include "NumCircle.h"
#include <QTextCursor>

NumCircle::NumCircle(QObject *parent, QGraphicsItem *parent1)
    : QObject(parent), QGraphicsItemGroup(parent1)
{
    num = 0;
    circle = new Circle;
    color = circle->color;
    QString string;
    string.setNum(num);
    textItem = new QGraphicsTextItem;
    addToGroup(circle);
    addToGroup(textItem);
    textItem->setDefaultTextColor(QColor("#4F5961"));

    circle->setPos(0, 0);
    textItem->setPos(0, 0);

    textItem->setPlainText(string);

    textItem->setScale(3);
    QRectF rectF = textItem->boundingRect();
    textItem->setPos(rectF.width() * (-3) / 2, rectF.height() * (-3) / 2);

}
QRectF NumCircle::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(-40 - penWidth / 2, -40 - penWidth / 2,
                  80 + penWidth, 80 + penWidth);
}
void NumCircle::setCircleColor(QColor qColor)
{
    circle->setColor(qColor);
}
void NumCircle::setTextColor(QColor qColor)
{
    textItem->setDefaultTextColor(qColor);
}
void NumCircle::setNum(int num)
{
    QString string;
    if (num < 1000)
        string.setNum(num);
    else
        string="...";
    textItem->setPlainText(string);
}









