#ifndef SERVICE_H
#define SERVICE_H

#include "mainwindow.h"

#include <QString>
#include <QLineEdit>
#include <iostream>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>

class Service
{
public:
    Service();
    Service(QString nom,QString description,QString categorie,QString notes);
    bool ConfirmerAjout(Ui::MainWindow * ui,MainWindow* parent);
    bool addToTable();
    void searchInTable(Ui::MainWindow * ui, QString a);
    bool supprimerService(Ui::MainWindow * ui);
    bool deleteFromTable(QString c);
    bool modifierService(Ui::MainWindow* ui);
    bool ConfirmerModifier(Ui::MainWindow* ui,MainWindow* parent);




private :
    QString nom;
    QString description;
    QString categorie;
    QString notes;

};

#endif // SERVICE_H
