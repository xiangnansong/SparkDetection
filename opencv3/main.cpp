#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
void algorithm(void);
void compare(void);
Mat solve(Mat last, Mat current);
int main()
{
    float start = (float) clock();
    algorithm();
//    compare();
    float end = (float) clock();
    cout<<"time: "<<(end-start)/ CLOCKS_PER_SEC<<endl;
    waitKey(0);
    return 0;
}
void algorithm(void)
{
    //保留上一帧，用于前向差分
    Mat resume;
    //打开视频流
    VideoCapture capture("/home/song/Project/STITP/5.avi");
    Size size = Size((int) capture.get(CV_CAP_PROP_FRAME_WIDTH),
                     (int) capture.get(CV_CAP_PROP_FRAME_HEIGHT));
    //获得帧率
    Mat sample;
    Mat area;
    Size areasize(200, 200);
    area.create(areasize, sample.type());
    capture.read(sample);
    resume.create(sample.rows, sample.cols, sample.type());

    for (int i = 0; i < resume.rows; i++) {
        uchar *data = resume.ptr<uchar>(i);
        for (int j = 0; j < resume.cols * resume.channels(); j++) {
            data[j] = 255;
        }

    }

    double fps = capture.get(CV_CAP_PROP_FPS);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    while (1) {
        Mat cap;
        //获取帧图
        if (!capture.read(cap)) {
            break;
        }
        //保留原图
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
        Mat result;
        dilate(subtract, result, element);
        erode(result, result, element);
        threshold(result, result, 240, 255, CV_THRESH_BINARY);

        findContours(result, contours, hierarchy, RETR_TREE, CV_CHAIN_APPROX_NONE, Point(0, 0));

        for (int i = 0; i < contours.size(); i++) {
            if (contourArea(contours[i]) > 300) {
                int num = 0;
                resize(subtract,area,areasize);
                for (int j = 0; j < area.rows; j++) {
                    uchar *subptr = area.ptr<uchar>(j);
                    for (int k = 0; k < area.cols; k++) {
                        int diff = (int) abs(subptr[k]);
                        if (diff > 0)
                            num++;
                    }
                }
                cout<<num / (float)(area.cols * area.cols)<<endl;
                if (num / (float)(area.cols * area.cols) > 0.1) {
                    cout<<"yes"<<endl;
                }
            }
        }
        //显示原画面
        imshow("q", copy);
        //差分后的图像
        imshow("", subtract);
        //最终的图像
        imshow("s", result);
        waitKey((int) (1000 / fps));

    }

}

//注意参数的顺序
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
            //   cout<<flag<<endl;
            if (flag < 34)
                resptr[cols] = 0;
            else
                resptr[cols] = (uchar) curptr[cols];
        }
    }
    return result;
}
