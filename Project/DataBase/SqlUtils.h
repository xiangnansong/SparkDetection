//
// Created by song on 3/6/16.
//

#ifndef SQL_SQLUTILS_H
#define SQL_SQLUTILS_H
#include <QtSql/QtSql>

class SqlUtils
{
private:
    SqlUtils()
    { }
    static QSqlDatabase db;
    static bool open;
public:
    static QSqlDatabase getDb();


};


#endif //SQL_SQLUTILS_H

















