#include "bouquet.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include<QSqlError>
#include <QtSql/QSqlDatabase>


bool bouquet::Ajouter_bouquet(Ui::MainWindow *ui)
{
    if (ui->electricite->isChecked())
    {
        setelectricite_bouquet("Y");
    }else
        setelectricite_bouquet("N");

    if (ui->Reparation->isChecked())
    {
        setreparation_bouquet("Y");
    }else
        setreparation_bouquet("N");

    if (ui->desinsectisation->isChecked())
    {
        setdesinsectation_bouquet("Y");
    }else
        setdesinsectation_bouquet("N");


    if (ui->menage->isChecked())
    {
        setmenage_bouquet("Y");
    }else
        setmenage_bouquet("N");

    if (ui->peinture->isChecked())
    {
        setPeinture_bouquet("Y");
    }else
        setPeinture_bouquet("N");

    if (ui->cours_particuliers->isChecked())
    {
        setcoursparticulier_bouquet("Y");
    }else
        setcoursparticulier_bouquet("N");

    if (ui->demenagement->isChecked())
    {
        setdemenagement_bouquet("Y");
    }else
        setdemenagement_bouquet("N");

    if (ui->plomberie->isChecked())
    {
        setplomberie_bouquet("Y");
    }else
        setplomberie_bouquet("N");

    if (ui->jardinage->isChecked())
    {
        setjardinage_bouquet("Y");
    }else
        setjardinage_bouquet("N");

    if (ui->transport->isChecked())
    {
        settransport_bouquet("Y");
    }else
        settransport_bouquet("N");

    if (ui->babby_sitting->isChecked())
    {
        setbabysitting_bouquet("Y");
    }else
        setbabysitting_bouquet("N");

    if (ui->soignants->isChecked())
    {
        setsoignant_bouquet("Y");
    }else
        setsoignant_bouquet("N");

    setNom_bouquet(ui->nombouquet->text());
    setID_bouquet(ui->ID_bouquet->text().toInt());




    QSqlQuery query;

                    query.prepare("INSERT INTO BOUQUET (ID_BOUQUET,NOM_BOUQUET,REPARATION,DESINSECTISATION,ELECTRICITE,MENAGE,PEINTURE,COURS_PART,DEMENAGEMENT,PLOMBERIE,JARDINAGE,TRANSPORT,BABY_SITTING,SOIGNANTS) "
                                  "VALUES (?,?, ?, ?,?,?,?,?,?,?,?,?,?,?)");

                    query.addBindValue(QString::number(getID_bouquet()));
                  query.addBindValue(getNom_bouquet());
                   query.addBindValue(getreparation_bouquet());

                 query.addBindValue(getdesinsectation_bouquet());
                  query.addBindValue(getelectricite_bouquet());
                    query.addBindValue(getmenage_bouquet());
                    query.addBindValue(getPeinture_bouquet());
                    query.addBindValue(getcoursparticulier_bouquet());
                    query.addBindValue(getdemenagement_bouquet());
                    query.addBindValue(getplomberie_bouquet());
                    query.addBindValue(getjardinage_bouquet());
                     query.addBindValue(gettransport_bouquet());

                    query.addBindValue(getbabysitting_bouquet());

                    query.addBindValue(getsoignant_bouquet());


                     query.exec();
}
