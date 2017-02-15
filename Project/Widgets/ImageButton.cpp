#include "ImageButton.h"
#include <QtWidgets>
#include <QPixmap>
#include <QDebug>
ImageButton::ImageButton(QString normalName,
                         QString horverName,
                         QString pressName,
                         QWidget *parent,
                         int icon_x,
                         int icon_y)
    : QPushButton(parent)
    //设置按钮初始状态
    , curStatus_(ST_INIT)
{
    //设置按钮状态为正常
    curStatus_ = ST_NORMAL;
    //存储按钮三态图片
    //正常图片
    imageName_[ST_NORMAL] = normalName;
    //悬停图片
    imageName_[ST_HOVER] = horverName;
    //按下图片
    imageName_[ST_PRESS] = pressName;

    //获得图片的大小以便用来调整按钮的大小
    QPixmap icon;
    icon.load(normalName);
    this->icon_width = icon.width();
    this->icon_height = icon.height();
    this->setGeometry(icon_x, icon_y, icon_width, icon_height);
    size = QSize(icon.width(), icon.height());
}

//按钮进入事件
void ImageButton::enterEvent(QEvent *)
{
    if (curStatus_ == ST_INIT) {
        return;
    }

    curStatus_ = ST_NORMAL;
    update();
}

//按钮离开事件
void ImageButton::leaveEvent(QEvent *)
{
    if (curStatus_ == ST_INIT) {
        return;
    }

    curStatus_ = ST_NORMAL;
    update();
}

//按钮按下事件
void ImageButton::mousePressEvent(QMouseEvent *event)
{
    if (curStatus_ == ST_INIT) {
        return;
    }

    //如果鼠标左键点击
    if (event->button() == Qt::LeftButton) {
        //将按钮状态设置为按下，并绘图
        curStatus_ = ST_PRESS;
        update();

    }

}

//按钮释放事件
void ImageButton::mouseReleaseEvent(QMouseEvent *event)
{
    //如果鼠标左键释放
    if (event->button() == Qt::LeftButton) {
        if (curStatus_ != ST_INIT) {
            //将按钮状态设置为悬停，并绘图
            curStatus_ = ST_HOVER;
            update();
        }
    }
    // 鼠标在弹起的时候光标在按钮上才激发clicked信号
    if (rect().contains(event->pos())) {
        qDebug() << "clicked";
        emit clicked();
    }
}

//按钮样式绘图
void ImageButton::paintEvent(QPaintEvent *event)
{
    if (curStatus_ == ST_INIT) {
        QPushButton::paintEvent(event);
        return;
    }

    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    QPixmap pixmap(imageName_[curStatus_]);
    this->resize(pixmap.width(), pixmap.height());
    painter.drawPixmap(rect(), pixmap);
}
QSize ImageButton::getSize()
{
    return size;
}
void ImageButton::setSize(QSize qsize)
{
    if (size != qsize) {
        this->resize(qsize);
        update();
    }
}




