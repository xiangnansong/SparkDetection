//
// Created by song on 3/21/16.
//

#ifndef MPLAYER_PLAYER_H
#define MPLAYER_PLAYER_H

#include <QWidget>
#include <QtWidgets/QPushButton>

#include "Widget.h"
class QSlider;

class QDial;

class QMediaPlayer;

class QLabel;

class QPushButton;

class QString;
class Player: public QWidget
{
Q_OBJECT

public:
    friend class StackWidget;
    Player(QWidget *parent = 0);
    void initUI();
    void playFromExtern(QString);
private:
    QPushButton *playButton;
    QPushButton *openButton;
    Widget *widget;
    QSlider *slider;
    QDial *dial;
    QString filepath;

protected slots:

    void playMedia();
    void setRange(int);
    void seekSlider(int);
    void seekVideo(int);
    void setVolume(int);
};


#endif //MPLAYER_PLAYER_H
