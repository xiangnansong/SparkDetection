#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include <QPushButton>
#include <QPoint>

class ImageButton: public QPushButton
{
Q_OBJECT
    Q_PROPERTY(QSize size
                   READ
                       getSize
                   WRITE
                   setSize)
public:
    explicit ImageButton(QString normalName,
                         QString horverName,
                         QString pressName,
                         QWidget *parent = 0,
                         int icon_x = 0,
                         int icon_y = 0);
    QSize getSize();
    void setSize(QSize);
    //按钮的事件处理函数
protected:
    //鼠标进入事件
    virtual void enterEvent(QEvent *);
    //鼠标退出事件
    virtual void leaveEvent(QEvent *);
    //鼠标单击事件
    virtual void mousePressEvent(QMouseEvent *event);
    //鼠标释放事件
    virtual void mouseReleaseEvent(QMouseEvent *event);
    //鼠标样式绘制
    virtual void paintEvent(QPaintEvent *);

private:
    //用于标识按钮的触发状态
    typedef enum
    {
        //初始状态
            ST_INIT,
        //正常状态
            ST_NORMAL,
        //鼠标悬停状态
            ST_HOVER,
        //鼠标按下状态
            ST_PRESS,

        ST_COUNT
    } Status;
    Status curStatus_;

    //存储按钮在这几个状态下的背景图片
    QString imageName_[ST_COUNT];

    //存储按钮的大小
    int icon_width;
    int icon_height;
    QSize size;
    //存储按钮的位置
    int icon_x;
    int icon_y;

};

#endif // IMAGEBUTTON_H
