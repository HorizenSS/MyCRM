#include "rendezvous.h"
#include <QSqlQuery>
#include <iostream>
#include <QSqlQueryModel>
#include <QVector>
Rendezvous::Rendezvous()
{
  CRV=0;
  CIN=0;
  DRV=QDateTime::currentDateTime();
  //HRV=QTime::currentTime();



}
Rendezvous::Rendezvous(QDateTime DRV, long CIN, long CRV)
{
    this->CRV=CRV;
    this->CIN=CIN;
    this->DRV=DRV;
   // this->HRV=HRV;

}
bool Rendezvous::ajouter(Ui::MainWindow *ui)
{
    QSqlQuery q;
    q.prepare("insert into RV values (:CRV,:DRV,:CIN)");
    q.bindValue(":CRV",ui->codeRV->text());
    q.bindValue(":CIN",ui->ouvrierRV->text());
     QString a;
    a=ui->dateTimeEdit->dateTime().toString("dd'-'MM'-'yyyy' 'hh:mm");

    q.bindValue(":DRV",a);




    if (    q.exec())
    {
        std::cout << "Ça marche ! 🙂" << std::endl;
        ui->codeRV->setText("");
        ui->ouvrierRV->setText("");


        return true;
    }
    else
    {
        std::cout<< "Ça marche pas ! 😞" <<std::endl;
        return false;

    }

}
bool Rendezvous::supprimer(Ui::MainWindow *ui)
{

    QSqlQuery q;
    //QString a=QString::number(ui->tableRV->model()->data(ui->tableRV->model()->index(ui->tableRV->selectionModel()->currentIndex().row(),0)));
    long a=ui->tableRV->model()->data(ui->tableRV->model()->index(ui->tableRV->selectionModel()->currentIndex().row(),0)).toInt();
    q.prepare("DELETE FROM RV WHERE CODE_RV=:CRV");
    q.bindValue(":CRV",QString::number(a));
    if(q.exec())
    {
        return true;
    }
    else return false;

}
bool Rendezvous::modifier(Ui::MainWindow *ui)
{
    QSqlQuery q;


    CRV=ui->codeRV_2->text().toInt();
   // DRV=ui->dateTimeEdit_2->dateTime();
    CIN=ui->ouvrierRV_2->text().toInt();
    q.prepare("update RV set DATE_RV=:date,CIN=:CIN where CODE_RV=:code");
    q.bindValue(":code",QString::number(CRV));
    q.bindValue(":CIN",QString::number(CIN));
    QString a;
    a=ui->dateTimeEdit_2->dateTime().toString("dd'-'MM'-'yyyy' 'hh:mm");
    q.bindValue(":date",a);


      if(q.exec())
    {
        return true;
    }
    else return false;
}
void Rendezvous::afficher(Ui::MainWindow *ui)
{
    QDateTime d;
    QSqlQueryModel *modal=new QSqlQueryModel();
   QSqlQuery q;
   q.prepare("select * from RV");
   q.exec();
   while(q.next())
   {
       d=QDateTime::fromString(q.value(1).toString(),"yyyy'-'MM'-'dd'T'hh:mm:ss");
       modal->setQuery(q);

        ui->tableRV->setModel(modal);

   }
   modal->setQuery(q);

    ui->tableRV->setModel(modal);

}

bool Rendezvous::ajouterHistorique()
{
    QSqlQuery q;
    QString d=DRV.toString("dd'-'MM'-'yyyy' 'hh:mm");



    QString a=QDateTime::currentDateTime().toString("dd'-'MM'-'yyyy' 'hh:mm");

    q.prepare("insert into HISTORIQUE_R VALUES (:CODE,:DATE_RV,:CIN,:TYPE,:DATE)");
    q.bindValue(":CODE",QString::number(CRV));
     q.bindValue(":DATE_RV",d);
    q.bindValue(":CIN",QString::number(CIN));
    q.bindValue(":TYPE","Rendez Vous");
    q.bindValue(":DATE",a);
    if (    q.exec())
    {
        std::cout << "Ça marche ! 🙂" << std::endl;

        qDebug()<<"eyy";

        return true;
    }
    else
    {
        std::cout<< "Ça marche pas ! 😞" <<std::endl;
        return false;

    }
}
void Rendezvous::afficherHistorique(Ui::MainWindow *ui)
{

    QSqlQueryModel *modal=new QSqlQueryModel();
   QSqlQuery q;
   q.prepare("select * from HISTORIQUE_R");
   q.exec();
   modal->setQuery(q);
   ui->TableHR->setModel(modal);
}

bool Rendezvous::supprimerHistorique()
{

    QSqlQuery q;
    q.prepare("DELETE FROM HISTORIQUE_R WHERE CODE=:CODE");
    q.bindValue(":CODE",QString::number(CRV));
    if(q.exec())
    {
        return true;
    }
    else return false;

}
