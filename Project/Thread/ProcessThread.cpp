//
// Created by song on 4/11/16.
//

#include <QtSql/QSqlQuery>
#include <DataBase/SqlUtils.h>
#include "ProcessThread.h"
#include "algorithm.h"
#include <QDebug>

void ProcessThread::run()
{
    getConf();
    QDir dir(sysConfig.sourcePath+"/");
    qDebug()<<"song fsjkfafsadfdfa"<<sysConfig.sourcePath+"/";
    QStringList filters;
    filters << "*.avi" << "*.mp4" << "*.rmvb";
    QFileInfoList fileInfoList = dir.entryInfoList(filters);

    int a = 0;
    while (!stop) {
        filelist.clear();
        int num = readDat();
        fileInfoList = dir.entryInfoList(filters);
        for (int i = 0; i < fileInfoList.size(); i++) {
            int index = filelist.indexOf(fileInfoList[i].fileName());
            if (index == -1) {
                QString fileSource = fileInfoList[i].absoluteFilePath();
                qDebug() << fileSource;
                //一次process处理一个视频
                int firenum =  process(sysConfig,fileSource);
                emit setNum(firenum);
                emit busy();
                filelist.append(fileInfoList[i].fileName());
                num++;
            }
        }
        emit idle();
        writeDat();
        sleep(1);
        qDebug()<<"I am runing";
        qDebug()<<a;
        a++;
    }
    stop = 0;
//    mutex->lock();
//    qDebug()<<"before: "<<num;
//    process(sysConfig, videoPath);
//    qDebug()<<"the num is: "<<num;
//    num--;
//    if(num==0)
//    {
//        qDebug()<<"process finish";
//        emit processFinish();
//    }
//    mutex->unlock();
}



void ProcessThread::timerEvent(QTimerEvent *event)
{
    QDir dir(sysConfig.sourcePath+"/");
    QStringList filters;
    filters << "*.avi" << "*.mp4" << "*.rmvb";
    QFileInfoList fileInfoList = dir.entryInfoList(filters);

}

int ProcessThread::readDat()
{
    mutex.lock();
    int i = 0;
    QFile file("dat");
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);

    while (!in.atEnd()) {
        QString string;
        in >> string;
        filelist.append(string);
        i++;
    }
    mutex.unlock();
    return i;

}

void ProcessThread::writeDat()
{
    mutex.lock();
    QFile file("dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    for (int i = 0; i < filelist.size(); i++) {
        out << filelist[i];
    }
    mutex.unlock();
}
void ProcessThread::end()
{
    stop = 1;

}
void ProcessThread::getConf()
{
    QSqlQuery query(SqlUtils::getDb());
    query.exec("select * from Config_BasicParamater");
    query.next();
    sysConfig.videoPath = query.value(0).toString();
    sysConfig.picPath = query.value(1).toString();
    sysConfig.sourcePath = query.value(2).toString();
    sysConfig.length = query.value(3).toInt();

    qDebug() << "DateBase " << query.value(0).toString();
    qDebug() << "DateBase " << query.value(1).toString();
    qDebug() << "DateBase " << query.value(2).toString();
    qDebug() << "DateBase " << query.value(3).toInt();
}





















