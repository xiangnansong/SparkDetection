//
// Created by song on 4/1/16.
//

#ifndef PROGECT_SETTINGWIDGET_H
#define PROGECT_SETTINGWIDGET_H
#include <QWidget>
#include <QDateEdit>
#include <QLabel>
#include "ImageButton.h"
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QSpinBox>
#include <QtWidgets/QComboBox>
#include <QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QDateTime>
#include "DataBase/Config.h"
class SettingWidget: public QWidget
{
Q_OBJECT
protected:
    virtual void timerEvent(QTimerEvent *event) override;

public:
    SettingWidget(QWidget *parent = 0);

    static SysConfig config;


private:
    QWidget *layoutWidget;
    QLabel *deviceidlabel;
    //提示id
    QLabel *framelabel;
    QLabel *formatlabel;
    QLabel *picoutlabel;
    QLabel *lengthlabel;
    QLabel *outputmodelabel;
    QLabel *savetimelabel;
    QLabel *outdirlabel;
    QLabel *indirLabel;

    QLineEdit *deviceidedit;
    QLineEdit *outdiredit; //输出目录
    QLineEdit *indiredit;
    QSpinBox *frameBox;
    QComboBox *formatBox;
    QLineEdit *picoutedit;
    QSpinBox *lengthedit;  //时间

    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QRadioButton *radioButton3;
    QDateTimeEdit *dateEdit;
    ImageButton *checkButton;
    QPushButton *saveButton;
    QPushButton *outdirbtn;
    QPushButton *picoutbtn;
    QPushButton *indirbtn;

    QDateTime dateTime;
protected slots:
    void setvideopath();
    void setpicpath();
    void setvideodir();
    void saveCong();
signals:
    void dateTimeChanged(QDateTime);

};
#endif //PROGECT_SETTINGWIDGET_H
