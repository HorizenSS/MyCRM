#include "compagne.h"
#include<QVariant>
#include <QTableView>
#include <QString>
#include "connection.h"
#include <QSqlDatabase>
#include <QSql>
#include <QSqlError>
#include <QSqlQuery>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

Compagne::Compagne()
{

}

Compagne::Compagne(int a, QString b, QString c, QString d, QString e, QString f, QString g, QString h, int i)
{
     id=a;
     nom=b;
     type=c;
     autorisation=d;
    duree=e;
    priorite=f;
     description=g;
     cible=h;
     budget=i;
}

bool Compagne::ajoutercompagne()
{
    QSqlQuery q;
    q.prepare("insert into compagne(id,nom,type,autorisation,duree,priorite,description,cible,budget) values(?,?,?,?,?,?,?,?,?)");
    q.addBindValue(id);
    q.addBindValue(nom);
    q.addBindValue(type);
    q.addBindValue(autorisation);
    q.addBindValue(duree);
    q.addBindValue(priorite);
    q.addBindValue(description);
    q.addBindValue(cible);
    q.addBindValue(budget);

if  (q.exec())return true; return false;


}

QSqlQueryModel* Compagne::affichercompagne()
{
    QSqlQueryModel *m= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from compagne");
    q.exec();
    m->setQuery(q);
    return m;


}
void Compagne::supprimercompagne(int a)
{
    QSqlQuery q;
    q.prepare("Delete from compagne where id =?");
    q.addBindValue(a);
    q.exec();


}


void Compagne::modifiercompagne()
{
    QSqlQuery q;
    q.prepare("update compagne set nom=?,type=?,autorisation=?,duree=?,priorite=?,description=?,cible=?,budget=? where id=?");

    q.addBindValue(nom);
    q.addBindValue(type);
    q.addBindValue(autorisation);
    q.addBindValue(duree);
    q.addBindValue(priorite);
    q.addBindValue(description);
    q.addBindValue(cible);
    q.addBindValue(budget);
    q.addBindValue(id);
    q.exec();

}

bool Compagne::verifier()
{
    if (nom==""||type==""||duree==""||priorite==""|| autorisation=="" || duree==""|| description==""||cible=="")
    {return false;}
    return true;


}
void Compagne::recherchercompagne (QString a,QTableView *g)
{QSqlQuery qry ;
    QSqlQueryModel *m= new QSqlQueryModel ();
    qry.prepare("SELECT * FROM COMPAGNE WHERE NOM like '%"+a+"%' OR TYPE like '%"+a+"%' or AUTORISATION like '%"+a+"%' OR PRIORITE like '%"+a+"%' OR DESCRIPTION like '%"+a+"%' OR CIBLE like '%"+a+"%'");
    qry.exec();

    m->setQuery(qry);
    g->setModel(m);
}

