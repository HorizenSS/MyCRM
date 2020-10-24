#include "mainwindow.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

  /*db.setDatabaseName("mybasefinal");
    db.setUserName("ines");
    db.setPassword("123");*/
    db.setHostName("sweet");
        db.setDatabaseName("mybasefinal");
        db.setUserName("ines");
        db.setPassword("123");
    if(db.open()==true)
        qDebug("Connected...");
        //qDebug(5);
    else qDebug("Failed to connect to the database...");
     MainWindow w;
    w.show();

    return a.exec();
}
