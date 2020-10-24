#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H


#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QString>
#include<QDate>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QMainWindow>
class fournisseur
{private:
    long ID_fournisseur ;
    QString Nom_fournisseur ;
    QString matiere_fournisseur ;
    QString Mail_fournisseur ;
    QString Adresse_fournisseur ;
    QString Ville_fournisseur;
    int Code_postal_fournisseur ;
    long Telephone_fournisseur;
    QString Message_fournisseur ;
    QDate Date_ajout;


public:
    fournisseur();
    fournisseur(long , QString , QString, QString, QString, QString ,int , long ,QString);
    bool Ajouter_fournisseur(Ui::MainWindow *ui);
    bool Supprimer_fournisseur(Ui::MainWindow *ui);
    bool Modifier_fournisseur(Ui::MainWindow *ui);
    long getID_fournisseur(){return ID_fournisseur ;};
    QString getNom_fournisseur(){return Nom_fournisseur;};
    QString getmatiere_fournisseur(){return matiere_fournisseur;};
    QString getMail_fournisseur(){return Mail_fournisseur;};
    QString getAdresse_fournisseur(){return Adresse_fournisseur;};
    QString getVille_fournisseur(){return Ville_fournisseur;};
    int getCode_postal_fournisseur(){return Code_postal_fournisseur ;};
    long getTelephone_fournisseur(){return Telephone_fournisseur ;};
    QString getMessage_fournisseur(){return Message_fournisseur;};
    QDate getdate_ajout(){return Date_ajout;};

    void setNom_fournisseur (QString Nom_fournisseur)
    {
         this->Nom_fournisseur=Nom_fournisseur;
    }
    void setmatiere_fournisseur (QString matiere_fournisseur)
    {
         this->matiere_fournisseur=matiere_fournisseur;
    }

    void setID_fournisseur (long ID_fournisseur)
    {
         this->ID_fournisseur=ID_fournisseur;
    }

    void setMail_fournisseur (QString Mail_fournisseur)
    {
         this->Mail_fournisseur=Mail_fournisseur;
    }
    void setAdresse_fournisseur (QString Adresse_fournisseur)
    {
         this->Adresse_fournisseur=Adresse_fournisseur;
    }
    void setVille_fournisseur (QString Ville_fournisseur)
    {
         this->Ville_fournisseur=Ville_fournisseur;
    }

    void setCode_postal_fournisseur (int Code_postal_fournisseur)
    {
         this->Code_postal_fournisseur=Code_postal_fournisseur;
    }
    void setTelephone_fournisseur (long Telephone_fournisseur)
    {
             this->Telephone_fournisseur=Telephone_fournisseur;
    }
    void setMessage_fournisseur (QString Message_fournisseur)
    {
         this->Message_fournisseur=Message_fournisseur;
    }
    void setdate_ajout (QDate date_ajout )
    {
         this->Date_ajout=date_ajout;
    }
};

#endif // FOURNISSEUR_H
