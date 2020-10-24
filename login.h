#ifndef LOGIN_H
#define LOGIN_H

#include <QString>
#include "ui_mainwindow.h"
#include <QSqlQueryModel>

class Login
{
private:
    QString code;
    QString pseudo;
    QString MotDePasse;
    QString type;


public:
   Login();
   Login(QString,QString,QString,QString);
   void set_pseudo(QString p){pseudo=p;}
   void set_mp(QString mp){MotDePasse=mp;}
   QString get_pseudo(){return pseudo;}
   QString get_mp(){return MotDePasse;}
   bool connection(QString,QString);
   void set_type(QString t){type=t;}
   QString get_type(){return type;}
   void set_code(QString c){code=c;}
   QString get_code(){return code;}
   bool ajouter();
   bool modifier();
    QSqlQueryModel* afficher();
    bool supprimer();

};

#endif // LOGIN_H
