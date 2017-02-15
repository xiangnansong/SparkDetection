#include <QtWidgets/qapplication.h>
#include <Widgets/MainWidget.h>
#include "Widgets/ButtonBar.h"
#include "DataBase/SqlUtils.h"
#include "DataBase/TableBase.h"
#include "DataBase/Picture.h"
#include <QMutex>
QMutex mutex;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    setlocale(LC_NUMERIC, "C");
    TableBase tableBase;
    tableBase.sqlTableInit();
    MainWidget mainWidget;
    mainWidget.show();
    return a.exec();
}