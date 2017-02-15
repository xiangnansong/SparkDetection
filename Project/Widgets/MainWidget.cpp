//
// Created by song on 3/31/16.
//
#include <QDebug>
#include <QtWidgets/QVBoxLayout>
#include "MainWidget.h"
#include "ButtonBar.h"
#include <QHBoxLayout>
#include <QDebug>
#include <QPushButton>
#include <QPixmap>
#include <QBitmap>
#include <QMouseEvent>
#include <QStackedWidget>
#include <QtWidgets/QDesktopWidget>
#include <QtWidgets/QApplication>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    getScreenInfo();
    QPixmap pix;

    //设置圆角窗体，但是圆角处有锯齿现象
//    pix.load(":/pix/src/mask.png", 0, Qt::AvoidDither | Qt::ThresholdDither | Qt::ThresholdAlphaDither);
//    setMask(QBitmap(pix.mask()));

    QHBoxLayout *mainlayout = new QHBoxLayout(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    buttonBar = new ButtonBar;
    stackWidget = new StackWidget;
    mainlayout->addWidget(buttonBar, 1);
    mainlayout->addWidget(stackWidget, 10);


    mainlayout->setSpacing(0);
    mainlayout->setMargin(0);


    this->setFixedSize(800, 600);
    move(screenwidth / 2 - 400, screenheight / 2 - 300);


    connect(buttonBar->closeBtn, SIGNAL(clicked()), this, SLOT(close()));
    connect(buttonBar->setBtn, SIGNAL(clicked()), this, SLOT(toSetPage()));
    connect(buttonBar->homeBtn, SIGNAL(clicked()), this, SLOT(toHomePage()));
    connect(buttonBar->tableBtn, SIGNAL(clicked()), this, SLOT(toTablePage()));
    connect(buttonBar->viewBtn, SIGNAL(clicked()), this, SLOT(toViewPage()));
    connect(buttonBar->playBtn, SIGNAL(clicked()), this, SLOT(toPlayPage()));

}

void MainWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        QPoint tmp = event->globalPos() - pos();
        dragPoint = tmp;
        event->accept();

    }
}

void MainWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QCursor cursor;
    cursor.setShape(Qt::ArrowCursor);
    QApplication::setOverrideCursor(cursor);
}

void MainWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::RightButton) {
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);
        QPoint tmp = event->globalPos() - pos();
        move(event->globalPos() - dragPoint);
        event->accept();

    }

}

void MainWidget::getScreenInfo()
{
    QDesktopWidget *desktopWidget = QApplication::desktop();
    QRect screenRect = desktopWidget->screenGeometry();
    screenwidth = screenRect.width();
    screenheight = screenRect.height();
}
void MainWidget::toSetPage()
{
    stackWidget->stackedWidget->setCurrentIndex(1);
}
void MainWidget::toHomePage()
{
    stackWidget->stackedWidget->setCurrentIndex(0);
}
void MainWidget::toViewPage()
{
    stackWidget->stackedWidget->setCurrentIndex(3);
}
void MainWidget::toTablePage()
{
    stackWidget->stackedWidget->setCurrentIndex(2);
}
void MainWidget::toPlayPage()
{
    stackWidget->stackedWidget->setCurrentIndex(4);

}
















