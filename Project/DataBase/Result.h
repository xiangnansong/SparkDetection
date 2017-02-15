//
// Created by song on 4/19/16.
//

#ifndef PROJECT_RESULT_H
#define PROJECT_RESULT_H

#include "TableBase.h"
#include <QString>
class Result: public TableBase
{

public:
    Result(const QString &videoFilePath = "", int length  = 0, const QString &picFilePath = "", bool ischecked = false)
        : videoFilePath(videoFilePath), length(length), picFilePath(picFilePath),ischecked(ischecked)
    { }
public:
    virtual bool record() override;
    QString videoFilePath;
    QString picFilePath;
    int length;
    bool  ischecked;

};


#endif //PROJECT_RESULT_H
