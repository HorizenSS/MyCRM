#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QString>
#include<QDate>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QMainWindow>
class client
{private:
    long CIN_client ;
    QString Nom_client ;
    QString Prenom_client ;
    int Age_client ;
    QDate Date_Naissance_client ;
    QString Sexe_client ;
    QString Mail_client ;
    QString Adresse_client ;
    QString Ville_client;
    int Code_postal_client ;
    int Points_client;
    long Telephone_client;
    int Coupon_client ;
    QString Message_client;

    int remise_client ;
     long ID_bouquet;


public:
    client();
    client(long , QString , QString , int , QDate, QString, QString, QString, int , int, long, int, QString, QString  , int,long );
    void saisir();
    void afficher();
    bool Ajouter_client(Ui::MainWindow *ui);
    bool Supprimer_client(Ui::MainWindow *ui);
    bool Modifier_client(Ui::MainWindow *ui);
    long getCIN_client(){return CIN_client ;};
    int getAge_client(){return Age_client ;};
    QString getNom_client(){return Nom_client;};
    QString getPrenom_client(){return Prenom_client;};
    QString getSexe_client(){return Sexe_client;};
    QString getMail_client(){return Mail_client;};
    QString getAdresse_client(){return Adresse_client;};
    QString getVille_client(){return Ville_client;};
    QString getMessage_client(){return Message_client;};
    QDate getDate_Naissance_client(){return Date_Naissance_client;};
    int getCode_postal_client(){return Code_postal_client ;};
    int getPoints_client(){return Points_client ;};
    int getCoupon_client(){return Coupon_client ;};
    long getTelephone_client(){return Telephone_client ;};
    int getRemise_client(){return remise_client ;};
     long getID_bouquet(){return ID_bouquet ;};

     void setID_bouquet (long ID_bouquet)
     {
          this->ID_bouquet=ID_bouquet;
     }
    void setNom_client (QString Nom_client)
    {
         this->Nom_client=Nom_client;
    }
    void setPrenom_client (QString prenom_client)
    {
         this->Prenom_client=prenom_client;
    }
    void setAge_client (int age_client)
    {
         this->Age_client=age_client;
    }
    void setCIN_client (long cin_client)
    {
         this->CIN_client=cin_client;
    }
    void setDate_Naissance_client (QDate Date_Naissance_client)
    {
         this->Date_Naissance_client=Date_Naissance_client;
    }
    void setSexe_client (QString Sexe_client)
    {
         this->Sexe_client=Sexe_client;
    }
    void setMail_client (QString Mail_client)
    {
         this->Mail_client=Mail_client;
    }
    void setAdresse_client (QString Adresse_client)
    {
         this->Adresse_client=Adresse_client;
    }
    void setVille_client (QString Ville_client)
    {
         this->Ville_client=Ville_client;
    }
    void setMessage_client (QString Message_client)
    {
         this->Message_client=Message_client;
    }
    void setCode_postal_client (int Code_postal_client)
    {
         this->Code_postal_client=Code_postal_client;
    }
    void setPoints_client (int Points_client)
    {
         this->Points_client=Points_client;
    }
    void setCoupon_client (int Coupon_client)
    {
         this->Coupon_client=Coupon_client;
    }
    void setTelephone_client (long Telephone_client)
    {
             this->Telephone_client=Telephone_client;
    }

    void setRemise_client (int remise_client)
    {
         this->remise_client=remise_client;
    }
};

#endif // CLIENT_H
