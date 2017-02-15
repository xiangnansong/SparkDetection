//
// Created by song on 4/19/16.
//

#include <QtSql/QSqlQuery>
#include "Config.h"
#include "SqlUtils.h"

bool SysConfig::record()
{


    QSqlQuery query(SqlUtils::getDb());
    query.prepare("INSERT INTO Config_BasicParamater (videoPath, picPath,sourcePath,length, dateTime) "
                      "VALUES (:videoPath,:picPath,:sourcePath,:length,:dateTime)");
    query.bindValue(":videoPath", videoPath);
    query.bindValue(":picPath", picPath);
    query.bindValue(":sourcePath",sourcePath);
    query.bindValue(":length", length);
    query.bindValue(":dateTime", dateTime);
    query.exec();
    qDebug() << "exec";

    return false;
}


