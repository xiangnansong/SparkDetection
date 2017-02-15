//
// Created by song on 3/20/16.
//

#ifndef MPLAYER_WIDGET_H
#define MPLAYER_WIDGET_H

#include <mpv/qthelper.hpp>
#include <mpv/client.h>
#include <QMainWindow>
#include <QWidget>

class QWidget;

class Widget: public QWidget
{
Q_OBJECT
public:
    Widget(QWidget *parent = 0);

    virtual ~Widget();

    void setProperty(const QString &name, const QVariant &value);

    QVariant getProperty(const QString &name) const;

    void command(const QVariant &params);

    void playFromExtern(QString);

    void onFinish(void);

    bool flag;
private:

    mpv_handle *mpv;

    void create_player();

    void handle_mpv_event(mpv_event *event);

signals:

    void mpv_events();

    void durationChanged(int value);

    void positionChanged(int value);


    void jumpBack(void);
protected slots:

    void on_mpv_events();

    void fileOpen();

};


#endif //MPLAYER_WIDGET_H
