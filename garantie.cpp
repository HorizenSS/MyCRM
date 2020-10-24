#include "garantie.h"
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
#include "smtp.h"


garantie::garantie()
{

NOM_CLIENT="";
NOM_OUV="";
NOM_SERVICE="";
ADRESS="";
ID_CLIENT=0;
ID_OUV=0;



}
garantie::garantie(long CS,QString NOM_SERVICE,QString NOM_OUV,long ID_OUV,QString NOM_CLIENT,long ID_CLIENT,QString ADRESS,QDate DATE_FIN){
    this->CS=CS;
    this->NOM_SERVICE=NOM_SERVICE;
    this->NOM_OUV=NOM_OUV;
    this->ID_OUV=ID_OUV;
    this->NOM_CLIENT=NOM_CLIENT;
    this->ID_CLIENT=ID_CLIENT;
    this->ADRESS=ADRESS;
    this->DATE_FIN=DATE_FIN;



}
/*bool garantie::ajouter_service_sous_garantie(Ui::MainWindow *ui){

    CS=ui->co_serv_g->text().toInt();
    NOM_SERVICE=ui->nom_serv_g->text();
    NOM_OUV=ui->nom_ouv_g->text();
    ID_OUV=ui->co_ouv_g->text().toInt();
    NOM_CLIENT=ui->nom_client_g->text();
    ID_CLIENT=ui->id_client_g->text().toInt();
     ADRESS=ui->adress_g->text();
     DATE_FIN=ui->date_g->date();
 QSqlQuery qry;
 qry.prepare("insert into garantie values (:CS,:NOM_SERVICE,:NOM_OUV,:ID_OUV,:NOM_CLIENT,:ID_CLIENT,:ADRESS,:DATE_FIN)");
 qry.bindValue(":CS",ui->co_serv_g->text());
  qry.bindValue(":NOM_SERVICE",NOM_SERVICE);
   qry.bindValue(":NOM_OUV",NOM_OUV);
    qry.bindValue(":ID_OUV",ui->co_ouv_g->text());
     qry.bindValue(":NOM_CLIENT",NOM_CLIENT);
      qry.bindValue(":ID_CLIENT",ui->id_client_g->text());
       qry.bindValue(":ADRESS",ADRESS);
         qry.bindValue(":DATE_FIN",DATE_FIN);
if(qry.exec())
{
ui->co_serv_g->setText("");
 ui->nom_serv_g->setText("");
    ui->nom_ouv_g->setText("");
      ui->co_ouv_g->setText("");
                  ui->nom_client_g->setText("");
                  ui->id_client_g->setText("");
                  ui->adress_g->setText("");




                 return true;
}
else
{
// QMessageBox::critical(this,("Error::"),qry.lastError().text());
                 return false;

}}
bool garantie::modifier(Ui::MainWindow *ui){

    CS=ui->co_serv_g2->text().toInt();
    NOM_SERVICE=ui->nom_serv_g2->text();
    NOM_OUV=ui->nom_ouv_g2->text();
    ID_OUV=ui->co_ouv_g2->text().toInt();
    NOM_CLIENT=ui->nom_client_g2->text();
    ID_CLIENT=ui->id_client_g2->text().toInt();
     ADRESS=ui->adress_g2->text();
        DATE_FIN=ui->dateg2->date();
     QSqlQuery qry;
   qry.prepare("update garantie set NOM_SERVICE=:NOM_SERVICE,NOM_OUV=:NOM_OUV,ID_OUV=:ID_OUV,NOM_CLIENT=:NOM_CLIENT,ID_CLIENT=:ID_CLIENT,ADRESS=:ADRESS,DATE_FIN=:DATE_FIN where CS=:CS");
   qry.bindValue(":CS",ui->co_serv_g2->text());
      qry.bindValue(":NOM_SERVICE",NOM_SERVICE);
         qry.bindValue(":NOM_OUV",NOM_OUV);
   qry.bindValue(":ID_OUV",ui->co_ouv_g2->text());
   qry.bindValue(":NOM_CLIENT",NOM_CLIENT);
   qry.bindValue(":ID_CLIENT",ui->id_client_g2->text());
    qry.bindValue(":ADRESS",ADRESS);
     qry.bindValue(":DATE_FIN",DATE_FIN);
    if(qry.exec())
    {
        ui->co_serv_g2->setText("");
         ui->nom_ouv_g2->setText("");
            ui->nom_serv_g2->setText("");
              ui->co_ouv_g2->setText("");
                 ui->nom_client_g2->setText("");
                   ui->id_client_g2->setText("");
                     ui->adress_g2->setText("");



        return true;
    }
    else return false;


}
*/
bool garantie::afficher(Ui::MainWindow *ui){
    QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery *qry=new QSqlQuery;
        qry->prepare("select ID_VENTE,TITRE,DATE_FGARANTIE from ventes");
       if(qry->exec())
       {
        modal->setQuery(*qry);
        ui->tablegarantie->setModel(modal);
        return true;}
       else
       {return false;}
}
bool garantie::rechercher(Ui::MainWindow *ui){
    QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery *qry=new QSqlQuery;
        qry->prepare("select ID_VENTE,TITRE,DATE_FGARANTIE FROM ventes where NOM_SERVICE like '"+ui->rechercher_g->text()+"%'");
       if(qry->exec())
       {
        modal->setQuery(*qry);
        ui->tablegarantie->setModel(modal);
        return true;}
       else
       {return false;}

}
bool garantie::tri(Ui::MainWindow *ui){
    QSqlQueryModel *modal=new QSqlQueryModel();
       QSqlQuery *qry=new QSqlQuery;
       qry->prepare("select ID_VENTE,TITRE,DATE_FGARANTIE from ventes ORDER BY DATE_FGARANTIE DESC");
      if(qry->exec())
      {
          modal->setQuery(*qry);
          ui->tablegarantie->setModel(modal);
          return true;}
         else
         {return false;}
}
bool garantie::actualiser(Ui::MainWindow *ui){
    QSqlQuery qry;
    Q=QDate::currentDate();
     qry.prepare("delete from garantie where DATE_FIN<=:d");
    qry.bindValue(":d",Q);

     if(qry.exec()){

         return true;


     }
     else {return false;}
}
bool garantie::tri_2(Ui::MainWindow *ui){
    QSqlQueryModel *modal=new QSqlQueryModel();
       QSqlQuery *qry=new QSqlQuery;
       qry->prepare("select ID_VENTE,TITRE,DATE_FGARANTIE from ventes ORDER BY DATE_FGARANTIE ASC");
      if(qry->exec())
      {
          modal->setQuery(*qry);
          ui->tablegarantie->setModel(modal);
          return true;}
         else
         {return false;}

}

