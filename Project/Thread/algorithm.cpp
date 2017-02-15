//
// Created by song on 4/17/16.
//
#include "algorithm.h"
#include <QDebug>
#include <QFileInfo>

using namespace std;
int process(SysConfig proconf, QString videoPath)
{

    Result result;
    QList<QString> movelist;
    QList<QString> piclist;
    QString path = videoPath;
    QFileInfo *fileInfo = new QFileInfo(videoPath);
    VideoCapture capture(path.toStdString());
    Size size = Size((int) capture.get(CV_CAP_PROP_FRAME_WIDTH),
                     (int) capture.get(CV_CAP_PROP_FRAME_HEIGHT));
    //获得帧率
    double fps = capture.get(CV_CAP_PROP_FPS);
    double intime = 2 * fps;
    int count1 = 0;
    int zs = 0;
    int pos = 0;
    //火花出现的位置
    int firepos[100] = {0};
    //一个视频中火花的数目
    int firenum = 0;
    intime = intime / 2;

    Mat resume;
    Mat sample;
    Mat area;
    capture.read(sample);
    resume.create(sample.rows, sample.cols, sample.type());
    Size areasize(200, 200);
    area.create(areasize, sample.type());

    for (int i = 0; i < resume.rows; i++) {
        uchar *data = resume.ptr<uchar>(i);
        for (int j = 0; j < resume.cols * resume.channels(); j++) {
            data[j] = 255;
        }
    }
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    while (1) {
        zs++;
        Mat cap;
        if (!capture.read(cap)) {
            break;
        }
        Mat copy = cap.clone();
        //--------------------对图像进行处理--------------//
        //中值滤波，参数可根据具体情况更改
        blur(cap, cap, Size(3, 3), Point(-1, -1));
        //腐蚀，膨胀操作的核矩阵
        Mat element = getStructuringElement(MORPH_ELLIPSE, Size(30, 30));
        Mat element1 = getStructuringElement(MORPH_ELLIPSE, Size(10, 10));

        erode(cap, cap, element);
        dilate(cap, cap, element1);

        Mat gray;
        //将彩图转化为灰度图
        cvtColor(cap, gray, CV_RGB2GRAY);

        //--------------------对图像进行差值运算-------------//
        Mat resGray;
        cvtColor(resume, resGray, CV_RGB2GRAY);
        Mat subtract;
        //经过差分后的图片存在subtract中
        subtract = solve(resGray, gray);
        resume = copy.clone();
        Mat resultm;
        dilate(subtract, resultm, element);
        erode(resultm, resultm, element);
        threshold(resultm, resultm, 240, 255, CV_THRESH_BINARY);

        findContours(resultm, contours, hierarchy, RETR_TREE, CV_CHAIN_APPROX_NONE, Point(0, 0));
        for (int i = 0; i < contours.size(); i++) {
            //得到最外面的矩形边界
            if (contourArea(contours[i]) > 300) {
                int num = 0;
                resize(subtract,area,areasize);
                for (int j = 0; j < area.rows; j++) {
                    uchar *subptr = area.ptr<uchar>(j);
                    for (int k = 0; k < area.cols; k++) {
                        int diff = (int) abs((int)subptr[k]-0);
                        if (diff > 0)
                            num++;
                    }
                }
                //确认火花出现
                if (num / (float) (area.cols * area.cols) > 0.1) {
                    //火花的位置
                    pos = zs;
                    firepos[firenum] = zs;
                    //设置图片的名称
                    QString setnum;
                    setnum.setNum(firenum);
                    QString picPath = proconf.picPath + "/" + fileInfo->baseName() + "_" + setnum + ".png";
                    result.picFilePath = picPath;
                    piclist << picPath;
                    //保存图片
                    Size size1(450, 300);
                    Mat mat1;
                    mat1.create(size1, copy.type());
                    resize(copy, mat1, size1);
                    imwrite(picPath.toStdString(), mat1);
                    firenum++;
                }
            }
        }
    }

    for (int i = 0; i < firenum; i++) {

        VideoCapture capturenew(path.toStdString());
        VideoWriter writer;
        QString videoname;
        videoname.setNum(i);
        QString videoOut = proconf.videoPath + "/" + fileInfo->baseName() + "_" + videoname + ".avi";
        movelist << videoOut;
        result.videoFilePath = videoOut;
        result.record();
        qDebug() << "outfile: " << videoOut;
        writer.open(videoOut.toStdString(),
                    (int) capture.get(CV_CAP_PROP_FOURCC),
                    capture.get(CV_CAP_PROP_FPS),
                    size,
                    1);
        while (1) {

            count1++;
            Mat cap;
            if (!capturenew.read(cap)) {
                break;
            }
            if (count1 > pos - intime && count1 < pos + intime) {
                writer << cap;
            }
        }
        count1 = 0;

    }
    for (int j = 0; j < firenum; j++) {
        //保存检测结果在数据库中
        Result result1;
        result1.videoFilePath = movelist[j];
        result1.picFilePath = piclist[j];
        result1.record();
    }
    return firenum;
}


Mat solve(Mat last, Mat current)//比较当前帧与上一帧亮度变化率
{
    double flag = 0;
    int height = current.rows;
    int width = current.cols;
    Mat result;
    result.create(last.rows, last.cols, last.type());
    for (int rows = 0; rows < height; rows++) {
        uchar *curptr = current.ptr<uchar>(rows);
        uchar *lastptr = last.ptr<uchar>(rows);
        uchar *resptr = result.ptr<uchar>(rows);
        for (int cols = 0; cols < width; cols++) {
            flag = (double) curptr[cols] - (double) lastptr[cols];
            if (flag < 34)
                resptr[cols] = 0;
            else
                resptr[cols] = (uchar) curptr[cols];
        }
    }
    return result;
}

