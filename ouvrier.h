#ifndef OUVRIER_H
#define OUVRIER_H
#include <QString>
#include <iostream>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QMainWindow>
#include <QChar>
#include <QSqlQueryModel>

class Ouvrier
{
private:
   QString CIN;
   QString Nom;
   QString Prenom;
   int Age;
   long Telephone;
   QString Adresse;
   QString Sexe;
   QString Specialite;
   QString Email;



public:
    Ouvrier();
    Ouvrier(QString,QString,QString,int,long,QString,QString,QString,QString);
    void set_CIN(QString cin){CIN=cin;}
    void set_Nom(QString nom){Nom=nom;}
    void set_Prenom(QString prenom){Prenom=prenom;}
    void set_Age(int age){Age=age;}
    void set_Telephone(long tel){Telephone=tel;}
    void set_Adresse(QString adresse){Adresse=adresse;}
    void set_Sexe(QString sexe){Sexe=sexe;}
    void set_Specialite(QString specialite){Specialite=specialite;}
    void set_Email(QString email){Email=email;}


    QString get_CIN(){return CIN;}
    QString get_Nom(){return Nom;}
    QString get_Prenom(){return Prenom;}
    int get_Age(){return Age;}
    long get_Telephone(){return Telephone;}
    QString get_Adresse(){return Adresse;}
    QString get_Sexe(){return Sexe;}
    QString get_Specialite(){return Specialite;}
    QString get_Email(){return Email;}


          bool ajouter();
          bool modifier();
          bool supprimer();
          void afficher(Ui::MainWindow *ui);
          void aff(Ui::MainWindow *ui);
           QVector<double> statistique();
           bool ajouterHistorique();
           void afficherHistorique(Ui::MainWindow *ui);
           bool supprimerHistorique();
           void makePlot(QCustomPlot *customPlot);
           QSqlQueryModel* triNom();
           QSqlQueryModel* triSpecialite();





};

#endif // OUVRIER_H
