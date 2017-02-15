//
// Created by song on 4/11/16.
//

#ifndef PROJECT_LOADTHREAD_H
#define PROJECT_LOADTHREAD_H
#include <QThread>
#include <QObject>
#include <DataBase/Picture.h>
#include <QFileInfoList>
#include <QMutex>
class LoadThread: public QThread
{
Q_OBJECT
protected :
    virtual void run() override;

private:
    QFileInfoList fileInfoList;

signals:
    void setVaule(int vaule);

public:
    QMutex mutex;
    void setFileInfoList(QFileInfoList fileInfoList)
    {
        LoadThread::fileInfoList = fileInfoList;
    }
    LoadThread(QObject *parent)
        : QThread(parent)
    { }

};


#endif //PROJECT_LOADTHREAD_H
