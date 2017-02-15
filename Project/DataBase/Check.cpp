//
// Created by song on 5/31/16.
//

#include <QtSql/QSqlQuery>
#include "Check.h"
#include "SqlUtils.h"

bool Check::record()
{
    QSqlQuery query(SqlUtils::getDb());
    query.prepare("REPLACE INTO RT_LocalAlarm (videoFilePath, picFilePath, length) "
                      "VALUES (:videoFilePath,:picFilePath,:length)");
    query.bindValue(":videoFilePath", videoFilePath);
    qDebug() << videoFilePath;
    query.bindValue(":picFilePath", picFilePath);
    qDebug() << picFilePath;
    query.bindValue(":length", length);
    qDebug() << length;
    query.exec();
    qDebug() << "result exec";
    return false;
}
void Check::unRecord()
{
    QSqlQuery query(SqlUtils::getDb());
    qDebug()<<"now delete the record: "<<videoFilePath;
    query.exec(QString("delete from RT_LocalAlarm where videoFilePath ='%1'").arg(videoFilePath));


}



