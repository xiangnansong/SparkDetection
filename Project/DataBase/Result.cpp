//
// Created by song on 4/19/16.
//

#include <QtSql/QSqlQuery>
#include "Result.h"
#include "SqlUtils.h"

bool Result::record()
{
    QSqlQuery query(SqlUtils::getDb());
    query.prepare("REPLACE INTO result (videoFilePath, picFilePath, length, ischecked) "
                      "VALUES (:videoFilePath,:picFilePath,:length,:ischecked)");
    query.bindValue(":videoFilePath", videoFilePath);
    qDebug() << videoFilePath;
    query.bindValue(":picFilePath", picFilePath);
    qDebug() << picFilePath;
    query.bindValue(":length", length);
    qDebug() << length;
    query.bindValue(":ischecked", ischecked);
    qDebug() << ischecked;
    query.exec();
    qDebug() << "result exec";
    return false;
}

