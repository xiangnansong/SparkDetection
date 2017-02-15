//
// Created by song on 4/1/16.
//
#include "HomeWidget.h"
#include <QLabel>
#include <QGraphicsRectItem>
#include <QGraphicsWidget>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QPalette>
#include <QPropertyAnimation>
#include <QDebug>
#include <QTimer>
#include <QtCore/QDir>
#include <QFileInfoList>
#include "StateItem.h"
#include "SettingWidget.h"
HomeWidget::HomeWidget(QWidget *parent)
    : QWidget(parent)
{
//    statelabel = new QGraphicsTextItem("当前状态: ");
//    curstate = new QGraphicsTextItem("空闲");
//    videolabel = new QGraphicsTextItem("火花: ");
//    videonum = new QGraphicsTextItem("0");
//    time = new QGraphicsTextItem;
//    sysConfig = SettingWidget::config;
//    time->setPlainText(sysConfig.dateTime);
    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsView *view = new QGraphicsView(this);
    // qDebug() << rect();
    view->setSceneRect(0, 0, 800, 550);
    fireNum = 0;

    view->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
//    button = new ImageButton(":/pix/src/start.png", ":/pix/src/start.png", ":/pix/src/startP.png");
//    greenItem = new ImageButton(":/pix/src/green.png", ":/pix/src/green.png", ":/pix/src/green.png");
//    redItem = new ImageButton(":/pix/src/red.png", ":/pix/src/red.png", ":/pix/src/red.png");

//    greenWidget = (QGraphicsWidget *) scene->addWidget(greenItem);
//    redWidget = (QGraphicsWidget *) scene->addWidget(redItem);

//    graphicsWidget = (QGraphicsWidget *) scene->addWidget(button);
    QPalette *palette = new QPalette;
    palette->setBrush(QPalette::Window, QBrush(QColor(255, 0, 0, 0)));



//    graphicsWidget->setPalette(*palette);
//    greenWidget->setPalette(*palette);
//    redWidget->setPalette(*palette);
//    graphicsWidget->setPos(230, 100);

//    statelabel->setPos(170, 230);
//    statelabel->setScale(2);
//    curstate->setScale(2);
//    videonum->setScale(2);
//    videolabel->setScale(2);
//    curstate->setPos(300, 230);
//    videolabel->setPos(200, 300);
//    videonum->setPos(300, 305);
//    time->setPos(0, 450);
//    scene->addItem(statelabel);
//    scene->addItem(curstate);
//    scene->addItem(time);
//    scene->addItem(videonum);
//    scene->addItem(videolabel);
//    greenWidget->setPos(-100, -100);
//    redWidget->setPos(-100, -100);

    view->setStyleSheet("background: transparent");
    view->setScene(scene);

    view->setAlignment(Qt::AlignCenter | Qt::AlignTop);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setRenderHint(QPainter::Antialiasing);


    clickButton = new ImageButton(":/pix/src/trans.png", ":/pix/src/trans.png", ":/pix/src/trans.png");
    clickButton->setPalette(*palette);
    circleGroup = new CircleGroup;
    tangleGroup = new TangleGroup;
    time = new QGraphicsTextItem;
    firenum= new QGraphicsTextItem;
    QString fireStr;
    fireStr.setNum(10);
    firenum->setPlainText(fireStr);
    QGraphicsPixmapItem* firePic = new QGraphicsPixmapItem;
    QGraphicsPixmapItem* timePic = new QGraphicsPixmapItem;
    timePic->setPixmap(QPixmap(":/pix/src/time.png"));
    firePic->setPixmap(QPixmap(":/pix/src/fire.png"));
  //  scene->addItem(firenum);
    firenum->setScale(3);
    firenum->setDefaultTextColor(Qt::gray);
    //scene->addItem(firePic);
    scene->addItem(circleGroup);
    scene->addItem(tangleGroup);
    scene->addItem(time);
   // scene->addItem(timePic);

    timePic->setPos(200,400);
    time->setPos(0,530);

   // firePic->setPos(200,340);
    firenum->setPos(230,330);


    numCircle = new NumCircle;
    scene->addItem(numCircle);
    numCircle->setPos(200,400);
    numCircle->setCircleColor(QColor("#FFD20D"));
    numCircle->setScale(0.8);


    checkCircle = new NumCircle;
    scene->addItem(checkCircle);
    checkCircle->setPos(500,400);
    checkCircle->setCircleColor(QColor("#FFD20D"));
    checkCircle->setScale(0.8);


    QGraphicsTextItem* jiance = new QGraphicsTextItem;
    jiance->setPlainText("已检测");
    scene->addItem(jiance);
    jiance->setScale(1.2);
    jiance->setPos(200+jiance->boundingRect().width()*(-0.6),450);




    QGraphicsTextItem* queren = new QGraphicsTextItem;
    queren->setPlainText("已确认");
    scene->addItem(queren);
    queren->setScale(1.2);
    queren->setPos(500+queren->boundingRect().width()*(-0.6),450);






    QGraphicsWidget *graphicsWidget = (QGraphicsWidget *) scene->addWidget(clickButton);

    circleGroup->setPos(350, 200);
    circleGroup->setScale(1.5);
    tangleGroup->setPos(350, 200);
    graphicsWidget->setPos(350 - 48, 200 - 48);
    processThread = new ProcessThread(this);
    connect(clickButton, SIGNAL(clicked()), this, SLOT(onClick()));
    connect(clickButton, SIGNAL(clicked()), tangleGroup, SLOT(inverse()));
    connect(processThread,SIGNAL(busy()),circleGroup,SLOT(busy()),Qt::QueuedConnection);
    connect(processThread,SIGNAL(idle()),circleGroup,SLOT(idle()),Qt::QueuedConnection);
    connect(processThread,SIGNAL(setNum(int)),this,SLOT(setFirNum(int)));
    //  connect(this,SIGNAL(endThread()),processThread,SLOT(end()));
//    rotation = 0;
//    pointangle = 0;
//    connect(button, SIGNAL(clicked()), this, SLOT(animal1()));
    state = 1;
    startTimer(1000);

}
void HomeWidget::animal1()
{
    graphicsWidget->setTransformOriginPoint(48, 48);
    greenWidget->setTransformOriginPoint(0, 48);
    redWidget->setTransformOriginPoint(96, 48);
    if (state == 1) {
        QSequentialAnimationGroup *sequentialAnimationGroup = new QSequentialAnimationGroup(this);
        QParallelAnimationGroup *parallelAnimationGroup1 = new QParallelAnimationGroup(this);
        QParallelAnimationGroup *greenGroup = new QParallelAnimationGroup(this);
        QParallelAnimationGroup *redGroup = new QParallelAnimationGroup(this);

        QPropertyAnimation *animation = new QPropertyAnimation(graphicsWidget, "scale");
        QPropertyAnimation *animation1 = new QPropertyAnimation(graphicsWidget, "pos");
        QPropertyAnimation *animation2 = new QPropertyAnimation(graphicsWidget, "rotation");
        QPropertyAnimation *animation3 = new QPropertyAnimation(greenWidget, "pos");
        QPropertyAnimation *animation4 = new QPropertyAnimation(greenWidget, "opacity");

        QPropertyAnimation *animation5 = new QPropertyAnimation(redWidget, "pos");
        QPropertyAnimation *animation6 = new QPropertyAnimation(redWidget, "opacity");

        QPropertyAnimation *animation7 = new QPropertyAnimation(greenWidget, "scale");
        QPropertyAnimation *animation8 = new QPropertyAnimation(redWidget, "scale");

        QPropertyAnimation *animation9 = new QPropertyAnimation(greenWidget, "rotation");
        QPropertyAnimation *animation10 = new QPropertyAnimation(redWidget, "rotation");

        QParallelAnimationGroup *group = new QParallelAnimationGroup(this);
        animation->setDuration(1000);
        animation->setStartValue(1);
        animation->setEndValue(0.5);

        animation1->setDuration(1000);
        animation1->setStartValue(QPoint(230, 100));
        animation1->setEndValue(QPoint(450, -20));

        animation2->setDuration(1000);
        animation2->setStartValue(0);
        animation2->setEndValue(360);

        animation3->setDuration(500);
        animation3->setStartValue(QPoint(-50, 100));
        animation3->setEndValue(QPoint(250, 100));

        animation4->setDuration(1000);
        animation4->setStartValue(0);
        animation4->setEndValue(1);

        animation5->setDuration(500);
        animation5->setStartValue(QPoint(-150, 100));
        animation5->setEndValue(QPoint(250 - 96, 100));


        animation6->setDuration(1000);
        animation6->setStartValue(0);
        animation6->setEndValue(1);


        animation7->setDuration(2000);
        animation7->setStartValue(1);
        animation7->setEndValue(0.8);
        animation7->setLoopCount(-1);
        animation7->setEasingCurve(QEasingCurve::SineCurve);

        animation8->setDuration(2000);
        animation8->setStartValue(0.8);
        animation8->setEndValue(1);
        animation8->setLoopCount(-1);
        animation8->setEasingCurve(QEasingCurve::SineCurve);


        animation9->setDuration(2000);
        animation9->setStartValue(0);
        animation9->setEndValue(360);
        animation9->setLoopCount(-1);


        animation10->setDuration(2000);
        animation10->setStartValue(0);
        animation10->setEndValue(360);
        animation10->setLoopCount(-1);

        animation->setEasingCurve(QEasingCurve::Linear);
        group->addAnimation(animation);
        group->addAnimation(animation1);
        group->addAnimation(animation2);
        group->addAnimation(animation3);
        group->addAnimation(animation4);
        group->addAnimation(animation5);
        group->addAnimation(animation6);
        greenGroup->addAnimation(animation7);
        greenGroup->addAnimation(animation9);

        redGroup->addAnimation(animation8);
        redGroup->addAnimation(animation10);
        parallelAnimationGroup1->addAnimation(greenGroup);
        parallelAnimationGroup1->addAnimation(redGroup);
        sequentialAnimationGroup->addAnimation(group);
        sequentialAnimationGroup->addAnimation(parallelAnimationGroup1);
        sequentialAnimationGroup->start();
        state = 2;
        QDir dir("/home/song/Project/STITP/video/");
        QStringList filters;
        filters << "*.avi" << "*.mp4" << "*.rmvb";
        QFileInfoList fileInfoList = dir.entryInfoList(filters);
        qDebug() << fileInfoList.size();
        for (int i = 0; i < fileInfoList.size(); i++) {
            QFileInfo info = fileInfoList.at(i);
            qDebug() << info.absoluteFilePath();
//            ProcessThread *processThread = new ProcessThread(this, info.absoluteFilePath(), sysConfig);
            ProcessThread *processThread = new ProcessThread(this);
            processThread->start();
            connect(processThread, SIGNAL(processFinish()), this, SLOT(finish()));
        }
    }
    else if (state == 2) {
        QParallelAnimationGroup *parallelAnimationGroup1 = new QParallelAnimationGroup(this);
        QPropertyAnimation *animation = new QPropertyAnimation(graphicsWidget, "pos");
        QPropertyAnimation *animation1 = new QPropertyAnimation(graphicsWidget, "rotation");
        QPropertyAnimation *animation2 = new QPropertyAnimation(greenWidget, "opacity");
        QPropertyAnimation *animation3 = new QPropertyAnimation(redWidget, "opacity");
        QPropertyAnimation *animation4 = new QPropertyAnimation(graphicsWidget, "scale");

        animation4->setDuration(1000);
        animation4->setStartValue(0.5);
        animation4->setEndValue(1);

        animation->setDuration(1000);
        animation->setStartValue(QPoint(450, -20));
        animation->setEndValue(QPoint(230, 100));

        animation1->setDuration(1000);
        animation1->setStartValue(0);
        animation1->setEndValue(360);

        animation2->setDuration(500);
        animation2->setStartValue(1);
        animation2->setEndValue(0);

        animation3->setDuration(500);
        animation3->setStartValue(1);
        animation3->setEndValue(0);

        parallelAnimationGroup1->addAnimation(animation);
        parallelAnimationGroup1->addAnimation(animation1);
        parallelAnimationGroup1->addAnimation(animation2);
        parallelAnimationGroup1->addAnimation(animation3);
        parallelAnimationGroup1->addAnimation(animation4);
        parallelAnimationGroup1->start();


        state = 1;


    }
}
void HomeWidget::test()
{
    qDebug() << "start animal";

}

void HomeWidget::timerEvent(QTimerEvent *event)
{
//    sysConfig = SettingWidget::config;
//    time->setPlainText(sysConfig.dateTime);
//    qDebug() << sysConfig.dateTime << "home";
    QString date = QDateTime::currentDateTimeUtc().toString();
    time->setPlainText(date);


}
void HomeWidget::finish()
{
    qDebug() << "在这个由于中完成";
    QParallelAnimationGroup *parallelAnimationGroup1 = new QParallelAnimationGroup(this);
    QPropertyAnimation *animation = new QPropertyAnimation(graphicsWidget, "pos");
    QPropertyAnimation *animation1 = new QPropertyAnimation(graphicsWidget, "rotation");
    QPropertyAnimation *animation2 = new QPropertyAnimation(greenWidget, "opacity");
    QPropertyAnimation *animation3 = new QPropertyAnimation(redWidget, "opacity");
    QPropertyAnimation *animation4 = new QPropertyAnimation(graphicsWidget, "scale");

    animation4->setDuration(1000);
    animation4->setStartValue(0.5);
    animation4->setEndValue(1);

    animation->setDuration(1000);
    animation->setStartValue(QPoint(450, -20));
    animation->setEndValue(QPoint(230, 100));

    animation1->setDuration(1000);
    animation1->setStartValue(0);
    animation1->setEndValue(360);

    animation2->setDuration(500);
    animation2->setStartValue(1);
    animation2->setEndValue(0);

    animation3->setDuration(500);
    animation3->setStartValue(1);
    animation3->setEndValue(0);

    parallelAnimationGroup1->addAnimation(animation);
    parallelAnimationGroup1->addAnimation(animation1);
    parallelAnimationGroup1->addAnimation(animation2);
    parallelAnimationGroup1->addAnimation(animation3);
    parallelAnimationGroup1->addAnimation(animation4);
    parallelAnimationGroup1->start();
    state = 1;

    videonum->setPlainText("2");

}
void HomeWidget::onClick()
{
    int a = tangleGroup->getStatus();
    qDebug()<<a;
    if(a==0){
        circleGroup->busy();
        processThread->end();
    }
    else if(a==1){
        processThread->start();
    }
}
void HomeWidget::idle()
{
    qDebug()<<"idle";
    QSequentialAnimationGroup* sequentialAnimationGroup = new QSequentialAnimationGroup(this);
    QPropertyAnimation* animation1 = new QPropertyAnimation(tangleGroup,"scale");

    animation1->setDuration(1000);
    animation1->setStartValue(1.2);
    animation1->setEndValue(0.8);
    animation1->setEasingCurve(QEasingCurve::SineCurve);
    animation1->setLoopCount(-1);


    sequentialAnimationGroup->addAnimation(animation1);

    sequentialAnimationGroup->start();
}

void HomeWidget::busy()
{
    qDebug()<<"busy";
    QPropertyAnimation *animation = new QPropertyAnimation(circleGroup, "opacity");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
}
void HomeWidget::setFirNum(int num)
{

    fireNum+=num;
    numCircle->setNum(fireNum);
}
void HomeWidget::setconfirm(int num)
{
    checkCircle->setNum(num);
}














//void HomeWidget::timerEvent(QTimerEvent *event)
//{
//    graphicsWidget->setTransformOriginPoint(48, 48);
////    graphicsWidget->setRotation(rotation);
////    rotation+=3;
//    double angle = (rotation / 360) * 2 * 3.14;
////    item->setTransformOriginPoint(-40,40);
////    item->setRotation(-45);
////    item->setRotation(pointangle);
//    graphicsWidget->setScale((fabs(cos(angle)) + 3) / 4);
//    rotation += 2000;
////    pointangle+=(cos(angle)+1)*1.8;
////    pointangle++;
////    if (pointangle >= (314-60)) {
////        pointangle = 60;
////    }
////    double b =  (cosf((float) (pointangle / 100))-cosf(0.6))*(1/(cosf(3.54)));
////    item->setTransformOriginPoint(-30, 40);
////    double a = 180 * (1 - b);
////    item->setRotation(a);
////    qDebug()<<"a: "<<a<<" b: "<<b;
//}

