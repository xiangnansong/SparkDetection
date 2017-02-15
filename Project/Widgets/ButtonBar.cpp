//
// Created by song on 3/31/16.
//
#include "ButtonBar.h"
#include <QPalette>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include "MpvPlayer/Player.h"
ButtonBar::ButtonBar(QWidget *parent)
    : QWidget(parent)
{
    this->setAutoFillBackground(true);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    setBtn = new ImageButton(":/pix/src/setting.png", ":/pix/src/setting.png", ":/pix/src/settingC.png");
    tableBtn = new ImageButton(":/pix/src/table.png", ":/pix/src/table.png", ":/pix/src/tableC.png");
    homeBtn = new ImageButton(":/pix/src/home.png", ":/pix/src/home.png", ":/pix/src/homeC.png");
    closeBtn = new ImageButton(":/pix/src/close.png", ":/pix/src/close.png", ":/pix/src/closeC.png");
    viewBtn = new ImageButton(":/pix/src/pic.png", ":/pix/src/pic.png", ":/pix/src/picC.png");
    playBtn = new ImageButton(":/pix/src/play.png", ":/pix/src/play.png", ":/pix/src/playC.png");


    QPalette *palette = new QPalette;
    palette->setColor(QPalette::Window, QColor(63, 69, 80));
    this->setPalette(*palette);

    mainLayout->addSpacing(20);
    mainLayout->addWidget(homeBtn);
    mainLayout->addWidget(setBtn);
    mainLayout->addWidget(tableBtn);
    mainLayout->addWidget(viewBtn);
    mainLayout->addWidget(playBtn);
    mainLayout->addStretch();
    mainLayout->addWidget(closeBtn);
    mainLayout->setSpacing(40);

    mainLayout->addWidget(new QLabel);
    resize(96, 600);

    mainLayout->setContentsMargins(13, 10, 5, 10);

}

