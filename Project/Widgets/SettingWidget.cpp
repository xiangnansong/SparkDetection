//
// Created by song on 4/1/16.
//
#include "SettingWidget.h"
#include <QGridLayout>
#include <QDebug>
#include <QFileDialog>
#include <QLabel>
SettingWidget::SettingWidget(QWidget *parent)
    : QWidget(parent)
{
    layoutWidget = new QWidget(this);
    layoutWidget->setGeometry(50, 50, 600, 500);
    dateTime = QDateTime::currentDateTimeUtc();

    QHBoxLayout *qhBoxLayout;
    qhBoxLayout = new QHBoxLayout;
    QGridLayout *mainLayout = new QGridLayout(layoutWidget);

    deviceidlabel = new QLabel("设备ID");
    framelabel = new QLabel("帧数");
    formatlabel = new QLabel("图片格式");
    picoutlabel = new QLabel("图片输出目录");
    lengthlabel = new QLabel("视频长度");
    outputmodelabel = new QLabel("输出模式");
    savetimelabel = new QLabel("参数日期");
    outdirlabel = new QLabel("视频输出");
    indirLabel = new QLabel("视频输入");

    saveButton = new QPushButton("保存");

    outdirbtn = new QPushButton("...");
    picoutbtn = new QPushButton("...");
    indirbtn = new QPushButton("...");

    deviceidedit = new QLineEdit;
    frameBox = new QSpinBox;
    formatBox = new QComboBox;
    formatBox->addItem("png");
    formatBox->addItem("jpg");
    picoutedit = new QLineEdit;
    lengthedit = new QSpinBox;
    lengthedit->setValue(3);
    outdiredit = new QLineEdit;
    indiredit = new QLineEdit;

    radioButton1 = new QRadioButton("报警");
    radioButton2 = new QRadioButton("图片");
    radioButton3 = new QRadioButton("视频");

    qhBoxLayout->addStretch();
    qhBoxLayout->addWidget(radioButton1);
    qhBoxLayout->addWidget(radioButton2);
    qhBoxLayout->addWidget(radioButton3);
    qhBoxLayout->addStretch();

    dateEdit = new QDateTimeEdit;
    dateEdit->setDisplayFormat("yyyy-MM-dd hh:mm:ss");
    dateEdit->setDateTime(dateTime.currentDateTimeUtc());

    mainLayout->setSpacing(6);

    mainLayout->setVerticalSpacing(11);
    mainLayout->setContentsMargins(50, 50, 30, 50);


    mainLayout->addWidget(outdirlabel, 0, 0, 1, 1, Qt::AlignCenter);
    mainLayout->addWidget(indirLabel, 1, 0, 1, 1, Qt::AlignCenter);

    mainLayout->addWidget(deviceidlabel, 2, 0, 1, 1, Qt::AlignCenter);
    mainLayout->addWidget(framelabel, 3, 0, 1, 1, Qt::AlignCenter);
    mainLayout->addWidget(formatlabel, 4, 0, 1, 1, Qt::AlignCenter);
    mainLayout->addWidget(picoutlabel, 5, 0, 1, 1, Qt::AlignCenter);
    mainLayout->addWidget(lengthlabel, 6, 0, 1, 1, Qt::AlignCenter);
    mainLayout->addWidget(outputmodelabel, 7, 0, 1, 1, Qt::AlignCenter);
    mainLayout->addWidget(savetimelabel, 8, 0, 1, 1, Qt::AlignCenter);

    mainLayout->addWidget(outdiredit, 0, 1, 1, 1);
    mainLayout->addWidget(indiredit, 1, 1, 1, 1);

    mainLayout->addWidget(deviceidedit, 2, 1, 1, 1);
    mainLayout->addWidget(frameBox, 3, 1, 1, 1);
    mainLayout->addWidget(formatBox, 4, 1, 1, 1);
    mainLayout->addWidget(picoutedit, 5, 1, 1, 1);
    mainLayout->addWidget(lengthedit, 6, 1, 1, 1);
    mainLayout->addLayout(qhBoxLayout, 7, 1, 1, 1);
    mainLayout->addWidget(dateEdit, 8, 1, 1, 1);
    QLabel *space = new QLabel("");
    mainLayout->addWidget(space, 9, 1, 1, 1);
    mainLayout->addWidget(saveButton, 10, 1, 1, 1, Qt::AlignCenter);
    saveButton->setMaximumWidth(90);

    mainLayout->addWidget(outdirbtn, 0, 2, 1, 1, Qt::AlignLeft);
    mainLayout->addWidget(indirbtn, 1, 2, 1, 1, Qt::AlignLeft);
    mainLayout->addWidget(picoutbtn, 5, 2, 1, 1, Qt::AlignLeft);
    connect(outdirbtn, SIGNAL(clicked()), this, SLOT(setvideopath()));
    connect(picoutbtn, SIGNAL(clicked()), this, SLOT(setpicpath()));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveCong()));
    connect(indirbtn, SIGNAL(clicked()), this, SLOT(setvideodir()));

    startTimer(1000);
    config.length = lengthedit->value();
    config.videoPath = outdiredit->text();
    config.picPath = picoutedit->text();
    config.dateTime = dateEdit->dateTime().toString();

}

void SettingWidget::setvideopath()
{
    QString videoPath = QFileDialog::getExistingDirectory(this, "choose dir", "/home/song/Movie");
    outdiredit->setText(videoPath);
    config.videoPath = videoPath;
}
void SettingWidget::setpicpath()
{
    QString picPath = QFileDialog::getExistingDirectory(this, "choose dir", "/home/song/Picture");
    picoutedit->setText(picPath);
    config.picPath = picPath;

}

void SettingWidget::timerEvent(QTimerEvent *event)
{
    dateTime = QDateTime::currentDateTimeUtc();
    QString string = dateTime.toString();
    dateEdit->setDateTime(dateTime.currentDateTimeUtc());
    config.length = lengthedit->value();
    config.videoPath = outdiredit->text();
    config.picPath = picoutedit->text();
    config.dateTime = dateEdit->dateTime().toString();

}
void SettingWidget::saveCong()
{
    config.record();
}

void SettingWidget::setvideodir()
{
    QString videoPath = QFileDialog::getExistingDirectory(this, "choose dir", "/home/song/Project/STITP/video");
    indiredit->setText(videoPath);
    config.sourcePath = videoPath;
}

SysConfig SettingWidget::config;

