//
// Created by song on 4/7/16.
//

#include "ViewWidget.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QDebug>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <iostream>
#include <QtSql/QSqlQuery>
#include <DataBase/SqlUtils.h>
#include "CheckView.h"
ViewWidget::ViewWidget(QWidget *parent)
    : QWidget(parent)
{
    getConf();
    QHBoxLayout *qhBoxLayout = new QHBoxLayout;
    lineEdit = new QLineEdit;
    QPushButton *choose = new QPushButton("刷新");
    QPushButton *confirm = new QPushButton("确认");

    progressBar = new QProgressBar;
    thread = new LoadThread(this);
//    qhBoxLayout->addWidget(lineEdit);
    qhBoxLayout->addStretch();
    qhBoxLayout->addWidget(choose);
    qhBoxLayout->addStretch();
    qhBoxLayout->addWidget(confirm);
    qhBoxLayout->addStretch();

//    qhBoxLayout->addWidget(progressBar);
    QVBoxLayout *qvBoxLayout = new QVBoxLayout(this);
    QScrollArea *scrollArea = new QScrollArea;
    //   scrollArea->setBackgroundRole(QPalette::Dark);
    qvBoxLayout->addLayout(qhBoxLayout);
    qvBoxLayout->addWidget(scrollArea);
    scrollArea->setWidgetResizable(true);

    dir = new QDir;
    path = "/home/song/Pictures/";
    viewLayout = new QVBoxLayout;
    viewLayout->setSpacing(30);
    widget = new QWidget;
    widget->setLayout(viewLayout);
    scrollArea->setWidget(widget);
    connect(choose, SIGNAL(clicked()), this, SLOT(getPath()));
    connect(confirm, SIGNAL(clicked()), this, SLOT(confirmDB()));

}

void ViewWidget::getPath()
{
//    path = QFileDialog::getExistingDirectory(this, "file", "/home/song/Pictures");
//    QStringList filters;
//    dir->setPath(sysConfig.picPath);
//    qDebug() << sysConfig.picPath;
//    filters << "*.jpg" << "*.png" << "*.gif";
//    dir->setNameFilters(filters);
//    int count = dir->count();
//
//    qDebug() << count;
//    QStringList list = dir->entryList(filters);


//    emit setcount(fileInfoList.size());
//    thread->setFileInfoList(fileInfoList);
//    thread->start();
//    for (int i = 0; i < fileInfoList.size(); i++) {
//        QFileInfo info = fileInfoList.at(i);
//        Picture picture(info.absolutePath(), info.size(), info.baseName());
//        picture.record();
//    }


//    for (int i = 0; i < count; i++) {
//        QLabel *label = new QLabel;
//        QString string = sysConfig.picPath + "/" + list[i];
//        qDebug() << string;
//        QImage image(string);
//        QImage image1 = image.scaled(650, 500);
//        label->setPixmap(QPixmap::fromImage(image1));
//        label->setMinimumSize(650, 500);
//        viewLayout->addWidget(label, i, 0, 1, 1);

    getResult();
    for (int i = 0; i < list.size(); i++) {

        if (resume.indexOf(list[i].picFilePath) == -1) {
            CheckView *checkView = new CheckView(list[i]);
            QHBoxLayout *rowLayout = new QHBoxLayout;
            rowLayout->addStretch();
            rowLayout->addWidget(checkView);
            rowLayout->addStretch();
            viewLayout->addLayout(rowLayout);
            connect(checkView, SIGNAL(playSignal(QString)), SLOT(playVideo(QString)));
            resume << list[i].picFilePath;
        }
    }
}

//
//    dir->setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
//    dir->setSorting(QDir::Size | QDir::Reversed);
//    QFileInfoList list = dir->entryInfoList();
//      std::cout << "     Bytes Filename" << std::endl;
//      for (int i = 0; i < list.size(); ++i) {
//          QFileInfo fileInfo = list.at(i);
//          std::cout << qPrintable(QString("%1 %2").arg(fileInfo.size(), 10)
//                                                  .arg(fileInfo.fileName()));
//          std::cout << std::endl;
//      }


void ViewWidget::setRange(int range)
{
    qDebug() << "range: " << range;
    progressBar->setRange(0, range);
}

void ViewWidget::getConf()
{

    QSqlQuery query(SqlUtils::getDb());
    query.exec("select * from Config_BasicParamater");


    query.next();

    sysConfig.videoPath = query.value(0).toString();
    sysConfig.picPath = query.value(1).toString();
    sysConfig.sourcePath = query.value(2).toString();
    sysConfig.length = query.value(3).toInt();
    qDebug() << "DateBase " << query.value(0).toString();
    qDebug() << "DateBase " << query.value(1).toString();
    qDebug() << "DateBase " << query.value(2).toString();
    qDebug() << "DateBase " << query.value(3).toInt();

}

void ViewWidget::getResult()
{
    Result result;
    list.clear();
    QSqlQuery query(SqlUtils::getDb());
    query.exec("select * from result");
    while (query.next()) {
        result.videoFilePath = query.value(0).toString();
        result.picFilePath = query.value(1).toString();
        result.length = query.value(2).toInt();
        result.ischecked = query.value(3).toBool();
        list << result;
    }
    qDebug() << "num is: " << list.size();
    for (int i = 0; i < list.size(); i++) {
        qDebug() << list[i].videoFilePath;
        qDebug() << list[i].picFilePath;
    }
}

void ViewWidget::playVideo(QString string)
{
    qDebug() << "receive: " << string;
    emit emitSignal(string);
}

void ViewWidget::confirmDB()
{
    list.clear();
//    resultList.clear();
    getResult();
    int num = 0;
    for (int i = 0; i < list.size(); i++) {
        if (list[i].ischecked == true) {
//            Check check;
//            check.videoFilePath = list[i].videoFilePath;
//            check.picFilePath = list[i].picFilePath;
//            check.length = list[i].length;
//            check.record();
//            resultList << check;
            num++;
        }
//        else {
//            QSqlQuery query(SqlUtils::getDb());
//            query.exec("delete from RT_LocalAlarm where videoFilePath ="+list[i].videoFilePath);
//        }
    }

    emit emitConfirm(num);
}








