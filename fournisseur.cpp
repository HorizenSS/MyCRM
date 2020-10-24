#include "fournisseur.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include<QSqlError>
#include <QtSql/QSqlDatabase>

fournisseur::fournisseur()
{
     Nom_fournisseur="";
     Adresse_fournisseur="";
     Ville_fournisseur="";
     matiere_fournisseur="";
     Code_postal_fournisseur=0;
     Telephone_fournisseur=0;
}

fournisseur::fournisseur(long ID_fournisseur , QString Nom_fournisseur , QString Mail_fournisseur, QString Adresse_fournisseur,QString matiere_fournisseur, QString Ville_fournisseur, int Code_postal_fournisseur, long Telephone_fournisseur, QString Message_fournisseur )
{
    this->Nom_fournisseur=Nom_fournisseur;
    this->ID_fournisseur=ID_fournisseur;
    this->Mail_fournisseur=Mail_fournisseur;
    this->Adresse_fournisseur=Adresse_fournisseur;
    this->Ville_fournisseur=Ville_fournisseur;
    this->Code_postal_fournisseur=Code_postal_fournisseur;
    this->Telephone_fournisseur=Telephone_fournisseur;
    this->matiere_fournisseur=matiere_fournisseur;
    this->Message_fournisseur=Message_fournisseur;
}
bool fournisseur::Ajouter_fournisseur(Ui::MainWindow *ui)
{
    setID_fournisseur(ui->id_fournisseur_3->text().toLong());
    setNom_fournisseur(ui->nom_fournisseur_3->text());
    setmatiere_fournisseur(ui->matiere_fournisseur_3->text());
    setAdresse_fournisseur(ui->adresse_fournisseur_3->text());
    setCode_postal_fournisseur(ui->code_pos_fournisseur_3->text().toInt());
    setMail_fournisseur(ui->mail_fournisseur_3->text());
    setTelephone_fournisseur(ui->tel_fournisseur_3->text().toLong());
    setVille_fournisseur(ui->ville_fournisseur_3->text());
QSqlQuery query;

           query.prepare("INSERT INTO FOURNISSEUR (ID, NOM, MATIERE,TELEPHONE,MAIL,VILLE,CODE_POSTAL,ADRESSE) "
                         "VALUES (?,?,?,?,?,?,?,?)");
        query.addBindValue(QString::number(getID_fournisseur()));
        query.addBindValue(getNom_fournisseur());
        query.addBindValue(getmatiere_fournisseur());
        query.addBindValue(QString::number(getTelephone_fournisseur()));
        query.addBindValue(getMail_fournisseur());
        query.addBindValue(getVille_fournisseur());
        query.addBindValue(QString::number( getCode_postal_fournisseur()));
        query.addBindValue(getAdresse_fournisseur());
            query.exec();
            qDebug()<<query.exec();
            return true ;

}
bool fournisseur::Modifier_fournisseur(Ui::MainWindow *ui)
{
    QSqlQuery qry ;

       qry.prepare("UPDATE FOURNISSEUR SET MAIL =? , ADRESSE= ? , VILLE=?, CODE_POSTAL=? , TELEPHONE = ?,MATIERE = ?   WHERE ID= ?");
       qry.bindValue(0,ui->Mail_modif_four->text());
       qry.bindValue(2,ui->Ville_modif_four->text());
       qry.bindValue(1,ui->Adresse_modif_four->text());
       qry.bindValue(3,ui->Code_modif_four->text());
       qry.bindValue(4,ui->Tel_modif_four->text().toInt());
       qry.bindValue(5,ui->Matiere_modif_four->text());
       qry.bindValue(6,ui->label_id_fournisseur->text().toInt());

                if(qry.exec())
                {
                    return true ;
                }
                else
                    return false ;

}


bool fournisseur::Supprimer_fournisseur(Ui::MainWindow *ui)

{
    QSqlQuery qry ;


                qry.prepare("delete from FOURNISSEUR where ID=?");
                qry.addBindValue(ui->label_id_fournisseur->text());
               if (qry.exec())
               {
                   return true ;
               }
               else
                   return false ;

}
