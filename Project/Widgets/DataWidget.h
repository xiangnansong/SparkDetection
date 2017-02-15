//
// Created by song on 4/10/16.
//

#ifndef PROJECT_DATAWIDGET_H
#define PROJECT_DATAWIDGET_H
#include <QTableView>
#include <QWidget>
#include <QSqlTableModel>
class DataWidget: public QWidget
{
Q_OBJECT
public:
    DataWidget(QWidget *parent = 0);
private:
    QTableView *tableView;
    QSqlTableModel *model;
protected slots:
    void updateTable();
};


#endif //PROJECT_DATAWIDGET_H
