//
// Created by song on 3/6/16.
//
//
//建立数据库表
#include <QtWidgets/QMessageBox>
#include "SqlUtils.h"

//QSqlDatabase SqlUtils::db = QSqlDatabase::addDatabase("QSQLITE","connect");
//
//
//QSqlDatabase SqlUtils::getDb() {
////    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("song.db");
//    db.open();
//    return db;
//}
QSqlDatabase SqlUtils::db = QSqlDatabase::addDatabase("QSQLITE","connect");
bool SqlUtils::open = false;

QSqlDatabase SqlUtils::getDb() {
    if(!open){
        db.setDatabaseName("song.db");
        db.open();
        open = true;
    }
    return db;
}




