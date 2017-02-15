//
// Created by song on 5/24/16.
//

#include "PlayView.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDebug>
#include <QLabel>
PlayView::PlayView(Result result,QWidget *parent)
    : QWidget(parent),result(result)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsView *view = new QGraphicsView(this);
    view->setRenderHint(QPainter::Antialiasing);
    view->setScene(scene);
    setFixedSize(600,400);
    view->setSceneRect(rect());
    QImage image;
    image.load(result.picFilePath);
    image = image.scaled(600,400);
    view->setBackgroundBrush(QPixmap::fromImage(image));
    view->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
//    setFixedSize(400,300);
//    QImage image;
//    image.load("/home/song/Picture/1_0.png");
//    image = image.scaled(400,300);
//    QLabel *label
}

