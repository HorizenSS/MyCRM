#include "client.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include<QSqlError>
#include <QtSql/QSqlDatabase>

client::client()
{
    Nom_client="";
    Prenom_client="";
     Adresse_client="";
     Ville_client="";
     Message_client="";
     Code_postal_client=0;
     Points_client=0;
     Coupon_client=0;
     Telephone_client=0;
     remise_client=0;
     ID_bouquet=0;
}

client::client(long cin_client , QString Nom_client , QString Prenom_client , int Age_client, QDate Date_Naissance_client, QString Sexe_client, QString Mail_client, QString Adresse_client, int Points_client, int Coupon_client,long Telephone_client, int Code_postal_client, QString Ville_client, QString Message_client,int remise_client,long ID_bouquet)
{
   this->Nom_client=Nom_client;
   this->Prenom_client=Prenom_client;
   this->Age_client=Age_client;
    this->CIN_client=cin_client;
    this->Date_Naissance_client=Date_Naissance_client;
    this->Sexe_client=Sexe_client;
    this->Mail_client=Mail_client;
    this->Adresse_client=Adresse_client;
    this->Ville_client=Ville_client;
    this->Message_client=Message_client;
    this->Code_postal_client=Code_postal_client;
    this->Points_client=Points_client;
    this->Coupon_client=Coupon_client;
    this->Telephone_client=Telephone_client;
    this->remise_client=remise_client;

    this->ID_bouquet=ID_bouquet;


}
bool client::Ajouter_client(Ui::MainWindow *ui)
{
    setCIN_client(ui->CIN_client->text().toLong());
    setNom_client(ui->nom_client->text());
    setPrenom_client(ui->prenom_client->text());
    setAdresse_client(ui->adresse_client->text());
    setDate_Naissance_client(ui->date_naissance_client->date());
    setCode_postal_client(ui->code_client->text().toInt());
    setMail_client(ui->mail_client->text());
    setSexe_client(ui->sexe_client->text());
    setTelephone_client(ui->telephone_client->text().toLong());
    setVille_client(ui->ville_client->text());
QSqlQuery query;

           query.prepare("INSERT INTO CLIENT (CIN, NOM, PRENOM ,ADRESSE,DATE_NAISS,SEXE,VILLE,CODE_POSTAL,MAIL,TELEPHONE) "
                         "VALUES (?,?,?,?,?,?,?,?,?,?)");
        query.addBindValue(QString::number(getCIN_client()));
        query.addBindValue(getNom_client());
        query.addBindValue(getPrenom_client());
        query.addBindValue(getAdresse_client());
        query.addBindValue(getDate_Naissance_client());
        query.addBindValue(getSexe_client());
        query.addBindValue(getVille_client());
        query.addBindValue(QString::number( getCode_postal_client()));
        query.addBindValue(getMail_client());
        query.addBindValue(QString::number(getTelephone_client()));

            query.exec();
            return true ;
}
bool client::Modifier_client(Ui::MainWindow *ui)
{
    QSqlQuery qry ;
       qry.prepare("UPDATE CLIENT SET MAIL =? , ADRESSE= ? , VILLE=?, CODE_POSTAL=? , TELEPHONE = ?  WHERE CIN = ?");
        qry.bindValue(0,ui->Mail_modif->text());
       qry.bindValue(2,ui->Ville_modif->text());
       qry.bindValue(1,ui->Adresse_modif->text());
       qry.bindValue(3,ui->Code_modif->text());
              qry.bindValue(4,ui->Tel_modif->text().toInt());
              qry.bindValue(5,ui->label_cin->text().toInt());
              if(qry.exec())
              {
                  return true ;

              }



}
bool client::Supprimer_client(Ui::MainWindow *ui)
{
    QSqlQuery qry ;


                qry.prepare("delete from CLIENT where CIN=?");
                qry.addBindValue(ui->label_cin->text());
               if (qry.exec())
               {
                   return true ;
               }
               else
                   return false ;
}
