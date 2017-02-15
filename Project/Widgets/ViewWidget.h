//
// Created by song on 4/7/16.
//

#ifndef PROJECT_VIEWWIDGET_H
#define PROJECT_VIEWWIDGET_H

#include <QWidget>
#include <QDir>
#include <QtWidgets/QGridLayout>
#include <QProgressBar>
#include "Thread/LoadThread.h"
#include "DataBase/Config.h"
#include "DataBase/Result.h"
#include "DataBase/Check.h"
class QLineEdit;
class ViewWidget: public QWidget
{
Q_OBJECT

public:
    ViewWidget(QWidget *parent = 0);
private:
    //数据库中的数据
    QList<Result> list;
    //确认后数据库中的数据
    QList<Check> resultList;
    //保存已经建立的控件，防止控件重复创建
    QList<QString> resume;

    QWidget *widget;


    QLineEdit *lineEdit;
    QString path;
    QDir *dir;
    QVBoxLayout *viewLayout;
    QProgressBar *progressBar;
    LoadThread *thread;
    SysConfig sysConfig;
    void getConf();
    void getResult();
protected slots:
    void getPath();
    void setRange(int range);
    void playVideo(QString);
    void confirmDB();

signals:
    void setcount(int count);
    void emitSignal(QString);
    void emitConfirm(int);
};


#endif //PROJECT_VIEWWIDGET_H
