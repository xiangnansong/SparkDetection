//
// Created by song on 3/31/16.
//

#ifndef PROGECT_STACKWIDGET_H
#define PROGECT_STACKWIDGET_H
#include "HomeWidget.h"
#include "SettingWidget.h"
#include "ViewWidget.h"
#include "DataWidget.h"
#include <QWidget>
#include "MpvPlayer/Player.h"
class QStackedWidget;
class MainWidget;

class StackWidget: public QWidget
{
Q_OBJECT

public:
    friend class MainWidget;
    explicit StackWidget(QWidget *parent = 0);

private:
    QStackedWidget *stackedWidget;
    HomeWidget *homeWidget;
    SettingWidget *settingWidget;
    ViewWidget *viewWidget;
    DataWidget *dataWidget;
    Player *player;
private slots:
    void playVideo(QString);
    void back(void);
};


#endif //PROGECT_STACKWIDGET_H
