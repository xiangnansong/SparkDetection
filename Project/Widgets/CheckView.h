//
// Created by song on 5/31/16.
//

#ifndef PROJECT_CHECKVIEW_H
#define PROJECT_CHECKVIEW_H

#include "DataBase/Check.h"
#include <QtWidgets/QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QImage>
#include <QLabel>
#include <QCheckBox>
#include "DataBase/Result.h"
#include "PlayView.h"
#include "ImageButton.h"

class CheckView: public QWidget
{
Q_OBJECT

public:
    CheckView(Result result, QWidget *parent = 0);
    Result getResult();
private:
    ImageButton *playButton;
    Result result;
    Check check;
    QVBoxLayout *mainlayout;
    QCheckBox *checkButton;
    QLabel *sourceLabel;
    QLabel *title;
    QLabel *destinationLabel;
    PlayView *view;

private slots:
    void playVideo();
    void stateChange(int);
signals:
    void playSignal(QString);
};


#endif //PROJECT_CHECKVIEW_H
