#include "reclamatio.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <iostream>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDate>
#include <QDateEdit>
#include <QDateTime>
#include <QSystemTrayIcon>
Reclamatio::Reclamatio()
{
nom=" ";
code=0;
lieu="";
date_reclamation="";
rec="";
id=0;
ID_Vente=0;
}
Reclamatio::Reclamatio(QString nom, int code, QString lieu, QString date_reclamation,QString rec,long id,long ID_Vente){

    this->id=id;
    this->nom=nom;
    this->code=code;
    this->date_reclamation=date_reclamation;
    this->lieu=lieu;
    this->rec=rec;
    this->ID_Vente=ID_Vente;

}
bool Reclamatio::ajouter_reclamation(Ui::MainWindow *ui)
{
        id=ui->id_rec->text().toInt();
        nom=ui->nom_rec->text();
         code=ui->code_rec->text().toInt();
         date_reclamation=ui->date_rec->text();
         lieu=ui->lieu_rec->text();
        rec=ui->rec_rec->text();
          ID_Vente=ui->id_vente->text().toInt();

        QSqlQuery qry;

        qry.prepare("insert into reclamation values (:id,:nom,:code,:DATE_RECLAMATION,:lieu,:rec,:ID_Vente)");
         qry.bindValue(":id",ui->id_rec->text());
        qry.bindValue(":nom",nom);
          qry.bindValue(":code",ui->code_rec->text());
          qry.bindValue(":DATE_RECLAMATION",date_reclamation);
              qry.bindValue(":lieu",lieu);
                qry.bindValue(":rec",rec);
             qry.bindValue(":ID_Vente",ui->id_vente->text());

if(qry.exec())
{

       ui->nom_rec->setText("");
         ui->id_rec->setText("");
           ui->rec_rec->setText("");
             ui->code_rec->setText("");
              ui->lieu_rec->setText("");
                           ui->id_vente->setText("");
                            ui->date_rec->setText("");
                        return true;
}
else
    {
//    QMessageBox::critical(this,tr("error"),tr("chek les valeurs!"));

       //QMessageBox::critical(this,("Error::"),qry.lastError().text());
                        return false;

    }

}

bool Reclamatio::modifier_reclamation(Ui::MainWindow *ui){
    lieu=(ui->lieu_2->text());
    id=(ui->id_2->text().toInt());
        code=(ui->code_4->text().toInt());
        nom=(ui->nom_rec_2->text());
        date_reclamation=(ui->date_rec_2->text());
        rec=(ui->rec_2->text());

          QSqlQuery qry;
        qry.prepare("update reclamation set NOM=:nom,DATE_RECLAMATION=:date_reclamation,LIEU=:lieu,CODE=:code,REC=:rec where id=:id");
        qry.bindValue(":id",ui->id_2->text());
        qry.bindValue(":nom",nom);
        qry.bindValue(":lieu",lieu);
        qry.bindValue(":code",code);
        qry.bindValue(":rec",rec);
        qry.bindValue(":date_reclamation",date_reclamation);
        if(qry.exec())
        {
             ui->id_2->setText("");
            ui->lieu_2->setText("");
            ui->code_4->setText("");
            ui->nom_rec_2->setText("");
            ui->rec_2->setText("");
            ui->date_rec_2->setText("");

            return true;
        }
        else return false;


}
bool Reclamatio::afficher_reclamation(Ui::MainWindow *ui){
    QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery *qry=new QSqlQuery;
        qry->prepare("select * from reclamation");
       if(qry->exec())
       {
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
        return true;}
       else
       {return false;}

}
bool Reclamatio::supprimer_reclamation(Ui::MainWindow *ui){
    QSqlQuery qry;
     qry.prepare("delete from reclamation where id=:id");
    qry.bindValue(":id",ui->id_supp->text());
     if(qry.exec()){
         ui->id_supp->setText(" ");

         return true;

     }
     else {return false;}



}
bool Reclamatio::rechercher_reclamation(Ui::MainWindow *ui){
    QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery *qry=new QSqlQuery;
        qry->prepare("select *  FROM RECLAMATION where NOM like '"+ui->rechercher_rec->text()+"%'");
       if(qry->exec())
       {
        modal->setQuery(*qry);
        ui->tableView_2->setModel(modal);
        return true;}
       else
       {return false;}


}
bool Reclamatio::tri_reclamation(Ui::MainWindow *ui)
{ QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery *qry=new QSqlQuery;
    qry->prepare("select * from reclamation ORDER BY NOM ASC");
   if(qry->exec())
   {
       modal->setQuery(*qry);
       ui->tableView->setModel(modal);
       return true;}
      else
      {return false;}
}
int Reclamatio::vente(Ui::MainWindow *ui)
{  QSqlQuery q;
    q.prepare("select ETAT from VENTES where ID_VENTE=:ID_Vente");
    q.bindValue(":ID_Vente",ui->id_vente->text());
    QString e="garantiee";
   int  x = QString::compare(e, q.value(5).toString(), Qt::CaseInsensitive);
     return x;
}
