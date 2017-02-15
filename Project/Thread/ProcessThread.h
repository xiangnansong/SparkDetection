//
// Created by song on 4/11/16.
//

#ifndef PROJECT_PROCESSTHREAD_H
#define PROJECT_PROCESSTHREAD_H
#include <QMutex>
#include <QThread>
#include <stdio.h>
#include <stdlib.h>
#include <DataBase/Config.h>
#include <QDebug>
#define sizeQStr sizeof(QString)
extern QMutex mutex;
class ProcessThread: public QThread
{

Q_OBJECT
protected:
    virtual void timerEvent(QTimerEvent *event) override;

protected:
    virtual void run() override;
    int stop;
public:
    QList<QString>filelist;
    SysConfig sysConfig;
    QString videoPath;
    ProcessThread(QObject *parent)
        : QThread(parent)
    {
        stop = 0;
    }

    int   readDat();
    void writeDat();

signals:
    void processFinish();
    void busy();
    void idle();
    void setNum(int);
public :
    void end();
private:
    void getConf();
};


#endif //PROJECT_PROCESSTHREAD_H
