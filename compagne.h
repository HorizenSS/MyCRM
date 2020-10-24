#ifndef COMPAGNE_H
#define COMPAGNE_H
#include<QString>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QTableView>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
class Compagne
{private:
    int id;
    QString nom;
    QString type;
    QString autorisation;
    QString duree;
    QString priorite;
    QString description;
    QString cible;
    int budget;

public:
    Compagne();
    Compagne(int, QString,QString,QString,QString,QString,QString,QString,int);
    bool ajoutercompagne();
QSqlQueryModel* affichercompagne();
void supprimercompagne(int );
void modifiercompagne();
void recherchercompagne (QString a, QTableView*g);
int getId(){return id;};
long getBudget(){return budget;};
QString getNom(){return nom;}
QString getType(){return type;}
QString getAutorisation(){return autorisation;};
QString getPriorite(){return priorite;};
QString getDescription(){return description;};
QString getCible(){return cible;};
bool verifier();
};

#endif // COMPAGNE_H
