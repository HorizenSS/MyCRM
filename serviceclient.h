#ifndef SERVICECLIENT_H
#define SERVICECLIENT_H
#include<QString>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QTableView>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QColor>
#include <QPainter>
#include "ui_mainwindow.h"

#include <QMainWindow>

namespace Ui {
class serviceClient;
}

class serviceClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit serviceClient(QWidget *parent = 0);
    ~serviceClient();

private:
   // Ui::mainwindow *ui;
    Ui::MainWindow *ui;

private:

    QString nom_service;
    QString description;
    QString categorie;
    QString notes;

public:
   serviceClient();
   serviceClient(QString,QString,QString,QString);
QSqlQueryModel* afficherservice();

private slots:
void on_maxtab_clicked(const QModelIndex &index);
void on_sendmail_clicked();
void on_MaxService_activated(const QModelIndex &index);
void on_pushButton_clicked();
void on_pushButton_2_clicked();
void on_menu1_clicked();
};

#endif // SERVICECLIENT_H
