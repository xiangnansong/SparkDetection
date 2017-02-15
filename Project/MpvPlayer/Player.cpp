//
// Created by song on 3/21/16.
//

#include "Player.h"
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QSlider>
#include <QDial>
#include <QVBoxLayout>
#include <QDebug>
#include <QFileDialog>

Player::Player(QWidget *parent)
    : QWidget(parent)
{
    initUI();
    connect(openButton, SIGNAL(clicked()), widget, SLOT(fileOpen()));
    connect(playButton, SIGNAL(clicked()), this, SLOT(playMedia()));
    connect(widget, SIGNAL(durationChanged(int)), this, SLOT(setRange(int)));
    connect(widget, SIGNAL(positionChanged(int)), this, SLOT(seekSlider(int)));
    connect(slider, SIGNAL(sliderMoved(int)), this, SLOT(seekVideo(int)));
    connect(dial, SIGNAL(sliderMoved(int)), this, SLOT(setVolume(int)));
}

void Player::initUI()
{
    QVBoxLayout *mainlayour = new QVBoxLayout(this);
    QHBoxLayout *bottom = new QHBoxLayout;
    widget = new Widget;
    playButton = new QPushButton("play");
    openButton = new QPushButton("open");
    slider = new QSlider(Qt::Horizontal);

    dial = new QDial;
    dial->setRange(0, 100);
    dial->setValue(0);
    bottom->addWidget(openButton);
    bottom->addStretch();
    bottom->addWidget(playButton);
    bottom->addStretch();
    bottom->addWidget(dial);

    mainlayour->addWidget(widget);
    mainlayour->addWidget(slider);
    mainlayour->addLayout(bottom);
    mainlayour->setStretchFactor(widget, 20);
    mainlayour->setStretchFactor(slider, 1);
    mainlayour->setStretchFactor(bottom, 1);
    setLayout(mainlayour);

}

void Player::playMedia()
{
    const bool paused = widget->getProperty("pause").toBool();
    widget->setProperty("pause", !paused);
}

void Player::setRange(int range)
{
//    qDebug()<<"range: "<<range;
    slider->setRange(0, range);
}

void Player::seekSlider(int value)
{

    slider->setValue(value);

}

void Player::seekVideo(int value)
{
    widget->command(QVariantList() << "seek" << value << "absolute");
}

void Player::setVolume(int volume)
{
    widget->setProperty("volume", volume);
    qDebug() << "volume" << volume;
}
void Player::playFromExtern(QString string)
{

    widget->playFromExtern(string);
}







