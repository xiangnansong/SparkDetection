//
// Created by song on 5/24/16.
//

#ifndef NEWWIDGET_PLAYVIEW_H
#define NEWWIDGET_PLAYVIEW_H

#include <QWidget>
#include "DataBase/Result.h"
class PlayView:public QWidget
{
Q_OBJECT

public:
    PlayView(Result result,QWidget *parent = 0);

private:
    Result result;
    QString picPath;

};


#endif //NEWWIDGET_PLAYVIEW_H
