#include "vente.h"
#include "ui_mainwindow.h"

#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include <QObject>
#include <QPalette>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QTextStream>


Vente::Vente()
{
    this->ID_vente=0;
    this->ID_contact=0;
    this->titre="";
    this->service="";
    this->etat="";
    this->type_paiement="";
    this->tarif_pre=0;
    this->tarif_fin=0;
    this->pourcent_paye=0;
    this->CP10="N";
    this->CP20="N";
    this->options="";
    this->notes="";
}


Vente::Vente(int ID_vente,int ID_contact,QString titre,QDate date_debut,QDate date_fin,QString service,QString etat,QString type_paiement,int tarif_pre,int tarif_fin,int pourcent_paye,QString cp10,QString cp20,QString options,QString notes,QDate date_fgarantie)
{

    this->ID_vente=ID_vente;
    this->ID_contact=ID_contact;
    this->titre=titre;
    this->date_debut=date_debut;
    this->date_exp=date_fin;
    this->service=service;
    this->etat=etat;
    this->type_paiement=type_paiement;
    this->tarif_pre=tarif_pre;
    this->tarif_fin=tarif_fin;
    this->pourcent_paye=pourcent_paye;
    this->CP10=cp10;
    this->CP20=cp20;
    this->options=options;
    this->notes=notes;
    this->date_fgarantie=date_fgarantie;

}




bool Vente::ConfirmerAjout(Ui::MainWindow * ui,MainWindow* parent)
{




    setID_vente(ui->V_lineEdit_ID_Vente->text().toInt());
    ID_contact=ui->V_lineEdit_ID_Contact->text().toInt();
    setDate_debut(ui->V_dateEdit_DateDebut->date());
    date_exp=ui->V_dateEdit_DateExp->date();
    setTitre(ui->V_lineEdit_Titre->text());
    setService(ui->V_lineEdit_Service->text());
/*
    QModelIndexList selection = ui->V_tableView_Services->selectionModel()->selectedRows();

    // Multiple rows can be selected

    if(selection.count()>1)
    {
        return false;
    }

    QModelIndex ind = selection.at(0);
    int myRow = ind.row();
    QString service_select = (ui->V_tableView_Services->model()->data(ui->V_tableView_Services->model()->index(myRow,0)).toString());
    service=service_select;
    qDebug()<<service_select;

*/
    setEtat(ui->V_comboBox_Etat->currentText());
    setType_paiement(ui->V_lineEdit_TypePaiement->text());
    setTarif_pre(ui->V_lineEdit_TarifPre->text().toInt());
    date_fgarantie=ui->V_dateEdit_Date_fgarantie->date();
    if(ui->V_radioButton_cp10->isChecked() && not (ui->V_radioButton_cp20->isChecked()) && ui->V_groupBox_Coupons->isChecked())
    {
    CP10="Y";
    CP20="N";
    }
    if(ui->V_radioButton_cp20->isChecked() && not (ui->V_radioButton_cp10->isChecked()) && ui->V_groupBox_Coupons->isChecked())
    {
    CP10="N";
    CP20="Y";
    }
    //*****************QUERY NEEDED******************
    QSqlQuery qry;

    qry.prepare("SELECT CP_10 FROM CLIENT WHERE CIN=:cin");
    qry.bindValue(":cin",ID_contact);
    int nbcp10;
    int nbcp20;
    qry.exec();

    if(qry.next()==true)
    {
        nbcp10=qry.value(0).toInt();
    }

    qry.prepare("SELECT CP_20 FROM CLIENT WHERE CIN=:cin");
    qry.bindValue(":cin",ID_contact);
    qry.exec();

    if(qry.next()==true)
    {
        nbcp20=qry.value(0).toInt();
    }
    qDebug()<<nbcp10;
    qDebug()<<nbcp20;



    if(CP10=="Y"&& CP20=="N")
    {
        if(nbcp10>=1)
        {
        tarif_fin=tarif_pre-(tarif_pre*10)/100;

        qry.prepare("UPDATE CLIENT SET CP_10=:cp10 WHERE CIN=:cin");


        qry.bindValue(":cp10",nbcp10-1);
        qry.bindValue(":cin",ID_contact);

        qry.exec();

        }
        else
        {
            QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Le client n'a pas assez de coupons!"));
            return false;


        }
    }
    if(CP10=="N"&& CP20=="Y")
    {
        if(nbcp20>=1)
        {
        tarif_fin=tarif_pre-(tarif_pre*20)/100;

        qry.prepare("UPDATE CLIENT SET CP_20=:cp20 WHERE CIN=:cin");
        qry.bindValue(":cp20",nbcp20-1);
        qry.bindValue(":cin",ID_contact);
        qry.exec();
        }
        else
        {
            QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Le client n'a pas assez de coupons!"));
            return false;
        }
    }
    if(CP10=="N"&& CP20=="N")
        tarif_fin=tarif_pre;


    options=ui->V_lineEdit_Options->text();

    bool err=true;
    setPourcent_paye(ui->V_lineEdit_Pourcentage->text().toInt());
    setNotes(ui->V_lineEdit_Notes->text());


    qry.prepare("SELECT COUNT (*) FROM VENTES WHERE ID_VENTE=:id");
    qry.bindValue(":id",ID_vente);
    qry.exec();
    qry.first();
    int count=qry.value(0).toInt();



if(ID_vente>99 || count==1)
{
    QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("ID_Vente erroné."));
    /*msgBox.setText("ID_Vente ne doit pas dépasser les deux chiffres!");
    msgBox.show();*/
    err=false;
}

qry.prepare("SELECT COUNT (*) FROM CLIENT WHERE CIN=:id");
qry.bindValue(":id",ID_contact);
qry.exec();
qry.first();
count=qry.value(0).toInt();

if(ID_contact>99999999 || count==0)
{

    QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("ID_Contact erroné."));
    err=false;}
if(titre.length()>40)
{
    QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Le titre ne doit pas dépasser les 40 lettres!"));
    err=false;}
if(date_debut.operator >(date_exp))
{
    QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Dates incohérentes!"));

    err=false;
}
if(service.length()>30)
{
    QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Le service ne doit pas dépasser les 30 lettres!"));
    err=false;}
if(type_paiement.length()>30)
{
    QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Le type de paiement ne doit pas dépasser les 30 lettres!"));
    err=false;
}
if(tarif_pre>9999999)
{
    QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Le Tarif ne doit pas dépasser les 7 chiffres!"));
    err=false;
}
if(pourcent_paye>100 || pourcent_paye< 0)
{
    QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Le pourcentage payé est incorrect!"));
    err=false;
}

if(options!="A" && options!="B" && options!="C")
{
    QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("L'option est incorrecte!"));
    err=false;
}
if(notes.length()>500)
{
    QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Les notes ne doivent pas dépasser les 500 lettres!"));
    err=false;
}
if(date_debut.operator >(date_debut))
{
    QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Dates incohérentes!"));
    err=false;
}
if(err==true)
        return addToTable();
else
    return false;




}

bool Vente::addToTable()
{
    QString a = QString::number(ID_vente);
    QString a2 = QString::number(ID_contact);
    QString b = date_debut.toString("dd.MM.yyyy");
    QString c = date_exp.toString("dd.MM.yyyy");
    QString d = date_fgarantie.toString("dd.MM.yyyy");
    QString strtarif_p = QString::number(tarif_pre);
    QString strtarif_f = QString::number(tarif_fin);

    QString h = QString::number(pourcent_paye);

   // qDebug()<<options;

    QSqlQuery qry;
    qry.prepare("INSERT INTO VENTES (ID_VENTE, CIN_CLIENT, TITRE, DATE_DEBUT,DATE_EXP, SERVICE, ETAT, TYPE_PAIEMENT, TARIF_PRE, TARIF_FIN, POURCENT_PAYE,CP10,CP20, OPTIONS, NOTES,DATE_FGARANTIE) VALUES(:idv,:idc,:titre,:date_d,:date_e,:service,:etat,:typepaie,:tarifpre,:tariffin,:pourcent,:cp10,:cp20,:options,:notes,:date_fgarantie)");
    qry.bindValue(":idv", a);
    qry.bindValue(":idc", ID_contact);
    qry.bindValue(":titre", titre);
    qry.bindValue(":date_d", b);
    qry.bindValue(":date_e",c);
    qry.bindValue(":service", service);
    qry.bindValue(":etat", etat);
    qry.bindValue(":typepaie",type_paiement );
    qry.bindValue(":tarifpre", strtarif_p);
    qry.bindValue(":tariffin",strtarif_f);
    qry.bindValue(":pourcent", h);
    qry.bindValue(":cp10", CP10);
    qry.bindValue(":cp20", CP20);
    qry.bindValue(":options", options);
    qry.bindValue(":notes", notes);
    qry.bindValue(":date_fgarantie",d);

if(qry.exec())
{
    qDebug()<<"Successfully added to VENTES table";


    return true;

}
else
{

    qDebug()<<"Could not add to VENTES table";
    return false;
}

}


void Vente::searchInTable(Ui::MainWindow * ui, QString a)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("select * from VENTES where ID_VENTE LIKE '%"+a+"%' OR CIN_CLIENT LIKE '%"+a+"%' OR TITRE LIKE '%"+a+"%' OR SERVICE LIKE '%"+a+"%' OR ETAT LIKE '%"+a+"%' OR SERVICE LIKE '%"+a+"%' OR TARIF_PRE LIKE '%"+a+"%' OR TARIF_FIN LIKE '%"+a+"%'  OR POURCENT_PAYE LIKE '%"+a+"%' OR OPTIONS LIKE '%"+a+"%'  OR NOTES LIKE '%"+a+"%'  ");
   // qry.bindValue("'%:a%'",a);
    qry.exec();
    model->setQuery(qry);
   // ui->tableView->setModel(model);

    QSortFilterProxyModel *sqlproxy = new QSortFilterProxyModel();
    sqlproxy->setDynamicSortFilter(true);
    sqlproxy->setSourceModel(model);
    ui->tableView_Ventes->setModel(sqlproxy);
    ui->tableView_Ventes->setSortingEnabled(true);

    qDebug()<<(model->rowCount());
    //return qry;
}

void Vente::ShowTableService(Ui::MainWindow * ui)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("select NOM_SERVICE from SERVICE");
    qry.exec();
    model->setQuery(qry);
    QSortFilterProxyModel *sqlproxy = new QSortFilterProxyModel();
    sqlproxy->setDynamicSortFilter(true);
    sqlproxy->setSourceModel(model);
    ui->V_tableView_Services->setModel(sqlproxy);
    ui->V_tableView_Services->setSortingEnabled(true);
    ui->V_tableView_Services_2->setModel(sqlproxy);
    ui->V_tableView_Services_2->setSortingEnabled(true);

    qDebug()<<(model->rowCount());

}



bool Vente::supprimerVente(Ui::MainWindow * ui,MainWindow* parent)
{

        QModelIndexList selection = ui->tableView_Ventes->selectionModel()->selectedRows();

        // Multiple rows can be selected
        for(int i=selection.count()-1; i>=0; i--)
        {
            QModelIndex index = selection.at(i);
            int myRow = index.row();
           // QString c = ui->tableView->model.index(myRow , 0).data().toString();
        //QString c = (ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
        QString c = (ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(myRow,0)).toString());

            //Ventes vente;
            if(deleteFromTable(c,parent))
            {
               searchInTable(ui,ui->Search_bar_ventes->text());

            }
            else
            {
                return false;
            }
        }

    return true;
}


bool Vente::deleteFromTable(QString c,MainWindow* parent)
{


    QSqlQuery qry;
    qry.prepare("delete from VENTES where ID_VENTE=:c " );
    qry.bindValue(":c", c);

    if(qry.exec())
    {
        QMessageBox::information(parent,QObject::tr("Supprimer"),QObject::tr("Suppression réussie!"));
        return true;
    }
    else
    {
        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Suppression non aboutie."));
        return false;
    }



}



bool Vente::modifierVente(Ui::MainWindow* ui)
{
    QModelIndexList selection = ui->tableView_Ventes->selectionModel()->selectedRows();

    if(selection.count()>1 || selection.count()==0)
    {
        qDebug()<<(selection.count());

        return false;

    }

    QModelIndex index = selection.at(0);
    int myRow = index.row();

    int a = (ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(myRow,0)).toInt());
        ID_vente = a;

    int b = (ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(myRow,1)).toInt());
        ID_contact = b;

    QString c = (ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(myRow,2)).toString());
        titre=c;

    QDate d = (ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(myRow,3)).toDate());
        date_debut=d;

    QDate e = (ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(myRow,4)).toDate());
        date_exp=e;

    QString f = (ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(myRow,5)).toString());
        service=f;

    QString g = (ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(myRow,6)).toString());
        etat=g;

    QString h = (ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(myRow,7)).toString());
        type_paiement=h;

    int i = (ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(myRow,8)).toInt());
        tarif_pre=i;

    int j = (ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(myRow,9)).toInt());
        tarif_fin=j;

    int k = (ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(myRow,10)).toInt());
        pourcent_paye=k;

    int k1 = (ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(myRow,11)).toInt());
        CP10=k1;

    int k2 = (ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(myRow,12)).toInt());
        CP20=k2;

    QString k3 = (ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(myRow,13)).toString());
        options=k3;

    QString k4 = (ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(myRow,14)).toString());
         notes=k4;

    QDate k5 = (ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(myRow,15)).toDate());
    date_fgarantie=k5;
    //int rowidx = ui->tblView->selectionModel()->currentIndex().row();





    ui->stackedWidget_2->setCurrentIndex(51);

    ui->V_lineEdit_ID_Vente_2->setReadOnly(true);
    ui->V_lineEdit_ID_Contact_2->setReadOnly(true);
    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Base,Qt::gray);
    palette->setColor(QPalette::Text,Qt::darkGray);
    ui->V_lineEdit_ID_Vente_2->setPalette(*palette);
    ui->V_lineEdit_ID_Contact_2->setPalette(*palette);

    ui->V_lineEdit_ID_Vente_2->clear();
    ui->V_lineEdit_ID_Contact_2->clear();
    ui->V_dateEdit_DateDebut_2->date()=date_debut;
    ui->V_dateEdit_DateExp_2->date()=date_exp;
    ui->V_lineEdit_Titre_2->clear();
    ui->V_lineEdit_Service_2->clear();
    ui->V_comboBox_Etat_2->currentText()=etat;
    ui->V_lineEdit_TypePaiement_2->clear();
    ui->V_lineEdit_TarifPre_2->clear();
    ui->V_lineEdit_Pourcentage_2->clear();
    ui->V_lineEdit_Notes_2->clear();





    QString id1 = QString::number(ID_vente);
    QString id2 = QString::number(ID_contact);
    QString tr = QString::number(tarif_pre);
    QString prc = QString::number(pourcent_paye);

    ui->V_lineEdit_ID_Vente_2->insert(id1);
    ui->V_lineEdit_ID_Contact_2->insert(id2);
    //ui->V_dateEdit_DateDebut_2->insert(date_debut);
    ui->V_dateEdit_DateDebut_2->setDate(date_debut);
    ui->V_dateEdit_DateExp_2->setDate(date_exp);
    ui->V_lineEdit_Titre_2->insert(titre);
    ui->V_lineEdit_Service_2->insert(service);
    ui->V_comboBox_Etat_2->currentText()=etat;
    ui->V_lineEdit_TypePaiement_2->insert(type_paiement);
    ui->V_lineEdit_TarifPre_2->insert(tr);
    ui->V_lineEdit_Pourcentage_2->insert(prc);
    ui->V_lineEdit_Notes_2->setText(notes);
    ui->V_lineEdit_Options_2->setText(options);
    ui->V_dateEdit_Date_fgarantie_2->setDate(date_fgarantie);

    return true;
}



bool Vente::ConfirmerModifierVente(Ui::MainWindow* ui,MainWindow* parent)
{
    setID_vente(ui->V_lineEdit_ID_Vente_2->text().toInt());
    setID_contact(ui->V_lineEdit_ID_Contact_2->text().toInt());
    setDate_debut(ui->V_dateEdit_DateDebut_2->date());
    date_exp=ui->V_dateEdit_DateExp_2->date();
    setTitre(ui->V_lineEdit_Titre_2->text());
    setService(ui->V_lineEdit_Service_2->text());

    setEtat(ui->V_comboBox_Etat_2->currentText());
    setType_paiement(ui->V_lineEdit_TypePaiement_2->text());
    setTarif_pre(ui->V_lineEdit_TarifPre_2->text().toInt());
    setPourcent_paye(ui->V_lineEdit_Pourcentage_2->text().toInt());
    setNotes(ui->V_lineEdit_Notes_2->text());
    options=ui->V_lineEdit_Options_2->text();
    date_fgarantie=ui->V_dateEdit_Date_fgarantie_2->date();

    bool err=true;


    if(titre.length()>40)
    {
        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Le titre ne doit pas dépasser les 40 lettres!"));
        err=false;}
    if(date_debut.operator >(date_exp))
    {
        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Dates incohérentes!"));

        err=false;
    }
    if(service.length()>30)
    {
        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Le service ne doit pas dépasser les 30 lettres!"));
        err=false;}
    if(type_paiement.length()>30)
    {
        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Le type de paiement ne doit pas dépasser les 30 lettres!"));
        err=false;
    }
    if(tarif_pre>9999999)
    {
        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Le Tarif ne doit pas dépasser les 7 chiffres!"));
        err=false;
    }
    if(pourcent_paye>100 || pourcent_paye< 0)
    {
        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Le pourcentage payé est incorrect!"));
        err=false;
    }

    if(options!="A" && options!="B" && options!="C")
    {
        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("L'option est incorrecte!"));
        err=false;
    }
    if(notes.length()>500)
    {
        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Les notes ne doivent pas dépasser les 500 lettres!"));
        err=false;
    }
    if(date_debut.operator >(date_debut))
    {
        QMessageBox::information(parent,QObject::tr("Erreur"),QObject::tr("Dates incohérentes!"));
        err=false;
    }

    if(err)
    {
            QString a = QString::number(ID_vente);
            QString b = date_debut.toString("dd.MM.yyyy");
            QString c = date_exp.toString("dd.MM.yyyy");
            QString d = date_fgarantie.toString("dd.MM.yyyy");
            QString g = QString::number(tarif_pre);
            QString h = QString::number(pourcent_paye);



            QSqlQuery qry;
            qry.prepare("update VENTES set TITRE=:titre, DATE_DEBUT=:date_d,DATE_EXP=:date_e, SERVICE=:service, ETAT=:etat, TYPE_PAIEMENT=:typepaie, TARIF_PRE=:tariftot, POURCENT_PAYE=:pourcent, OPTIONS=:options, NOTES=:notes,DATE_FGARANTIE=:date_fgarantie where ID_Vente=:id");

            qry.bindValue(":titre", titre);
            qry.bindValue(":date_d", b);
            qry.bindValue(":date_e", c);
            qry.bindValue(":service", service);
            qry.bindValue(":etat", etat);
            qry.bindValue(":typepaie",type_paiement );
            qry.bindValue(":tariftot", g);
            qry.bindValue(":pourcent", h);
            qry.bindValue(":options", options);
            qry.bindValue(":notes", notes);
            qry.bindValue(":date_fgarantie",d);
            qry.bindValue(":id", a);

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
}

QSqlQuery Vente::Stats_VL(int opt)
{
    QSqlQuery qry;
    QDate currD= currD.currentDate();
    int currentMonth = currD.month();
    int currentYear = currD.year();
    qDebug()<<"h is :"<<currentMonth;
    if(opt==2)
    {
    qry.prepare("SELECT COUNT(*) FROM VENTES WHERE to_char(DATE_DEBUT , 'mm') = :currentMonth AND to_char(DATE_DEBUT , 'yyyy')=:currentYear ");
    qry.bindValue(":currentMonth",currentMonth);
    qry.bindValue(":currentYear",currentYear);
    }
    if(opt==3)
    {
    qry.prepare("SELECT COUNT(*) FROM VENTES WHERE to_char(DATE_DEBUT , 'yyyy')=:currentYear ");
    qry.bindValue(":currentYear",currentYear);
    }


    qry.exec();
    return qry;



}
 QVector <double> Vente::UI_Stats_VL(Ui::MainWindow* ui)
{
    QVector <double> nbvParPeriode;
    QSqlQuery qry;
    qry=Stats_VL(2);
    int nb;
    if(qry.next()==true)
    {
        nb=qry.value(0).toInt();
    }
    //qry.first();

    //nb=qry.value(0).toInt();
    nbvParPeriode.push_back(nb);


    qry=Stats_VL(3);

    if(qry.next()==true)
    {
        nb=qry.value(0).toInt();
    }
     nbvParPeriode.push_back(nb);

    return nbvParPeriode;

}

void Vente::FillListeVentesExp(Ui::MainWindow* ui)
{
    QSqlQuery qry;
    qry.prepare("select ID_VENTE from VENTES where (POURCENT_PAYE <100 AND DATE_EXP - 7  < CURRENT_DATE AND DATE_EXP > CURRENT_DATE )");
    qry.exec();
    qDebug()<<"reached";
    QString container;
    QStringList list;
    //int i=0;
    while(qry.next()==true)
    {
        container=qry.value(0).toString();
        qDebug()<<container;
        //i++;
        list.append(container);
    }
    QStringListModel* model= new QStringListModel(list);
    ui->V_listView_VentesExp->setModel(model);
}
