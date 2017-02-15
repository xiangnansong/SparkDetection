//
// Created by song on 4/9/16.
//

#include <QtSql/QSqlQuery>
#include <QtSql>
#include "Picture.h"
#include "SqlUtils.h"
#include <QDebug>
bool Picture::record()
{
    QSqlQuery query(SqlUtils::getDb());

    query.prepare("INSERT INTO picture (name, path, size) "
                      "VALUES (:name,:path,:size)");
    query.bindValue(":name", name);
    qDebug() << path;
    query.bindValue(":path", path);
    qDebug() << name;
    query.bindValue(":size", size);
    qDebug() << size;

    query.exec();
    qDebug() << "exec";
    return false;
}

