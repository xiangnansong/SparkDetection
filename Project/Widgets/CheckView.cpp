//
// Created by song on 5/31/16.
//

#include "CheckView.h"
#include <QDebug>
CheckView::CheckView(Result result, QWidget *parent)
    : QWidget(parent), result(result)
{

    check.length = result.length;
    check.videoFilePath = result.videoFilePath;
    check.picFilePath = result.picFilePath;



    mainlayout = new QVBoxLayout(this);
    playButton = new ImageButton(":/pix/src/start.png", ":/pix/src/start.png", ":/pix/src/startP.png");
    playButton->setFixedSize(50, 50);
    checkButton = new QCheckBox("确认");

    qDebug()<<"state: "<<result.videoFilePath<<"   "<<result.ischecked;

    if(result.ischecked){
        checkButton->setCheckState(Qt::Checked);
    }
    else{
        checkButton->setCheckState(Qt::Unchecked);
    }

    view = new PlayView(result);
    title = new QLabel;
    title->setText(result.picFilePath);
    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch();
    bottomLayout->addWidget(playButton);
    bottomLayout->addStretch();
    bottomLayout->addWidget(title);
    bottomLayout->addStretch();
    bottomLayout->addWidget(checkButton);
    bottomLayout->addStretch();



    mainlayout->addWidget(view);
    mainlayout->addLayout(bottomLayout);
    mainlayout->setSpacing(10);
    connect(playButton, SIGNAL(clicked()), this, SLOT(playVideo()));
    connect(checkButton,SIGNAL(stateChanged(int)),this,SLOT(stateChange(int)));
}

void CheckView::playVideo()
{
    qDebug() << "videofile: " << result.videoFilePath;
    emit playSignal(result.videoFilePath);
}

void CheckView::stateChange(int state)
{
    if (state == 2) {
        result.ischecked = true;
        result.record();
        check.record();
    }
    else {
        result.ischecked = false;
        result.record();
        check.unRecord();
    }
}
Result CheckView::getResult()
{
    return result;
}





