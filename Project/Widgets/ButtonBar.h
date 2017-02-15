//
// Created by song on 3/31/16.
//

#ifndef PROGECT_BUTTONBAR_H
#define PROGECT_BUTTONBAR_H
#include "ImageButton.h"
#include <QWidget>
class MainWidget;
class ButtonBar: public QWidget
{
Q_OBJECT
public:
    friend class MainWidget;
    explicit ButtonBar(QWidget *parent = 0);


private:
    ImageButton *setBtn;
    ImageButton *tableBtn;
    ImageButton *closeBtn;
    ImageButton *miniBtn;
    ImageButton *viewBtn;
    ImageButton *homeBtn;
    ImageButton *playBtn;
};


#endif //PROGECT_BUTTONBAR_H
