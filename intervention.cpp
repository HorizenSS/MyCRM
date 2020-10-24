#include "intervention.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <iostream>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlError>
intervention::intervention()
{
CODE_OUV=0;
NOM_CLIENT="";
NOM_OUV="";
NOM_SERVICE="";
DEG="";
PRIX=0;

}
intervention::intervention(long CODE_OUV,long ID_CLIENT,long CI,QString NOM_CLIENT,QString NOM_OUV,QString NOM_SERVICE,QDate DATE_INTER,QString DEG,int PRIX)
{
this->CODE_OUV=CODE_OUV;
this->ID_CLIENT=ID_CLIENT;
this->CI=CI;
this->NOM_CLIENT=NOM_CLIENT;
this->NOM_OUV=NOM_OUV;
this->NOM_SERVICE=NOM_SERVICE;
this->DATE_INTER=DATE_INTER;
this->DEG=DEG;
this->PRIX=PRIX;
}
bool intervention::ajouter_intervention(Ui::MainWindow *ui)
{
    CI=ui->code_inter->text().toInt();
    CODE_OUV=ui->code_ouv->text().toInt();
    NOM_OUV=ui->nom_ouv->text();
    NOM_SERVICE=ui->nom_serv->text();
    NOM_CLIENT=ui->nom_client_2->text();
    ID_CLIENT=ui->id_client->text().toInt();
     DATE_INTER=ui->date_inter->date();
      DEG=ui->deg_pri->text();
      PRIX=ui->prix->text().toInt();
 QSqlQuery qry;
 qry.prepare("insert into intervention  values (:CI,:CODE_OUV,:NOM_OUV,:NOM_SERVICE,:NOM_CLIENT,:DATE_INTER,:ID_CLIENT,:DEG,:PRIX)");
 qry.bindValue(":CI",ui->code_inter->text());
  qry.bindValue(":CODE_OUV",ui->code_ouv->text());
   qry.bindValue(":NOM_OUV",NOM_OUV);
    qry.bindValue(":NOM_SERVICE",NOM_SERVICE);
     qry.bindValue(":NOM_CLIENT",NOM_CLIENT);
      qry.bindValue(":ID_CLIENT",ui->id_client->text());
       qry.bindValue(":DATE_INTER",DATE_INTER);
         qry.bindValue(":DEG",DEG);
          qry.bindValue(":PRIX",PRIX);
 if(qry.exec())
{

ui->code_inter->setText("");
 ui->code_ouv->setText("");
    ui->nom_ouv->setText("");
      ui->nom_serv->setText("");
                  ui->nom_client_2->setText("");
                  ui->id_client->setText("");
                  ui->deg_pri->setText("");
                  ui->prix->setText("");
                  return true;
}
else
{
// QMessageBox::critical(this,("Error::"),qry.lastError().text());
                 return false;

}}
bool intervention::modifier_intervention(Ui::MainWindow *ui){
    CI=ui->ci_2->text().toInt();
    CODE_OUV=ui->co_2->text().toInt();
    NOM_OUV=ui->nom_ouv_2->text();
    NOM_SERVICE=ui->nom_serv2->text();
    NOM_CLIENT=ui->nom_client_3->text();
    ID_CLIENT=ui->id_client_2->text().toInt();
     DATE_INTER=ui->date_inter_2->date();
      DEG=ui->deg_pri_2->text();
          QSqlQuery qry;
        qry.prepare("update intervention set CODE_OUV=:CODE_OUV,NOM_OUV=:NOM_OUV,NOM_SERVICE=:NOM_SERVICE,NOM_CLIENT=:NOM_CLIENT,ID_CLIENT=:ID_CLIENT,DATE_INTER=:DATE_INTER,DEG=:DEG where CI=:CI");
        qry.bindValue(":CI",ui->ci_2->text());
        qry.bindValue(":CODE_OUV",ui->co_2->text());
        qry.bindValue(":NOM_OUV",NOM_OUV);
        qry.bindValue(":NOM_SERVICE",NOM_SERVICE);
        qry.bindValue(":NOM_CLIENT",NOM_CLIENT);
        qry.bindValue(":DATE_INTER",DATE_INTER);
        qry.bindValue(":ID_CLIENT",ui->id_client_2->text());

          qry.bindValue(":DEG",DEG);
        if(qry.exec())
        {
            ui->ci_2->setText("");
             ui->co_2->setText("");
                ui->nom_ouv_2->setText("");
                  ui->nom_serv2->setText("");
                     ui->nom_client_3->setText("");
                       ui->id_client_2->setText("");
                         //ui->date_inter_2->setText("");
                           ui->deg_pri_2->setText("");

            return true;
        }
        else return false;


}
bool intervention::afficher_intervention(Ui::MainWindow *ui){
    QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery *qry=new QSqlQuery;
        qry->prepare("select * from intervention");
       if(qry->exec())
       {
        modal->setQuery(*qry);
        ui->tableView_3->setModel(modal);
        return true;}
       else
       {return false;}
}
bool intervention::supprimer_intervention(Ui::MainWindow *ui){
    QSqlQuery qry;
     qry.prepare("delete from intervention where CI=:CI");
    qry.bindValue(":CI",ui->id_inter_supp->text());
     if(qry.exec()){
         ui->id_inter_supp->setText(" ");

         return true;

     }
     else {return false;}

}

QVector<double> intervention::statstique(){

    QSqlQuery q;
        QVector<double> stat(3);
        stat[0]=0;
        stat[1]=0;
        stat[2]=0;

        q.prepare("SELECT * FROM intervention WHERE NOM_SERVICE='baby_sitter'");
        q.exec();
        while (q.next())
        {
            stat[0]++;
        }
        q.prepare("SELECT * FROM intervention WHERE NOM_SERVICE='jardiner'");
        q.exec();
        while (q.next())
        {
            stat[1]++;
            std::cout<<"..."<<std::endl;
        }
        q.prepare("SELECT * FROM intervention WHERE NOM_SERVICE='infermier'");
        q.exec();
        while (q.next())
        {
            stat[2]++;
        }

        return stat;
}
bool intervention::rechercher(Ui::MainWindow *ui){
    QSqlQueryModel *modal=new QSqlQueryModel();
        QSqlQuery *qry=new QSqlQuery;
        qry->prepare("select CI,CODE_OUV,ID_CLIENT,NOM_CLIENT,NOM_SERVICE,NOM_OUV,DEG,DATE_INTER FROM intervention where NOM_SERVICE like '"+ui->rechecher_inter->text()+"%'");
       if(qry->exec())
       {
        modal->setQuery(*qry);
        ui->tableView_3->setModel(modal);
        return true;}
       else
       {return false;}

}
bool intervention::tri_intervention(Ui::MainWindow *ui){
    QSqlQueryModel *modal=new QSqlQueryModel();
       QSqlQuery *qry=new QSqlQuery;
       qry->prepare("select * from intervention ORDER BY DEG ASC");
      if(qry->exec())
      {
          modal->setQuery(*qry);
          ui->tableView_3->setModel(modal);
          return true;}
         else
         {return false;}
}
