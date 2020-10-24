#include "serviceclient.h"
#include "ui_mainwindow.h"
#include <QString>
#include "smtp2.h"
#include "mainwindow.h"

QSqlQueryModel* serviceClient::afficherservice()
{
    QSqlQueryModel *m= new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("select prenomc ,count(NOMS)from CLIENT_SERVICE group by prenomc");
    qry.exec();
    m->setQuery(qry);
    ui->maxtab->setModel(m);
    return m;


}

serviceClient::serviceClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serviceClient::afficherservice();
}

serviceClient::~serviceClient()
{
    delete ui;
}
/*QSqlQueryModel* serviceClient::afficherservice()
{
    QSqlQueryModel *m= new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("select prenomc ,count(NOMS)from CLIENT_SERVICE group by prenomc");
    qry.exec();
    m->setQuery(qry);
    ui->maxtab->setModel(m);
    return m;


}*/


void serviceClient::on_sendmail_clicked()
{
    Smtp2 *s=new Smtp2("ines.akez@esprit.tn","118EEWGW","Smtp2.gmail.com",465);
    s->sendMail("ines.akez@esprit.tn","ines.akez@esprit.tn","Félicitation!","House Care vous remercie de votre fidélité et vous offre des coupons gratuits! ");

}



void serviceClient::on_pushButton_clicked()
{
    QSqlQueryModel *m= new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("select noms,count(prenomc) nb_service from CLIENT_SERVICE group by noms order by count(prenomc) desc");
    qry.exec();
    m->setQuery(qry);
    ui->MaxService->setModel(m);
    return ;
}

void serviceClient::on_pushButton_2_clicked()
{
 MainWindow *m= new MainWindow(this);
         hide();
         m->show();
}

void serviceClient::on_menu1_clicked()
{
    MainWindow *m= new MainWindow(this);
            hide();
            m->show();
}
