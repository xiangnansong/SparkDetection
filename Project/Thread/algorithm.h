//
// Created by song on 4/17/16.
//

#ifndef CORE_ALGORITHM_H
#define CORE_ALGORITHM_H
#include "DataBase/Result.h"
#include <opencv2/opencv.hpp>
#include <DataBase/Config.h>
using namespace cv;
int process(SysConfig, QString);
Mat solve(Mat last, Mat current);
#endif //CORE_ALGORITHM_H
