#include "login.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>
#include "ui_mainwindow.h"
#include <QTextStream>
#include <iostream>
#include "qmessagebox.h"
#include <QObject>
#include "mainwindow.h"

Login::Login()
{
    code="";
    type="";
    pseudo="";
    MotDePasse="";
}
Login::Login(QString code, QString type,QString pseudo, QString MotDePasse)
{
    this->pseudo=pseudo;
    this->MotDePasse=pseudo;
    this->code=code;
    this->type=type;
}
 bool Login::connection(QString pseu,QString mdp)
 {

     QSqlQuery q;
     q.prepare("select * from login where pseudo=:pseudo and motdepasse=:motdepasse");
     q.bindValue(":pseudo",pseu);
     q.bindValue(":motdepasse",mdp);
     q.exec();
     q.next();
     {
         if((q.value(1)==pseu)&&(q.value(2)==mdp))
         {

            type=q.value(3).toString();
             return true;
         }
         else {

             return false;
         }
     }



 }
bool Login::ajouter()
 {
     QSqlQuery q;
     q.prepare("insert into login VALUES (:code,:pseudo,:motdepasse,:type)");
     q.bindValue(":code",code);
     q.bindValue(":pseudo",pseudo);
     q.bindValue(":motdepasse",MotDePasse);
     q.bindValue(":type",type);
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
bool Login::modifier()
{
    QSqlQuery q;
    q.prepare("update login set pseudo=:pseudo,motdepasse=:motdepasse,type=:type where code=:code");

    q.bindValue(":code",code);
    q.bindValue(":pseudo",pseudo);
    q.bindValue(":motdepasse",MotDePasse);
    q.bindValue(":type",type);

      if(q.exec())
    {
        return true;
    }
    else return false;
}
QSqlQueryModel* Login::afficher()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
   QSqlQuery q;
   q.prepare("select * from login");
   q.exec();
   modal->setQuery(q);
   return modal;
}
/*bool Login::supprimer()
{
    QSqlQuery q;
    q.prepare("DELETE FROM login WHERE CODE =:CODE");
    q.bindValue(":CODE",code);
    if(q.exec())
    {
        return true;
    }
    else return false;

}*/
bool Login::supprimer()
{
   QSqlQuery q,k;
   q.prepare("select * FROM login WHERE CODE =:CODE");
   q.bindValue(":CODE",code);
   q.exec();
   q.next();
    type=q.value(3).toString();

   if(type=="ADMIN")
   {
       k.prepare("select count(*) from login where type='ADMIN'");
       k.exec();
       k.next();

       if(k.value(0).toInt()>1)
       {
           q.prepare("delete from login where CODE=:CODE");
           q.bindValue(":CODE",code);
       }
   }

   else if(type!="ADMIN")
   {

        q.prepare("delete from login where CODE=:CODE");
        q.bindValue(":CODE",code);
   }

     return q.exec();
}
