#include <connection.h>

connection::connection()
{}

bool connection::initaliser(QSqlDatabase &db)
{
   // QSqlError a;

    db= QSqlDatabase::addDatabase("QODBC");
    db.setHostName("sweet");
    db.setDatabaseName("mybasefinal");
    db.setUserName("ines");
    db.setPassword("123");
    if (!db.open())
    {
        qDebug()<<"Failed to open db";

        return false;
    }
    else
    {
        qDebug()<<"db opened";
        return true;
    }
}
void connection::close_database(QSqlDatabase& db)
{
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
}
