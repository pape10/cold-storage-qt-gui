#include "mainwindow.h"
#include <QApplication>
#include "user.h"
#include "user_admin.h"
int user_admin::user_admin_id;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
