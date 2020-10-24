#include "materiaux.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"
Materiaux::Materiaux()
{
    Code=0;
    Nom="";
    Qte=0;
    CIN=0;
}
Materiaux::Materiaux(long Code,QString Nom,int Qte,long CIN)
{
    this->Code=Code;
    this->Nom=Nom;
   this->Qte=Qte;
    this->CIN=CIN;
}
bool Materiaux::ajouter()
{

    QSqlQuery q;
    q.prepare("insert into MATERIAUX (CODE,NOM,QTE) VALUES (:CODE,:NOM,:QTE)");
    q.bindValue(":CODE",QString::number(Code));
    q.bindValue(":NOM",Nom);
    q.bindValue(":QTE",QString::number(Qte));
    if (q.exec())
    {
        std::cout << "Ça marche ! 🙂" << std::endl;



        return true;
    }
    else
    {
        std::cout<< "Ça marche pas ! 😞" <<std::endl;
        return false;

    }

}
bool Materiaux::supprimer()
{
    QSqlQuery q;
    q.prepare("DELETE FROM MATERIAUX WHERE CODE =:CODE");
    q.bindValue(":CODE",QString::number(Code));
    if(q.exec())
    {
        return true;
    }
    else return false;

}
bool Materiaux::modifier()
{

    QSqlQuery q;
    q.prepare("update MATERIAUX set NOM=:NOM,QTE=:QTE where CODE=:CODE");

    q.bindValue(":CODE",QString::number(Code));
    q.bindValue(":NOM",Nom);
    q.bindValue(":QTE",QString::number(Qte));

      if(q.exec())
    {
        return true;
    }
    else return false;
}
void Materiaux::afficher(Ui::MainWindow *ui)
{

            QSqlQueryModel *modal=new QSqlQueryModel();
           QSqlQuery q;
           q.prepare("select * from MATERIAUX");
           q.exec();
           modal->setQuery(q);
           ui->tableMateriaux->setModel(modal);

}
void Materiaux::notif(QString text,QString titre,qint8 duree)
{
    Ui::MainWindow *ui;
    if(ui->tableMateriaux->selectionModel()->hasSelection())
    {
        if((ui->tableMateriaux->model()->data(ui->tableMateriaux->model()->index(ui->tableMateriaux->selectionModel()->currentIndex().row(),2)).toInt())<=2)

        {

        }
    }
}
void Materiaux::a(Ui::MainWindow *ui)
{
    QSqlQuery q;
    QString a=ui->tableMateriaux->model()->data(ui->tableMateriaux->model()->index(ui->tableMateriaux->selectionModel()->currentIndex().row(),0)).toString();
    q.prepare("select * from MATERIAUX where Code='"+ui->tableMateriaux->model()->data(ui->tableMateriaux->model()->index(ui->tableMateriaux->selectionModel()->currentIndex().row(),0)).toString()+"'");
//    q.prepare("select * from MATERIAUX where Code=:CODE");
//    q.bindValue();
    q.exec();
    q.next();
    ui->codemat->setText(q.value(0).toString());
    ui->nommat->setText(q.value(1).toString());
    ui->qtemat->setText(q.value(2).toString());
    ui->a->setText(q.value(3).toString());

}
bool Materiaux::accorder()
{
    QSqlQuery q;


//    Code=ui->code_3->text().toInt();
//    Nom=ui->nom_3->text();
//    Qte=ui->qte_3->text().toInt();
//    CIN=ui->accorde->text().toInt();


    q.prepare("update MATERIAUX set NOM=:NOM,QTE=:QTE,CIN=:CIN where CODE=:CODE");

    q.bindValue(":CODE",QString::number(Code));
    q.bindValue(":NOM",Nom);
    q.bindValue(":QTE",QString::number(Qte));
    q.bindValue(":CIN",QString::number(CIN));

      if(q.exec())
    {
        return true;
    }
    else return false;
}
bool Materiaux::ajouterHistorique()
{
   QSqlQuery q;

    QString a=QDateTime::currentDateTime().toString("dd'-'MM'-'yyyy' 'hh:mm");
    q.prepare("insert into HISTORIQUE_M VALUES (:CODE,:NOM,:QTE,:TYPE,:DATE)");
    q.bindValue(":CODE",QString::number(Code));
    q.bindValue(":NOM",Nom);
    q.bindValue(":QTE",Qte);
    q.bindValue(":TYPE","MATERIEL");
    q.bindValue(":DATE",a);
    if (    q.exec())
    {
        std::cout << "Ça marche ! 🙂" << std::endl;



        return true;
    }
    else
    {
        std::cout<< "Ça marche pas ! 😞" <<std::endl;
        return false;

    }
}
void Materiaux::afficherHistorique(Ui::MainWindow *ui)
{

    QSqlQueryModel *modal=new QSqlQueryModel();
   QSqlQuery q;
   q.prepare("select * from HISTORIQUE_M");
   q.exec();
   modal->setQuery(q);
   ui->TableHM->setModel(modal);
}
bool Materiaux::supprimerHistorique()
{

    QSqlQuery q;
    q.prepare("DELETE FROM HISTORIQUE_M WHERE CODE=:CODE");
    q.bindValue(":CODE",QString::number(Code));
    if(q.exec())
    {
        return true;
    }
    else return false;

}
QSqlQueryModel* Materiaux::triQte()
{
    QSqlQuery q;
     QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select * from MATERIAUX order by QTE desc");
    q.exec();
    modal->setQuery(q);
    return modal;
}
