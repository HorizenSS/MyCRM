#ifndef RECLAMATIO_H
#define RECLAMATIO_H
#include <QMainWindow>
#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSystemTrayIcon>

class Reclamatio
{ private:
    QString nom;
    int code;
   QString lieu;
   QString date_reclamation;
   QString rec;
   long id;
   long ID_Vente;
public:
    Reclamatio();
    Reclamatio(QString,int,QString,QString,QString,long,long);
    bool ajouter_reclamation(Ui::MainWindow *ui);
    bool modifier_reclamation(Ui::MainWindow *ui);
    bool supprimer_reclamation(Ui::MainWindow *ui);
    bool afficher_reclamation(Ui::MainWindow *ui);
    bool rechercher_reclamation(Ui::MainWindow *ui);
    bool tri_reclamation(Ui::MainWindow *ui);
    QString get_nom(){return nom;}
    int vente(Ui::MainWindow *ui);
    int get_code(){return code;}
    QString get_lieu(){return lieu;}



};

#endif // RECLAMATIO_H
