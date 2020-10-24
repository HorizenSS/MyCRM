#ifndef PISTEOPP_H
#define PISTEOPP_H

#include "mainwindow.h"

#include <QString>
#include <QVector>
#include <QDate>
#include <QLineEdit>
#include <iostream>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>


class PisteOpp
{
private :
    int ID_Piste;
    int ID_Contact;
    int pertinence;

    QString titre;
    QString description;
    QDate date;
    QVector <QString> activites;
    QString notes;
    QString etat;
    QString type;




public:
    PisteOpp();
    PisteOpp(int a,int b, int c, QString d , QDate e,QString f,QString g,QString h,QString i);
    bool ConfirmerAjout(Ui::MainWindow * ui, MainWindow *parent);
    bool addToTable();
    void searchInTablePistes(Ui::MainWindow * ui, QString a);
    void searchInTableOpp(Ui::MainWindow * ui, QString a);
    bool supprimerPiste(Ui::MainWindow * ui);
    bool supprimerOpp(Ui::MainWindow * ui);
    bool deleteFromTable(QString c);
    bool modifierPiste(Ui::MainWindow* ui);
    bool modifierOpp(Ui::MainWindow* ui);
    bool ConfirmerModifier(Ui::MainWindow* ui, MainWindow * parent);










};

#endif // PISTEOPP_H
