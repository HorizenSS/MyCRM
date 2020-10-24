#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlDatabase>
#include<QSqlError>
class connection
{public:
    connection();
    bool initaliser(QSqlDatabase& db);
    void close_database(QSqlDatabase& db);


};

#endif // CONNECTION_H
