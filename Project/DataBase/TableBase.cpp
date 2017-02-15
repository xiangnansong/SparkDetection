//
// Created by song on 3/6/16.
//
#include <QtSql>
#include "TableBase.h"
#include "SqlUtils.h"

void TableBase::sqlTableInit() {
    QSqlQuery query(SqlUtils::getDb());
    query.exec("CREATE TABLE picture("
                       "name text PRIMARY KEY,"
                       "path text ,"
                       "size integer"
                       ")");
    query.exec("CREATE TABLE Config_BasicParamater("
                   "videoPath text ,"
                   "picPath text ,"
                   "sourcePath text,"
                   "length integer,"
                   "dateTime text PRIMARY KEY"
                   ")");
    query.exec("CREATE TABLE result("
                   "videoFilePath text PRIMARY KEY,"
                   "picFilePath text ,"
                   "length integer,"
                   "ischecked boolean"
                   ")");
    query.exec("CREATE TABLE RT_LocalAlarm("
                   "videoFilePath text PRIMARY KEY,"
                   "picFilePath text ,"
                   "length integer"
                   ")");



}

bool TableBase::record() {
    return false;
}
