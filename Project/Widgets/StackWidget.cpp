//
// Created by song on 3/31/16.
//
#include <QDebug>
#include "StackWidget.h"
#include <QStackedWidget>
#include <QDebug>
#include <QtWidgets/QVBoxLayout>
StackWidget::StackWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setAutoFillBackground(true);
    QPalette *palette = new QPalette;
    palette->setBrush(QPalette::Background, QBrush("#EAEAEA"));

    this->setPalette(*palette);
    qDebug() << "generate StackWidget";

    stackedWidget = new QStackedWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(stackedWidget);
    layout->setSpacing(0);
    layout->setMargin(0);

    setLayout(layout);
    homeWidget = new HomeWidget;
    settingWidget = new SettingWidget;
    viewWidget = new ViewWidget;
    dataWidget = new DataWidget;
    player = new Player;
    stackedWidget->addWidget(homeWidget);
    stackedWidget->addWidget(settingWidget);
    stackedWidget->addWidget(dataWidget);
    stackedWidget->addWidget(viewWidget);
    stackedWidget->addWidget(player);
    stackedWidget->setCurrentIndex(0);


    connect(viewWidget,SIGNAL(emitSignal(QString)),this,SLOT(playVideo(QString)));
    connect(player->widget,SIGNAL(jumpBack()),this,SLOT(back()));
    connect(viewWidget,SIGNAL(emitConfirm(int)),homeWidget,SLOT(setconfirm(int)));
}

void StackWidget::playVideo(QString string)
{
    stackedWidget->setCurrentIndex(4);
    qDebug()<<"parent receive: "<<string;
    player->playFromExtern(string);
}


void StackWidget::back(void)
{
    stackedWidget->setCurrentIndex(3);

}




