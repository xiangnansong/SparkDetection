//
// Created by song on 4/10/16.
//

#include "DataWidget.h"
#include "DataBase/SqlUtils.h"
#include <QVBoxLayout>
#include <QPushButton>
DataWidget::DataWidget(QWidget *parent)
{
    QVBoxLayout *mainlayout = new QVBoxLayout(this);


    QHBoxLayout* qhBoxLayout = new QHBoxLayout;
    qhBoxLayout->addStretch();
    QPushButton* pushButton = new QPushButton("刷新");
    pushButton->setMaximumWidth(100);

    tableView = new QTableView(this);
    qhBoxLayout->addWidget(pushButton);

    qhBoxLayout->addStretch();
    mainlayout->addLayout(qhBoxLayout);
    mainlayout->addWidget(tableView);
    model = new QSqlTableModel(this, SqlUtils::getDb());
    model->setTable("result");
    model->select();
    // 设置编辑策略
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    tableView->setModel(model);
    connect(pushButton,SIGNAL(clicked()),this,SLOT(updateTable()));
}
void DataWidget::updateTable()
{
    model->select();
}





