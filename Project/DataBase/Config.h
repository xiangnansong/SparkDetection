//
// Created by song on 4/19/16.
//

#ifndef PROJECT_CONFIG_H
#define PROJECT_CONFIG_H

#include "TableBase.h"
#include <QString>

class SysConfig:public TableBase
{


public:
    SysConfig(const QString &videoPath = "~/video", const QString &picPath = "~/picture", const QString &sourcePath = "~/Project/STITP/video",int length = 3,QString datetime ="")
        : videoPath(videoPath), picPath(picPath), sourcePath(sourcePath),length(length),dateTime(datetime)
    { }
    virtual bool record() override;
    QString videoPath;
    QString picPath;
    QString sourcePath;
    QString dateTime;
    int length;
};


#endif //PROJECT_CONFIG_H
