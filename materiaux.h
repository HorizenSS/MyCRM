#ifndef MATERIAUX_H
#define MATERIAUX_H
#include <QString>
#include <iostream>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QMainWindow>
#include <QSqlQueryModel>
class Materiaux
{
private:
    long Code;
    QString Nom;
    int Qte;
    long CIN;
    QSystemTrayIcon *notification;
public:
    Materiaux();
    Materiaux(long,QString,int,long);
    void set_Code(long code){Code=code;}
    void set_Nom(QString nom){Nom=nom;}
    void set_Qte(int qte){Qte=qte;}

    long get_Code(){return Code;}
    QString get_Nom(){return Nom;}
    int get_Qte(){return Qte;}

    bool ajouter();
    bool modifier();
    bool supprimer();
    void afficher(Ui::MainWindow *ui);
    void notif(QString, QString, qint8);
    void a(Ui::MainWindow *ui);
    bool accorder();
    bool ajouterHistorique();
    void afficherHistorique(Ui::MainWindow *ui);
    bool supprimerHistorique();
    QSqlQueryModel* triQte();

};

#endif // MATERIAUX_H
