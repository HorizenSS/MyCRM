#include "service.h"
#include "ui_mainwindow.h"

#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include <QObject>

Service::Service()
{
nom="";
description="";
categorie="";
notes="";
}

Service::Service(QString nom,QString description,QString categorie,QString notes)
{
    this->nom=nom;
    this->description=description;
    this->categorie=categorie;
    this->notes=notes;
}


bool Service::ConfirmerAjout(Ui::MainWindow * ui,MainWindow* parent)
{

    nom=ui->S_lineEdit_Nom->text();
    description=ui->S_plainTextEdit_Description->toPlainText();
    notes=ui->S_plainTextEdit_Notes->toPlainText();
    categorie=ui->S_comboBox_Categorie->currentText();


    bool err=true;

    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM SERVICE WHERE NOM_SERVICE=:id");
    qry.bindValue(":id",nom);
    qry.exec();
    qry.first();
    int count=qry.value(0).toInt();
    if(nom.length()>25 || count==1)
    {
        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Nom du service erroné!"));
        err=false;
    }

    if(description.length()>100)
    {

        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("La description ne doit pas dépasser les 100 lettres!"));
        err=false;
    }
    if(notes.length()>150)
    {
        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Les notes ne doivent pas dépasser les 150 lettres!"));
        err=false;
    }

        if(err)
        return addToTable();
        else return false;


}

bool Service::addToTable()
{

    QSqlQuery qry;
    qry.prepare("INSERT INTO SERVICE (NOM_SERVICE, DESCRIPTION, CATEGORIE, NOTES) VALUES(:id,:description,:categorie,:notes)");
    qry.bindValue(":id", nom);
    qry.bindValue(":description", description);
    qry.bindValue(":categorie", categorie);
    qry.bindValue(":notes",notes );

if(qry.exec())
    return true;
else
    return false;

}

void Service::searchInTable(Ui::MainWindow * ui, QString a)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("select * from SERVICE where( NOM_SERVICE LIKE '%"+a+"%' OR CATEGORIE LIKE '%"+a+"%' OR DESCRIPTION LIKE '%"+a+"%'  OR NOTES LIKE '%"+a+"%') ");
   // qry.bindValue("'%:a%'",a);
    qry.exec();
    model->setQuery(qry);
    QSortFilterProxyModel *sqlproxy = new QSortFilterProxyModel();
    sqlproxy->setDynamicSortFilter(true);
    sqlproxy->setSourceModel(model);
    ui->S_tableView_Services->setModel(sqlproxy);
    ui->S_tableView_Services->setSortingEnabled(true);

    qDebug()<<(model->rowCount());
}

bool Service::supprimerService(Ui::MainWindow * ui)
{

        QModelIndexList selection = ui->S_tableView_Services->selectionModel()->selectedRows();

        // Multiple rows can be selected
        for(int i=selection.count()-1; i>=0; i--)
        {
            QModelIndex index = selection.at(i);
            int myRow = index.row();

        QString c = (ui->S_tableView_Services->model()->data(ui->S_tableView_Services->model()->index(myRow,0)).toString());

            if(deleteFromTable(c))
            {
               searchInTable(ui,ui->S_lineEdit_Recherche->text());
               return true;


            }
            else
            {
                return false;
            }
        }

}

bool Service::deleteFromTable(QString c)
{


    QSqlQuery qry;
    qry.prepare("delete from SERVICE where NOM_SERVICE=:c " );
    qry.bindValue(":c", c);

    if(qry.exec())
    {
       qDebug()<<"Deleted!";
        return true;
    }
    else
    {
        qDebug()<<"Error!";
        return false;
    }



}

bool Service::modifierService(Ui::MainWindow* ui)
{
    QModelIndexList selection = ui->S_tableView_Services->selectionModel()->selectedRows();

    if(selection.count()>1 || selection.count()==0)
    {
        qDebug()<<(selection.count());

        return false;

    }

    QModelIndex index = selection.at(0);
    int myRow = index.row();

    nom = (ui->S_tableView_Services->model()->data(ui->S_tableView_Services->model()->index(myRow,0)).toString());

    categorie = (ui->S_tableView_Services->model()->data(ui->S_tableView_Services->model()->index(myRow,1)).toString());

    description = (ui->S_tableView_Services->model()->data(ui->S_tableView_Services->model()->index(myRow,2)).toString());

    notes = (ui->S_tableView_Services->model()->data(ui->S_tableView_Services->model()->index(myRow,3)).toString());







    ui->stackedWidget_2->setCurrentIndex(57);

    ui->S_lineEdit_Nom_2->setReadOnly(true);
    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Base,Qt::gray);
    palette->setColor(QPalette::Text,Qt::darkGray);
    ui->S_lineEdit_Nom_2->setPalette(*palette);

    ui->S_lineEdit_Nom_2->clear();
    ui->S_plainTextEdit_Description_2->clear();
    ui->S_plainTextEdit_Notes_2->clear();



    ui->S_lineEdit_Nom_2->setText(nom);
    ui->S_plainTextEdit_Description_2->setPlainText(description);
    ui->S_comboBox_Categorie_2->setCurrentIndex(ui->S_comboBox_Categorie_2->findData(categorie));
    ui->S_plainTextEdit_Notes_2->setPlainText(notes);

    return true;
}


bool Service::ConfirmerModifier(Ui::MainWindow* ui,MainWindow* parent)
{
    nom=ui->S_lineEdit_Nom_2->text();
    description=ui->S_plainTextEdit_Description_2->toPlainText();
    categorie=ui->S_comboBox_Categorie_2->currentText();
    notes=ui->S_plainTextEdit_Notes_2->toPlainText();

    bool err=true;


    if(description.length()>100)
    {

        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("La description ne doit pas dépasser les 100 lettres!"));
        err=false;
    }
    if(notes.length()>150)
    {
        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Les notes ne doivent pas dépasser les 150 lettres!"));
        err=false;
    }


    if(err)
    {
            QSqlQuery qry;

            qry.prepare("update SERVICE set DESCRIPTION=:description ,CATEGORIE=:categorie,NOTES=:notes where NOM_SERVICE=:nom");

            qry.bindValue(":description", description);
            qry.bindValue(":categorie", categorie);
            qry.bindValue(":notes", notes);
            qry.bindValue(":nom", nom);



            if(qry.exec())
            {
                qDebug()<<"Successful update!";
                return true;
            }
            else
            {
                qDebug()<<"Update failed";
                return false;
            }
    }
    else
        return false;
}
