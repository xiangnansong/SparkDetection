//
// Created by song on 4/9/16.
//

#ifndef PROJECT_PICTURE_H
#define PROJECT_PICTURE_H
#include "TableBase.h"
#include <QString>
class Picture:public TableBase
{
public:
    virtual bool record();
    Picture(const QString &path = "/", int size = 0, const QString &name = "picture")
        : path(path), size(size), name(name)
    { }
private:
    QString path;
    QString name;
    int size;
};


#endif //PROJECT_PICTURE_H
