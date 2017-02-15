//
// Created by song on 5/31/16.
//

#ifndef PROJECT_CHECK_H
#define PROJECT_CHECK_H
#include <QString>
#include "TableBase.h"
class Check: public TableBase
{

public:
    Check(const QString &videoFilePath = "", const QString &picFilePath = "", int length = 0)
        : videoFilePath(videoFilePath), picFilePath(picFilePath), length(length)
    { }
public:
    virtual bool record() override;
    void unRecord();
    QString videoFilePath;
    QString picFilePath;
    int length;

};


#endif //PROJECT_CHECK_H
