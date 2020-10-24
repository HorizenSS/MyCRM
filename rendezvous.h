#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H

#include <QDateTime>
#include "ui_mainwindow.h"
#include "mainwindow.h"
//#include <QDate>
//#include <QTime>
class Rendezvous
{
private:
   long CIN;
   long CRV;
   QDateTime DRV;


public:
    Rendezvous();
    Rendezvous(QDateTime, long, long);
    bool ajouter(Ui::MainWindow *ui);
    QDateTime get_date(){return DRV;}
    long get_cin(){return CIN;}
    long get_crv(){return CRV;}
    void set_date(QDateTime t){DRV=t;}
    void set_cin(long cin){CIN=cin;}
    void set_crv(long crv){CRV=crv;}
    bool supprimer(Ui::MainWindow *ui);
    bool modifier(Ui::MainWindow *ui);
    void afficher(Ui::MainWindow *ui);
    bool ajouterHistorique();
    void afficherHistorique(Ui::MainWindow *ui);
    bool supprimerHistorique();


};

#endif // RENDEZVOUS_H
