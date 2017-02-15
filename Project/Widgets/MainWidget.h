//
// Created by song on 3/31/16.
//

#ifndef PROGECT_MAINWIDGET_H
#define PROGECT_MAINWIDGET_H
#include "StackWidget.h"
#include "ButtonBar.h"
#include "ViewWidget.h"

#include <QWidget>
#include <QtGui/QPainter>
class MainWidget: public QWidget
{
Q_OBJECT

protected :
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;

public:

    explicit MainWidget(QWidget *parent = 0);
    void getScreenInfo();
private:
    StackWidget *stackWidget;
    ButtonBar *buttonBar;
    QPoint dragPoint;
    int screenwidth;
    int screenheight;
protected slots:
    void toSetPage();
    void toHomePage();
    void toViewPage();
    void toTablePage();
    void toPlayPage();
//protected:
//    virtual void paintEvent(QPaintEvent *event) override
//    {
//        QPainter painter(this);
//        painter.setRenderHint(QPainter::SmoothPixmapTransform);
//       // painter.drawPixmap(-50,-50,QPixmap(":/pix/src/mask.png"));
//    }


};



#endif //PROGECT_MAINWIDGET_H
