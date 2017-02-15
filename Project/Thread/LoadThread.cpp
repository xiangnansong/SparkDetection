//
// Created by song on 4/11/16.
//

#include "LoadThread.h"
#include <QDebug>
#include "DataBase/SqlUtils.h"
#include <QSqlDatabase>
#include <QSqlQuery>
void LoadThread::run()
{

    QSqlQuery *query = new QSqlQuery(SqlUtils::getDb());
    query->exec("select * from config");

    qDebug() << "DateBase " << query->value(0);
//    for (int i = 0; i < fileInfoList.size(); i++) {
//        QFileInfo info = fileInfoList.at(i);
//        Picture picture(info.absolutePath(), (int) info.size(), info.baseName());
//        emit setVaule(i + 1);
//        picture.record();
//        qDebug() << i;
//    }
}



