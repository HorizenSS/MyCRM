#include "ouvrier.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFont>


Ouvrier::Ouvrier()
{
    CIN="";
    Nom="";
    Prenom="";
    Age=0;
    Telephone=0;
    Adresse="";
    Sexe="";
    Specialite="";
    Email="";

}

Ouvrier::Ouvrier(QString CIN,QString Nom,QString Prenom,int Age,long Telephone,QString Adresse,QString Sexe,QString Specialite,QString Email)
{
    this->CIN=CIN;
    this-> Nom=Nom;
    this-> Prenom=Prenom;
    this-> Age=Age;
    this->Telephone=Telephone;
    this-> Adresse=Adresse;
    this->Sexe=Sexe;
    this-> Specialite=Specialite;
    this-> Email=Email;


}
bool Ouvrier::ajouter()
{
    QSqlQuery q;
    q.prepare("insert into OUVRIER values (:CIN,:NOM,:PRENOM,:AGE,:TELEPHONE,:ADRESSE,:SEXE,:SPECIALITE,:EMAIL)");
    q.bindValue(":CIN",CIN);
    q.bindValue(":NOM",Nom);
    q.bindValue(":PRENOM",Prenom);
    q.bindValue(":AGE",Age);
    q.bindValue(":TELEPHONE",QString::number(Telephone));
    q.bindValue(":ADRESSE",Adresse);
    q.bindValue(":SEXE",Sexe);
    q.bindValue(":SPECIALITE",Specialite);
    q.bindValue(":EMAIL",Email);

   /* q.prepare("insert into OUVRIER values (:CIN,:NOM,:PRENOM,:AGE,:TELEPHONE,:ADRESSE,:SEXE,:SPECIALITE,:EMAIL)");
    q.bindValue(":CIN",CIN);
    q.bindValue(":NOM",Nom);
    q.bindValue(":PRENOM",Prenom);
    q.bindValue(":AGE",Age);
    q.bindValue(":TELEPHONE",QString::number(Telephone));
    q.bindValue(":ADRESSE",Adresse);
    q.bindValue(":SEXE",Sexe);
    q.bindValue(":SPECIALITE",Specialite);
    q.bindValue(":EMAIL",Email);*/

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
bool Ouvrier::supprimer()
{
    QSqlQuery q;
    q.prepare("DELETE FROM OUVRIER WHERE CIN =:CIN");
    q.bindValue(":CIN",CIN);
    if(q.exec())
    {
        return true;
    }
    else return false;

}
bool Ouvrier::modifier()
{

      QSqlQuery q;

    q.prepare("update OUVRIER set NOM=:NOM,PRENOM=:PRENOM,AGE=:AGE,TELEPHONE=:TELEPHONE,ADRESSE=:ADRESSE,SEXE=:SEXE,SPECIALITE=:SPECIALITE,EMAIL=:EMAIL where CIN=:CIN");

    q.bindValue(":CIN",CIN);
    q.bindValue(":NOM",Nom);
    q.bindValue(":PRENOM",Prenom);
    q.bindValue(":AGE",Age);
    q.bindValue(":TELEPHONE",QString::number(Telephone));
    q.bindValue(":ADRESSE",Adresse);
    q.bindValue(":SEXE",Sexe);
    q.bindValue(":SPECIALITE",Specialite);
    q.bindValue(":EMAIL",Email);
      if(q.exec())
    {

        return true;
    }
    else return false;
}
void Ouvrier::afficher(Ui::MainWindow *ui)
{

           QSqlQueryModel *modal=new QSqlQueryModel();
           QSqlQuery q;
           q.prepare("select * from OUVRIER");
           q.exec();
           modal->setQuery(q);
           ui->tableOuvrier->setModel(modal);

}
void Ouvrier::aff(Ui::MainWindow *ui)
{
  QSqlQuery q;
  QString c=ui->tableOuvrier->model()->data(ui->tableOuvrier->model()->index(ui->tableOuvrier->selectionModel()->currentIndex().row(),0)).toString();

    q.prepare("select * from OUVRIER where CIN=:CIN");
    q.bindValue(":CIN",c);
    q.exec();
    q.next();
    ui->cinaffouv->setText(q.value(0).toString());
    ui->nomaffouv->setText(q.value(1).toString());
    ui->prenomaffouv->setText(q.value(2).toString());
    ui->ageaffouv->setText(q.value(3).toString());
    ui->telaffouv->setText(q.value(4).toString());
    ui->adresseaffouv->setText(q.value(5).toString());
    ui->sexeaffouv->setText(q.value(6).toString());
    ui->specialiteaffouv->setText(q.value(7).toString());
    ui->emailaffouv->setText(q.value(8).toString());

}

QVector<double> Ouvrier::statistique()
{
        QSqlQuery q;
        QVector<double> stat(5);
        stat[0]=0;
        stat[1]=0;
        stat[2]=0;
        stat[3]=0;
        stat[4]=0;
        q.prepare("SELECT SPECIALITE FROM OUVRIER WHERE SPECIALITE='ELECTRICIEN'");
        q.exec();
        while (q.next())
        {
            stat[0]++;
        }
        q.prepare("SELECT SPECIALITE FROM OUVRIER WHERE SPECIALITE='PLOMBIER'");
        q.exec();
        while (q.next())
        {
            stat[1]++;
        }
        q.prepare("SELECT SPECIALITE FROM OUVRIER WHERE SPECIALITE='JARDINIER'");
        q.exec();
        while (q.next())
        {
            stat[2]++;
        }
        q.prepare("SELECT SPECIALITE FROM OUVRIER WHERE SPECIALITE='FEMME DE MENAGE'");
        q.exec();
        while(q.next())
        {
            stat[3]++;
        }
        q.prepare("SELECT SPECIALITE FROM OUVRIER WHERE SPECIALITE='CHAUFFEUR'");
        q.exec();
        while(q.next())
        {
            stat[4]++;
        }
        return stat;
}
bool Ouvrier::ajouterHistorique()
{
    QSqlQuery q;
     QString a=QDateTime::currentDateTime().toString("dd'-'MM'-'yyyy' 'hh:mm");
    //q.prepare("insert into HISTORIQUE VALUES (:CODE,:TYPE,:DATE)");
    q.prepare("insert into HISTORIQUE_O (code,nom,prenom,age,telephone,adresse,sexe,specialite,email,type,date_suppression)values (:CIN,:NOM,:PRENOM,:AGE,:TELEPHONE,:ADRESSE,:SEXE,:SPECIALITE,:EMAIL,:TYPE,:DATE)");
    q.bindValue(":CIN",CIN);
    q.bindValue(":NOM",Nom);
    q.bindValue(":PRENOM",Prenom);
    q.bindValue(":AGE",Age);
    q.bindValue(":TELEPHONE",QString::number(Telephone));
    q.bindValue(":ADRESSE",Adresse);
    q.bindValue(":SEXE",Sexe);
    q.bindValue(":SPECIALITE",Specialite);
    q.bindValue(":EMAIL",Email);
    q.bindValue(":TYPE","OUVRIER");
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
void Ouvrier::afficherHistorique(Ui::MainWindow *ui)
{

    QSqlQueryModel *modal=new QSqlQueryModel();
   QSqlQuery q;
   q.prepare("select * from HISTORIQUE_O");

   q.exec();
   modal->setQuery(q);
   ui->TableHO->setModel(modal);

}
bool Ouvrier::supprimerHistorique()
{

    QSqlQuery q;
    q.prepare("DELETE FROM HISTORIQUE_O WHERE CODE=:CODE");
    q.bindValue(":CODE",CIN);
    if(q.exec())
    {
        return true;
    }
    else return false;

}
void Ouvrier::makePlot(QCustomPlot *customPlot)
{
    QVector<double> x3(5), y3(20);
        for (int i=0; i<x3.size(); ++i)
        {
          x3[i] = i+1;
        }

    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    //customPlot->setBackground(QBrush(gradient));
    customPlot->setBackground(QBrush(gradient));


    // create empty bar chart objects:

    QCPBars *bars1 = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3,Ouvrier::statistique());
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));

    bars1->setAntialiased(false);

    bars1->setStackingGap(1);

   bars1->setPen(QPen(QColor(0, 168, 140).lighter(130)));
   bars1->setBrush(QColor(0, 168, 140));


    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9;
    labels << "ELECTRICIEN" << "PLOMBIER" << "JARDINIER"<<"FEMME DE MENAGE"<<"CHAUFFEUR";
   QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    customPlot->xAxis->setTicker(textTicker);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->setRange(0, 8);
    customPlot->xAxis->setBasePen(QPen(Qt::white));
    customPlot->xAxis->setTickPen(QPen(Qt::white));
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    customPlot->yAxis->setRange(0,4);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("Nombre d'ouvrier");
     customPlot->yAxis->setSubTicks(false);
    customPlot->yAxis->setBasePen(QPen(Qt::white));
    customPlot->yAxis->setTickPen(QPen(Qt::white));
    customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis->setLabelColor(Qt::white);
    customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));


    //bars1->setData(x3, o.statistique());
    customPlot->replot();

    // setup legend:
    customPlot->legend->setVisible(false);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont/*= font()*/;
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


}
QSqlQueryModel* Ouvrier::triNom()
{
    QSqlQuery q;
     QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select * from OUVRIER order by NOM");
    q.exec();
    modal->setQuery(q);
    return modal;
}
QSqlQueryModel* Ouvrier::triSpecialite()
{
    QSqlQuery q;
     QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select * from OUVRIER order by SPECIALITE");
    q.exec();
    modal->setQuery(q);
    return modal;
}
