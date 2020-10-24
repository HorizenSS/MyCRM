#include "pisteopp.h"
#include "ui_mainwindow.h"

#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include <QObject>


PisteOpp::PisteOpp()
{
    ID_Piste=0;
    ID_Contact=0;
    pertinence=0;
    titre="";
    description="";
    //date=;
    notes="";
    etat="";
    type="";
}
PisteOpp::PisteOpp(int a,int b, int c, QString d , QDate e,QString f,QString g,QString h,QString i)
{
    ID_Piste=a;
    ID_Contact=b;
    pertinence=c;
    titre=d;
    date=e;
    description=f;
    notes=g;
    etat=h;
    type=i;
}

bool PisteOpp::ConfirmerAjout(Ui::MainWindow * ui,MainWindow* parent)
{

    ID_Piste=ui->PO_Ajout_lineEdit_ID_piste->text().toInt();
    ID_Contact=ui->PO_lineEdit_ID_Contact->text().toInt();
    pertinence=ui->PO_Ajout_comboBox_feedback->currentText().toInt();
    titre=ui->PO_Ajout_lineEdit_titre->text();
    date=ui->PO_Ajout_dateEdit->date();
    description=ui->PO_Ajout_plainTextEdit_description->toPlainText();
    notes=ui->PO_Ajout_plainTextEdit_notes->toPlainText();
    etat=ui->PO_Ajout_comboBox_Etat->currentText();
    type=ui->PO_Ajout_comboBox_Type->currentText();

    bool err=true;

    QSqlQuery qry;
    qry.prepare("SELECT COUNT (*) FROM PISTESOPP WHERE ID_PISTE=:id");
    qry.bindValue(":id",ID_Piste);
    qry.exec();
    qry.first();
    int count=qry.value(0).toInt();
    if(ID_Piste>999 || count==1)
    {
        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("ID_Piste erroné!"));
        err=false;
    }

    qry.prepare("SELECT COUNT (*) FROM CLIENT WHERE CIN=:id");
    qry.bindValue(":id",ID_Contact);
    qry.exec();
    qry.first();
    count=qry.value(0).toInt();
    if(ID_Contact>99999999 || count==0)
    {

        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("ID_Contact erroné!"));
        err=false;
    }
    if(titre.length()>30 || titre=="")
    {
        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Titre erroné!"));
        err=false;
    }
    if(description.length()>150)
    {

        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("La description ne doit pas dépasser les 150 lettres!"));
        err=false;
    }
    if(notes.length()>500)
    {
        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("ID_Piste ne doit pas dépasser les trois chiffres!"));
        err=false;
    }
        if(err)
        return addToTable();
        else return false;


}


bool PisteOpp::addToTable()
{
   // QString a = QString::number(ID_Piste);
   // QString a2 = QString::number(ID_Contact);

   // QString b = date.toString("dd.MM.yyyy");
   // QString g = QString::number(tarif_total);
   // QString h = QString::number(pourcent_paye);

    //qDebug()<<a;

    QSqlQuery qry;
    qry.prepare("INSERT INTO PISTESOPP (ID_PISTE, ID_CONTACT, TITRE, PERTINENCE, DESCRIPTION, DATE_D, NOTES,ETAT,TYPE) VALUES(:idp,:idc,:titre,:pertinence,:description,:date_d,:notes,:etat,:type)");
    qry.bindValue(":idp", ID_Piste);
    qry.bindValue(":idc", ID_Contact);
    qry.bindValue(":titre", titre);
    qry.bindValue(":pertinence", pertinence);
    qry.bindValue(":description", description);
    qry.bindValue(":date_d", date);
    qry.bindValue(":notes",notes );
    qry.bindValue(":etat",etat );
    qry.bindValue(":type",type );


//MainWindow* Menu = new MainWindow;
if(qry.exec())
{

    return true;

}
else
    return false;

}


void PisteOpp::searchInTablePistes(Ui::MainWindow * ui, QString a)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("select * from PISTESOPP where( ID_PISTE LIKE '%"+a+"%' OR ID_CONTACT LIKE '%"+a+"%' OR TITRE LIKE '%"+a+"%' OR PERTINENCE LIKE '%"+a+"%' OR DESCRIPTION LIKE '%"+a+"%'  OR NOTES LIKE '%"+a+"%'  OR ETAT LIKE '%"+a+"%') AND TYPE = 'Piste' ");
   // qry.bindValue("'%:a%'",a);
    qry.exec();
    model->setQuery(qry);
    QSortFilterProxyModel *sqlproxy = new QSortFilterProxyModel();
    sqlproxy->setDynamicSortFilter(true);
    sqlproxy->setSourceModel(model);
    ui->tableView_Pistes->setModel(sqlproxy);
    ui->tableView_Pistes->setSortingEnabled(true);

    qDebug()<<(model->rowCount());
}

void PisteOpp::searchInTableOpp(Ui::MainWindow * ui, QString a)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("select * from PISTESOPP where (ID_PISTE LIKE '%"+a+"%' OR ID_CONTACT LIKE '%"+a+"%' OR TITRE LIKE '%"+a+"%' OR PERTINENCE LIKE '%"+a+"%' OR DESCRIPTION LIKE '%"+a+"%'  OR NOTES LIKE '%"+a+"%'  OR ETAT LIKE '%"+a+"%') AND TYPE = 'Opportunite' ");
   // qry.bindValue("'%:a%'",a);
    qry.exec();
    model->setQuery(qry);
    QSortFilterProxyModel *sqlproxy = new QSortFilterProxyModel();
    sqlproxy->setDynamicSortFilter(true);
    sqlproxy->setSourceModel(model);
    ui->tableView_Opportunites->setModel(sqlproxy);
    ui->tableView_Opportunites->setSortingEnabled(true);

    qDebug()<<(model->rowCount());
    //return qry;
}

bool PisteOpp::supprimerPiste(Ui::MainWindow * ui)
{

        QModelIndexList selection = ui->tableView_Pistes->selectionModel()->selectedRows();

        // Multiple rows can be selected
        for(int i=selection.count()-1; i>=0; i--)
        {
            QModelIndex index = selection.at(i);
            int myRow = index.row();

        QString c = (ui->tableView_Pistes->model()->data(ui->tableView_Pistes->model()->index(myRow,0)).toString());

            //Ventes vente;
            if(deleteFromTable(c))
            {
               searchInTablePistes(ui,ui->PO_lineEdit_recherche->text());


            }
            else
            {
                return false;
            }
        }

    return true;
}

bool PisteOpp::supprimerOpp(Ui::MainWindow * ui)
{

        QModelIndexList selection = ui->tableView_Opportunites->selectionModel()->selectedRows();

        // Multiple rows can be selected
        for(int i=selection.count()-1; i>=0; i--)
        {
            QModelIndex index = selection.at(i);
            int myRow = index.row();

        QString c = (ui->tableView_Opportunites->model()->data(ui->tableView_Opportunites->model()->index(myRow,0)).toString());

            //Ventes vente;
            if(deleteFromTable(c))
            {
               searchInTableOpp(ui,ui->PO_lineEdit_rechercheOpp->text());
                 return true;

            }
            else
            {
                return false;
            }
        }


}

bool PisteOpp::deleteFromTable(QString c)
{


    QSqlQuery qry;
    qry.prepare("delete from PISTESOPP where ID_PISTE=:c " );
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


bool PisteOpp::modifierPiste(Ui::MainWindow* ui)
{
    QModelIndexList selection = ui->tableView_Pistes->selectionModel()->selectedRows();

    if(selection.count()>1 || selection.count()==0)
    {
        qDebug()<<(selection.count());

        return false;

    }

    QModelIndex index = selection.at(0);
    int myRow = index.row();

    ID_Piste = (ui->tableView_Pistes->model()->data(ui->tableView_Pistes->model()->index(myRow,0)).toInt());

    ID_Contact = (ui->tableView_Pistes->model()->data(ui->tableView_Pistes->model()->index(myRow,1)).toInt());

    titre  = (ui->tableView_Pistes->model()->data(ui->tableView_Pistes->model()->index(myRow,2)).toString());

    pertinence = (ui->tableView_Pistes->model()->data(ui->tableView_Pistes->model()->index(myRow,3)).toInt());

    description = (ui->tableView_Pistes->model()->data(ui->tableView_Pistes->model()->index(myRow,4)).toString());

    date= (ui->tableView_Pistes->model()->data(ui->tableView_Pistes->model()->index(myRow,5)).toDate());

    notes = (ui->tableView_Pistes->model()->data(ui->tableView_Pistes->model()->index(myRow,6)).toString());

    etat = (ui->tableView_Pistes->model()->data(ui->tableView_Pistes->model()->index(myRow,7)).toString());

    type = (ui->tableView_Pistes->model()->data(ui->tableView_Pistes->model()->index(myRow,8)).toString());



    //int rowidx = ui->tblView->selectionModel()->currentIndex().row();





    ui->stackedWidget_2->setCurrentIndex(58);

    ui->PO_Ajout_lineEdit_ID_2->setReadOnly(true);
    ui->PO_lineEdit_ID_Contact_2->setReadOnly(true);
    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Base,Qt::gray);
    palette->setColor(QPalette::Text,Qt::darkGray);
    ui->PO_Ajout_lineEdit_ID_2->setPalette(*palette);
    ui->PO_lineEdit_ID_Contact_2->setPalette(*palette);



    ui->PO_Ajout_lineEdit_titre_2->clear();
    ui->PO_Ajout_plainTextEdit_description_2->clear();
    ui->PO_Ajout_plainTextEdit_notes_2->clear();





    QString id1 = QString::number(ID_Piste);
    QString id2 = QString::number(ID_Contact);
    QString per = QString::number(pertinence);



    ui->PO_Ajout_lineEdit_ID_2->setText(id1);
    ui->PO_Ajout_dateEdit_2->date()=date;
    ui->PO_Ajout_lineEdit_titre_2->setText(titre);
    ui->PO_Ajout_plainTextEdit_description_2->setPlainText(description);
    ui->PO_lineEdit_ID_Contact_2->setText(id2);
    ui->PO_Ajout_comboBox_Etat_2->currentText()=etat;
    ui->PO_Ajout_comboBox_Type_2->currentText()=type;
    ui->PO_Ajout_comboBox_feedback_2->currentText()=per;
    ui->PO_Ajout_plainTextEdit_notes_2->setPlainText(notes);

    return true;
}


bool PisteOpp::ConfirmerModifier(Ui::MainWindow* ui,MainWindow* parent)
{
    ID_Piste=ui->PO_Ajout_lineEdit_ID_2->text().toInt();
    ID_Contact=ui->PO_lineEdit_ID_Contact_2->text().toInt();
    date=ui->PO_Ajout_dateEdit_2->date();
    etat=(ui->PO_Ajout_comboBox_Etat_2->currentText());
    type=(ui->PO_Ajout_comboBox_Type_2->currentText());
    titre=ui->PO_Ajout_lineEdit_titre_2->text();
    description=ui->PO_Ajout_plainTextEdit_description_2->toPlainText();
    pertinence=(ui->PO_Ajout_comboBox_feedback_2->currentText().toInt());
    notes=ui->PO_Ajout_plainTextEdit_notes_2->toPlainText();
    bool err=true;
    if(titre.length()>30 || titre=="")
    {
        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Titre erroné!"));
        err=false;
    }
    if(description.length()>150)
    {

        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("La description ne doit pas dépasser les 150 lettres!"));
        err=false;
    }
    if(notes.length()>500)
    {
        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("ID_Piste ne doit pas dépasser les trois chiffres!"));
        err=false;
    }


/*
    QString a = QString::number(ID_vente);
    QString b = date.toString("dd.MM.yyyy");
    QString g = QString::number(tarif_total);
    QString h = QString::number(pourcent_paye);

*/
    if(err)
    {
            QSqlQuery qry;
            qDebug()<<ID_Piste;
            qry.prepare("update PISTESOPP set TITRE=:titre, PERTINENCE=:pertinence,DESCRIPTION=:description ,DATE_D=:date,NOTES=:notes,  ETAT=:etat,  TYPE=:type  where ID_PISTE=:id");

            qry.bindValue(":titre", titre);
            qry.bindValue(":pertinence", pertinence);
            qry.bindValue(":description", description);
            qry.bindValue(":date", date);
            qry.bindValue(":etat", etat);
            qry.bindValue(":type",type );
            qry.bindValue(":notes", notes);
            qry.bindValue(":id", ID_Piste);


            if(qry.exec())
            {
                //QMessageBox::critical(this,QObject::tr("Save"),QObject::tr("Saved!"));
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








bool PisteOpp::modifierOpp(Ui::MainWindow* ui)
{
    QModelIndexList selection = ui->tableView_Opportunites->selectionModel()->selectedRows();

    if(selection.count()>1 || selection.count()==0)
    {
        qDebug()<<(selection.count());

        return false;

    }

    QModelIndex index = selection.at(0);
    int myRow = index.row();

    ID_Piste = (ui->tableView_Opportunites->model()->data(ui->tableView_Opportunites->model()->index(myRow,0)).toInt());

    ID_Contact = (ui->tableView_Opportunites->model()->data(ui->tableView_Opportunites->model()->index(myRow,1)).toInt());

    titre  = (ui->tableView_Opportunites->model()->data(ui->tableView_Opportunites->model()->index(myRow,2)).toString());

    pertinence = (ui->tableView_Opportunites->model()->data(ui->tableView_Opportunites->model()->index(myRow,3)).toInt());

    description = (ui->tableView_Opportunites->model()->data(ui->tableView_Opportunites->model()->index(myRow,4)).toString());

    date= (ui->tableView_Opportunites->model()->data(ui->tableView_Opportunites->model()->index(myRow,5)).toDate());

    notes = (ui->tableView_Opportunites->model()->data(ui->tableView_Opportunites->model()->index(myRow,6)).toString());

    etat = (ui->tableView_Opportunites->model()->data(ui->tableView_Opportunites->model()->index(myRow,7)).toString());

    type = (ui->tableView_Opportunites->model()->data(ui->tableView_Opportunites->model()->index(myRow,8)).toString());



    //int rowidx = ui->tblView->selectionModel()->currentIndex().row();





    ui->stackedWidget_2->setCurrentIndex(58);

    ui->PO_Ajout_lineEdit_ID_2->setReadOnly(true);
    ui->PO_lineEdit_ID_Contact_2->setReadOnly(true);
    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Base,Qt::gray);
    palette->setColor(QPalette::Text,Qt::darkGray);


    ui->PO_Ajout_lineEdit_titre_2->clear();
    ui->PO_Ajout_plainTextEdit_description_2->clear();
    ui->PO_Ajout_plainTextEdit_notes_2->clear();





    QString id1 = QString::number(ID_Piste);
    QString id2 = QString::number(ID_Contact);
    QString per = QString::number(pertinence);


    //ui->V_dateEdit_DateDebut_2->insert(date_debut);

    ui->PO_Ajout_lineEdit_ID_2->setText(id1);
    ui->PO_Ajout_dateEdit_2->date()=date;
    ui->PO_Ajout_lineEdit_titre_2->setText(titre);
    ui->PO_Ajout_plainTextEdit_description_2->setPlainText(description);
    ui->PO_lineEdit_ID_Contact_2->setText(id2);
    ui->PO_Ajout_comboBox_Etat_2->currentText()=etat;
    ui->PO_Ajout_comboBox_Type_2->currentText()=type;
    ui->PO_Ajout_comboBox_feedback_2->currentText()=per;
    ui->PO_Ajout_plainTextEdit_notes_2->setPlainText(notes);

    return true;
}
