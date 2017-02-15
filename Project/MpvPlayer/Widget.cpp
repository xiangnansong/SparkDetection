//
// Created by song on 3/20/16.
//
#include "Widget.h"
#include <QMenuBar>
#include <QMainWindow>
#include <QtWidgets/QFileDialog>
#include <QDebug>
static void wakeup(void *ctx) //回调函数
{
    // This callback is invoked from any mpv thread (but possibly also
    // recursively from a thread that is calling the mpv API). Just notify
    // the Qt GUI thread to wake up (so that it can process events with
    // mpv_wait_event()), and return as quickly as possible.
    Widget *mainwindow = (Widget *) ctx;

    emit mainwindow->mpv_events();

}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    flag= false;
    setWindowTitle("Qt embedding demo");
    setMinimumSize(640, 480);
//    QMenu *menu = menuBar()->addMenu("file");
//    QAction *open = new QAction("open", this);
//    connect(open, SIGNAL(triggered()), this, SLOT(fileOpen()));
//    menu->addAction(open);

    mpv = mpv_create();
//    mpvPlayer = new QWidget(this);
//    setCentralWidget(mpvPlayer);

    int64_t wid = winId();
    mpv_set_option(mpv, "wid", MPV_FORMAT_INT64, &wid);
    mpv_set_option_string(mpv, "input-default-bindings", "yes");
    mpv_set_option_string(mpv, "input-vo-keyboard", "yes");
    mpv_set_option_string(mpv, "terminal", "yes");
    mpv_set_option_string(mpv, "msg-level", "all=v");
    mpv_observe_property(mpv, 0, "time-pos", MPV_FORMAT_DOUBLE);
    mpv_observe_property(mpv, 0, "track-list", MPV_FORMAT_NODE);
    mpv_observe_property(mpv, 0, "chapter-list", MPV_FORMAT_NODE);
    mpv_observe_property(mpv, 0, "duration", MPV_FORMAT_DOUBLE);
    mpv_request_log_messages(mpv, "info");
    connect(this, SIGNAL(mpv_events()), this, SLOT(on_mpv_events()), Qt::QueuedConnection);
    mpv_set_wakeup_callback(mpv, wakeup, this);           //loop in the other thread ,will always emit mpv_event;
    if (mpv_initialize(mpv) < 0)
        throw std::runtime_error("mpv failed to initialize");
}

Widget::~Widget()
{
    if (mpv)
        mpv_terminate_destroy(mpv);
}

void Widget::create_player()
{

}

void Widget::handle_mpv_event(mpv_event *event)
{
    switch (event->event_id) {
        case MPV_EVENT_PROPERTY_CHANGE: {
            mpv_event_property *eventProperty = (mpv_event_property *) event->data;
            if (strcmp(eventProperty->name, "time-pos") == 0) {
                if (eventProperty->format == MPV_FORMAT_DOUBLE) {
                    double time = *(double *) eventProperty->data;
                    emit positionChanged((int) time);
                }
            }
            else if (strcmp(eventProperty->name, "duration") == 0) {
                if (eventProperty->format == MPV_FORMAT_DOUBLE) {
                    double time = *(double *) eventProperty->data;
                    emit durationChanged((int) time);
                }
            }
        };
            break;
        case MPV_EVENT_NONE:
            break;
        case MPV_EVENT_SHUTDOWN:
            break;
        case MPV_EVENT_LOG_MESSAGE:
            break;
        case MPV_EVENT_GET_PROPERTY_REPLY:
            break;
        case MPV_EVENT_SET_PROPERTY_REPLY:
            break;
        case MPV_EVENT_COMMAND_REPLY:
            break;
        case MPV_EVENT_START_FILE:
            break;
        case MPV_EVENT_END_FILE:
            onFinish();
            break;
        case MPV_EVENT_FILE_LOADED:
            break;
        case MPV_EVENT_TRACKS_CHANGED:
            break;
        case MPV_EVENT_TRACK_SWITCHED:
            break;
        case MPV_EVENT_IDLE:
            break;
        case MPV_EVENT_PAUSE:
            break;
        case MPV_EVENT_UNPAUSE:
            break;
        case MPV_EVENT_TICK:
            break;
        case MPV_EVENT_SCRIPT_INPUT_DISPATCH:
            break;
        case MPV_EVENT_CLIENT_MESSAGE:
            break;
        case MPV_EVENT_VIDEO_RECONFIG:
            break;
        case MPV_EVENT_AUDIO_RECONFIG:
            break;
        case MPV_EVENT_METADATA_UPDATE:
            break;
        case MPV_EVENT_SEEK:
            break;
        case MPV_EVENT_PLAYBACK_RESTART:
            break;
        case MPV_EVENT_CHAPTER_CHANGE:
            break;
        case MPV_EVENT_QUEUE_OVERFLOW:
            break;
    }
}

void Widget::fileOpen()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open file", "/home/song/Movie");
    if (mpv) {
        const QByteArray c_filename = filename.toUtf8();
        const char *args[] = {"loadfile", c_filename.data(), NULL};
        mpv_command_async(mpv, 0, args);
    }
}

void Widget::on_mpv_events()
{
    while (mpv) {
        mpv_event *event = mpv_wait_event(mpv, 0);
        if (event->event_id == MPV_EVENT_NONE)  //filter ahead
            break;
        handle_mpv_event(event);
    }
}

void Widget::command(const QVariant &params)
{
    mpv::qt::command_variant(mpv, params);
}

QVariant Widget::getProperty(const QString &name) const
{
    return mpv::qt::get_property_variant(mpv, name);
}

void Widget::setProperty(const QString &name, const QVariant &value)
{
    mpv::qt::set_property_variant(mpv, name, value);
}


void Widget::playFromExtern(QString filename)
{
    flag= true;
    if (mpv) {
        const QByteArray c_filename = filename.toUtf8();
        const char *args[] = {"loadfile", c_filename.data(), NULL};
        mpv_command_async(mpv, 0, args);
    }
}
void Widget::onFinish(void)
{
    if(flag){
        flag= false;
        emit jumpBack();
    }
}
























