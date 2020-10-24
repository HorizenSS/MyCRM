    #include "mainwindow.h"
    #include "ui_mainwindow.h"
    #include <iostream>
    #include <QPdfWriter>
    #include <QPainter>
    #include <QtPrintSupport/QPrinter>
    #include <QTextDocument>
    #include <QMessageBox>
    #include <QSqlQuery>
    #include "ouvrier.h"
    #include <QSqlQueryModel>
    #include "materiaux.h"
    #include <QDateTime>
    #include <QDebug>
    #include "rendezvous.h"
    #include "qcustomplot.h"
    #include "client.h"
    #include <QString>
    #include <QtSql/QSqlDatabase>
    #include<QLineEdit>
    #include<QDate>
    #include<QSqlError>
    #include <QcheckBox>
    #include "fournisseur.h"
    #include "bouquet.h"
    #include <QTextStream>
    #include "popup.h"
    #include "reclamatio.h"
    #include "intervention.h"
    #include "garantie.h"
    #include "smtp.h"
    #include "login.h"
    //Module Vente
    #include "vente.h"
    #include "pisteopp.h"
    #include "service.h"
    #include "compagne.h"
#include "smtp2.h"
 #include "st.h"
    #define q2c(string) string.toStdString()
    MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        notification=new QSystemTrayIcon(QIcon("C:/Users/SELON/Desktop/1937"),this);
        notification->setIcon(QIcon("C:/Users/SELON/Desktop/1937"));
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->stackedWidget_3->setCurrentIndex(0);
        //notification=new QSystemTrayIcon(this);
        //notification->setIcon(QIcon("C:/Users/SELON/Desktop/1937"));
        ui->tablegarantie->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableOuvrier->setSelectionBehavior(QAbstractItemView::SelectRows);
         ui->tableMateriaux->setSelectionBehavior(QAbstractItemView::SelectRows);
          ui->TableHO->setSelectionBehavior(QAbstractItemView::SelectRows);
           ui->TableHM->setSelectionBehavior(QAbstractItemView::SelectRows);
           ui->TableHR->setSelectionBehavior(QAbstractItemView::SelectRows);
         ui->tableRV->setSelectionBehavior(QAbstractItemView::SelectRows);
         ui->tableCompte->setSelectionBehavior(QAbstractItemView::SelectRows);
         ui->connecter->setShortcut(Qt::Key_Enter);
         ui->connecter->setShortcut(Qt::Key_Return);
           page=0;
           MainWindow::makeplot2();

           //**********************Module Vente*************************
           Vente a;
           a.searchInTable(ui,ui->Search_bar_ventes->text());
           ui->tableView_Ventes->setSelectionBehavior(QAbstractItemView::SelectRows);
           ui->tableView_Pistes->setSelectionBehavior(QAbstractItemView::SelectRows);
           ui->tableView_Opportunites->setSelectionBehavior(QAbstractItemView::SelectRows);
           ui->V_tableView_Services->setSelectionBehavior(QAbstractItemView::SelectRows);
           ui->V_tableView_Services->setSelectionMode( QAbstractItemView::SingleSelection );
           ui->S_tableView_Services->setSelectionBehavior(QAbstractItemView::SelectRows);
    }

    MainWindow::~MainWindow()
    {
        delete ui;
    }

    void MainWindow::on_Accueil_clicked()
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget_2->setCurrentIndex(0);
    }

    void MainWindow::on_gestionInterne_clicked()
    {
          ui->stackedWidget->setCurrentIndex(1);
          ui->stackedWidget_2->setCurrentIndex(0);

    }

    void MainWindow::on_gestionOuvriers_clicked()
    {
        Ouvrier o;
          ui->stackedWidget_2->setCurrentIndex(1);
          page=1;
          o.afficher(ui);
    }

    void MainWindow::on_connecter_clicked()
    {


           QString user = ui->pseudo->text();
             QString mp=ui->motdepasse->text();
               Login *l=new Login();
               //l.connection();

                if(user==("admin")&&mp==("admin"))
                {
                    ui->stackedWidget_3->setCurrentIndex(1);
               /*if((ui->pseudo->text()!="")&&(ui->motdepasse->text()!=""))
               {
                   if(l->connection(ui->pseudo->text(),ui->motdepasse->text()))
                   {
                      if(l->get_type()=="ADMIN")
                      {
                          Login l;
                          ui->stackedWidget_3->setCurrentIndex(1);
                          ui->stackedWidget_2->setCurrentIndex(47);
                          page=47;
                          ui->Accueil->setVisible(false);
                          ui->gestionInterne->setVisible(false);
                          ui->gestionContacts->setVisible(false);
                          ui->sav->setVisible(false);
                          ui->vente->setVisible(false);
                          ui->analyse->setVisible(false);
                          ui->label->setVisible(false);
                          ui->label_2->setVisible(false);
                          ui->label_3->setVisible(false);
                          ui->label_4->setVisible(false);
                          ui->label_5->setVisible(false);
                          ui->label_7->setVisible(false);
                          ui->precedent->setVisible(false);
                          ui->tableCompte->setModel(l.afficher());
                      }
                      else if(l->get_type()=="RGC")
                      {
                          ui->Accueil->setVisible(true);
                          ui->gestionInterne->setVisible(true);
                          ui->gestionInterne->setEnabled(false);

                          ui->gestionContacts->setVisible(true);
                          ui->gestionContacts->setEnabled(true);

                          ui->sav->setVisible(true);
                          ui->sav->setEnabled(false);

                          ui->vente->setVisible(true);
                          ui->vente->setEnabled(false);

                          ui->analyse->setVisible(true);
                          ui->analyse->setEnabled(false);

                          ui->label->setVisible(true);
                          ui->label_2->setVisible(true);
                          ui->label_3->setVisible(true);
                          ui->label_4->setVisible(true);
                          ui->label_5->setVisible(true);
                          ui->label_7->setVisible(true);
                          ui->precedent->setVisible(true);
                          ui->stackedWidget_3->setCurrentIndex(1);
                          ui->stackedWidget_2->setCurrentIndex(0);
                      }

                      else if(l->get_type()=="RV")
                      {
                          ui->Accueil->setVisible(true);
                          ui->gestionInterne->setVisible(true);
                          ui->gestionInterne->setEnabled(false);

                          ui->gestionContacts->setVisible(true);
                          ui->gestionContacts->setEnabled(false);

                          ui->sav->setVisible(true);
                          ui->sav->setEnabled(false);

                          ui->analyse->setVisible(true);
                          ui->analyse->setEnabled(false);

                          ui->vente->setVisible(true);
                          ui->vente->setEnabled(true);


                          ui->label->setVisible(true);
                          ui->label_2->setVisible(true);
                          ui->label_3->setVisible(true);
                          ui->label_4->setVisible(true);
                          ui->label_5->setVisible(true);
                          ui->label_7->setVisible(true);
                          ui->precedent->setVisible(true);
                          ui->stackedWidget_3->setCurrentIndex(1);
                          ui->stackedWidget_2->setCurrentIndex(0);
                      }

                      else if(l->get_type()=="RA")
                      {
                          ui->Accueil->setVisible(true);
                          ui->gestionInterne->setVisible(true);
                          ui->gestionInterne->setEnabled(false);

                          ui->gestionContacts->setVisible(true);
                          ui->gestionContacts->setEnabled(false);

                          ui->sav->setVisible(true);
                          ui->sav->setEnabled(false);

                          ui->vente->setVisible(true);
                          ui->vente->setEnabled(false);

                          ui->analyse->setVisible(true);
                          ui->analyse->setEnabled(true);

                          ui->label->setVisible(true);
                          ui->label_2->setVisible(true);
                          ui->label_3->setVisible(true);
                          ui->label_4->setVisible(true);
                          ui->label_5->setVisible(true);
                          ui->label_7->setVisible(true);
                          ui->precedent->setVisible(true);
                          ui->stackedWidget_3->setCurrentIndex(1);
                          ui->stackedWidget_2->setCurrentIndex(0);

                      }
                      else if(l->get_type()=="RGI")
                      {
                          ui->Accueil->setVisible(true);
                          ui->gestionInterne->setVisible(true);
                          ui->gestionInterne->setEnabled(true);

                          ui->gestionContacts->setVisible(true);
                          ui->gestionContacts->setEnabled(false);

                          ui->sav->setVisible(true);
                          ui->sav->setEnabled(false);

                          ui->vente->setVisible(true);
                          ui->vente->setEnabled(false);

                          ui->analyse->setVisible(true);
                          ui->analyse->setEnabled(false);

                          ui->label->setVisible(true);
                          ui->label_2->setVisible(true);
                          ui->label_3->setVisible(true);
                          ui->label_4->setVisible(true);
                          ui->label_5->setVisible(true);
                          ui->label_7->setVisible(true);
                          ui->precedent->setVisible(true);
                          ui->stackedWidget_3->setCurrentIndex(1);
                          ui->stackedWidget_2->setCurrentIndex(0);


                      }
                      else if(l->get_type()=="RSAV")
                      {
                          ui->Accueil->setVisible(true);
                          ui->gestionInterne->setVisible(true);
                          ui->gestionInterne->setEnabled(false);

                          ui->gestionContacts->setVisible(true);
                          ui->gestionContacts->setEnabled(false);

                          ui->sav->setVisible(true);
                          ui->sav->setEnabled(true);


                          ui->vente->setVisible(true);
                          ui->vente->setEnabled(false);

                          ui->analyse->setVisible(true);
                          ui->analyse->setEnabled(false);

                          ui->label->setVisible(true);
                          ui->label_2->setVisible(true);
                          ui->label_3->setVisible(true);
                          ui->label_4->setVisible(true);
                          ui->label_5->setVisible(true);
                          ui->label_7->setVisible(true);
                          ui->precedent->setVisible(true);
                          ui->stackedWidget_3->setCurrentIndex(1);
                          ui->stackedWidget_2->setCurrentIndex(0);


                      }
                      else if(l->get_type()=="ALL"){

                          ui->Accueil->setVisible(true);
                          ui->gestionInterne->setVisible(true);
                          ui->gestionContacts->setVisible(true);
                          ui->sav->setVisible(true);
                          ui->vente->setVisible(true);
                          ui->analyse->setVisible(true);
                          ui->label->setVisible(true);
                          ui->label_2->setVisible(true);
                          ui->label_3->setVisible(true);
                          ui->label_4->setVisible(true);
                          ui->label_5->setVisible(true);
                          ui->label_7->setVisible(true);
                          ui->precedent->setVisible(true);
                          ui->stackedWidget_3->setCurrentIndex(1);
                          ui->stackedWidget_2->setCurrentIndex(0);
                      }

                  }
                  else QMessageBox::critical(this,tr("error"),tr("veuillez ressayer!"));*/
               }
               else
                   QMessageBox::critical(this,tr("error"),tr("veuillez ressayer!"));

    }

    void MainWindow::on_ajouter_clicked()
    {
        ui->stackedWidget_2->setCurrentIndex(2);
    }

    void MainWindow::on_modifier_clicked()
    {


        Ouvrier o;
        if(ui->tableOuvrier->selectionModel()->hasSelection())
        {
            ui->stackedWidget_2->setCurrentIndex(3);
            page=3;

        }
        ui->CIN_2->setText(ui->tableOuvrier->model()->data(ui->tableOuvrier->model()->index(ui->tableOuvrier->selectionModel()->currentIndex().row(),0)).toString());
        ui->ADRESSE_2->setText(ui->tableOuvrier->model()->data(ui->tableOuvrier->model()->index(ui->tableOuvrier->selectionModel()->currentIndex().row(),5)).toString());
        ui->NOM_2->setText(ui->tableOuvrier->model()->data(ui->tableOuvrier->model()->index(ui->tableOuvrier->selectionModel()->currentIndex().row(),1)).toString());
        ui->PRENOM_2->setText(ui->tableOuvrier->model()->data(ui->tableOuvrier->model()->index(ui->tableOuvrier->selectionModel()->currentIndex().row(),2)).toString());
        ui->TELEPHONE_2->setText(ui->tableOuvrier->model()->data(ui->tableOuvrier->model()->index(ui->tableOuvrier->selectionModel()->currentIndex().row(),4)).toString());
        ui->AGE_2->setText(ui->tableOuvrier->model()->data(ui->tableOuvrier->model()->index(ui->tableOuvrier->selectionModel()->currentIndex().row(),3)).toString());
        ui->SPECIALITE_2->setText(ui->tableOuvrier->model()->data(ui->tableOuvrier->model()->index(ui->tableOuvrier->selectionModel()->currentIndex().row(),7)).toString());
        ui->SEXE_2->setText(ui->tableOuvrier->model()->data(ui->tableOuvrier->model()->index(ui->tableOuvrier->selectionModel()->currentIndex().row(),6)).toString());
        ui->EMAIL_2->setText(ui->tableOuvrier->model()->data(ui->tableOuvrier->model()->index(ui->tableOuvrier->selectionModel()->currentIndex().row(),8)).toString());

    }

    void MainWindow::on_enregistrerOuvrier_clicked()
    {
        Ouvrier o(ui->CIN->text(),ui->NOM->text(),ui->PRENOM->text(),ui->AGE->text().toInt(),ui->TELEPHONE->text().toInt(),ui->ADRESSE->text(),ui->SEXE->text(),ui->SPECIALITE->text(),ui->EMAIL->text());
        o.ajouter();
        ui->ADRESSE->setText("");
        ui->AGE->setText("");
        ui->CIN->setText("");
        ui->EMAIL->setText("");
        ui->NOM->setText("");
        ui->PRENOM->setText("");
        ui->SEXE->setText("");
        ui->SPECIALITE->setText("");
        ui->TELEPHONE->setText("");
        ui->stackedWidget_2->setCurrentIndex(2);
        page=2;
        o.afficher(ui);
    }

    void MainWindow::on_enregistrerModificationOuvrier_clicked()
    {
        Ouvrier o(ui->CIN_2->text(),ui->NOM_2->text(),ui->PRENOM_2->text(),ui->AGE_2->text().toInt(),ui->TELEPHONE_2->text().toInt(),ui->ADRESSE_2->text(),ui->SEXE_2->text(),ui->SPECIALITE_2->text(),ui->EMAIL_2->text());

        o.modifier();
        ui->ADRESSE_2->setText("");
        ui->AGE_2->setText("");
        ui->CIN_2->setText("");
        ui->EMAIL_2->setText("");
        ui->NOM_2->setText("");
        ui->PRENOM_2->setText("");
        ui->SEXE_2->setText("");
        ui->SPECIALITE_2->setText("");
        ui->TELEPHONE_2->setText("");


        ui->stackedWidget_2->setCurrentIndex(1);
        page=1;
        o.afficher(ui);
    }

    void MainWindow::on_supprimer_clicked()
    {
        Ouvrier o;
        QMessageBox::StandardButton reply=QMessageBox::question(this,tr("suppression ouvrier"),tr("Etes-vous sur de vouloir supprimer cet ouvrier ?"),QMessageBox::Yes|QMessageBox::No);
        if (reply==QMessageBox::Yes)
        {
        if(ui->tableOuvrier->selectionModel()->hasSelection())
        {

            o.set_CIN(ui->tableOuvrier->model()->data(ui->tableOuvrier->model()->index(ui->tableOuvrier->selectionModel()->currentIndex().row(),0)).toString());
            o.set_Nom(ui->tableOuvrier->model()->data(ui->tableOuvrier->model()->index(ui->tableOuvrier->selectionModel()->currentIndex().row(),1)).toString());
            o.set_Prenom(ui->tableOuvrier->model()->data(ui->tableOuvrier->model()->index(ui->tableOuvrier->selectionModel()->currentIndex().row(),2)).toString());
            o.set_Age(ui->tableOuvrier->model()->data(ui->tableOuvrier->model()->index(ui->tableOuvrier->selectionModel()->currentIndex().row(),3)).toInt());
            o.set_Telephone(ui->tableOuvrier->model()->data(ui->tableOuvrier->model()->index(ui->tableOuvrier->selectionModel()->currentIndex().row(),4)).toInt());
            o.set_Adresse(ui->tableOuvrier->model()->data(ui->tableOuvrier->model()->index(ui->tableOuvrier->selectionModel()->currentIndex().row(),5)).toString());
            o.set_Sexe(ui->tableOuvrier->model()->data(ui->tableOuvrier->model()->index(ui->tableOuvrier->selectionModel()->currentIndex().row(),6)).toString());
            o.set_Specialite(ui->tableOuvrier->model()->data(ui->tableOuvrier->model()->index(ui->tableOuvrier->selectionModel()->currentIndex().row(),7)).toString());
            o.set_Email(ui->tableOuvrier->model()->data(ui->tableOuvrier->model()->index(ui->tableOuvrier->selectionModel()->currentIndex().row(),8)).toString());

        }
        if( o.supprimer()==true)
        {
            o.ajouterHistorique();
        }
        o.afficher(ui);

    }
    }

    void MainWindow::on_chercherouv_textEdited(const QString &arg1)
    {

        QSqlQueryModel *modal=new QSqlQueryModel();
       QSqlQuery q;


                q.prepare("select * from OUVRIER where NOM like'"+ui->chercherouv->text()+"%'");
                q.exec();
                modal->setQuery(q);
                 ui->tableOuvrier->setModel(modal);
    }

    void MainWindow::on_deconnexion_clicked()
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->stackedWidget_3->setCurrentIndex(0);
        page=0;
    }

    void MainWindow::on_tableOuvrier_clicked(const QModelIndex &index)
    {
        Ouvrier o;
       if(ui->tableOuvrier->selectionModel()->hasSelection())
       {
           o.aff(ui);
       }
    }

    void MainWindow::on_ajouterMateriel_clicked()
    {
         ui->stackedWidget_2->setCurrentIndex(5);
         page=5;
    }

    void MainWindow::on_modifierMateriel_clicked()
    {
        Materiaux m;

        if(ui->tableMateriaux->selectionModel()->hasSelection())
        {
            ui->stackedWidget_2->setCurrentIndex(6);
            page=6;

        }
        ui->code_2->setText(ui->tableMateriaux->model()->data(ui->tableMateriaux->model()->index(ui->tableMateriaux->selectionModel()->currentIndex().row(),0)).toString());

        ui->nom_2->setText(ui->tableMateriaux->model()->data(ui->tableMateriaux->model()->index(ui->tableMateriaux->selectionModel()->currentIndex().row(),1)).toString());

        ui->qte_2->setText(ui->tableMateriaux->model()->data(ui->tableMateriaux->model()->index(ui->tableMateriaux->selectionModel()->currentIndex().row(),2)).toString());

        m.afficher(ui);


    }

    void MainWindow::on_supprimerMateriel_clicked()
    {
        QMessageBox::StandardButton reply=QMessageBox::question(this,tr("suppression materiel"),tr("Etes-vous sur de vouloir supprimer ce materiel ?"),QMessageBox::Yes|QMessageBox::No);
        if (reply==QMessageBox::Yes)
        {
        Materiaux m;
        if(ui->tableMateriaux->selectionModel()->hasSelection())
        {

            m.set_Code(ui->tableMateriaux->model()->data(ui->tableMateriaux->model()->index(ui->tableMateriaux->selectionModel()->currentIndex().row(),0)).toInt());
            m.set_Nom(ui->tableMateriaux->model()->data(ui->tableMateriaux->model()->index(ui->tableMateriaux->selectionModel()->currentIndex().row(),1)).toString());
            m.set_Qte(ui->tableMateriaux->model()->data(ui->tableMateriaux->model()->index(ui->tableMateriaux->selectionModel()->currentIndex().row(),2)).toInt());

        }
        if(m.supprimer()==true)
        {
            m.ajouterHistorique();
        }
        m.afficher(ui);


    }
    }




    void MainWindow::on_enregistrerMateriel_clicked()
    {
        Materiaux m(ui->code->text().toInt(),ui->nom->text(),ui->qte->text().toInt(),ui->accorde->text().toInt());

        m.ajouter();
        m.afficher(ui);
        ui->code->setText("");
        ui->nom->setText("");
        ui->qte->setText("");
    }

    void MainWindow::on_gestionMateriaux_clicked()
    {
        ui->stackedWidget_2->setCurrentIndex(4);
        page=4;
        Materiaux m;
        m.afficher(ui);
    }


    void MainWindow::on_enregistrerModificationMateriel_clicked()
    {
        Materiaux m(ui->code_2->text().toInt(),ui->nom_2->text(),ui->qte_2->text().toInt(),ui->accorde->text().toInt());
         m.modifier();

       ui->stackedWidget_2->setCurrentIndex(4);
       page=4;
       m.afficher(ui);
    }

    void MainWindow::on_planification_clicked()
    {
        ui->stackedWidget_2->setCurrentIndex(9);
        page=9;
    }

    void MainWindow::on_ajouterRV_clicked()
    {
        Rendezvous r;
        QDateTime d;

        ui->stackedWidget_2->setCurrentIndex(10);
        page=10;
        QTextCharFormat currentDayHighlight;
        currentDayHighlight.setBackground(Qt::cyan);
       // QDate today = QDate::currentDate();

       // ui->calendarWidget->setDateTextFormat(ui->calendarWidget->selectedDate(), currentDayHighlight);
        QSqlQuery q;
          q.prepare("select date_RV from RV ");
         q.exec();

      while(q.next())
       {
          //d=QDateTime::fromString(q.value(0).toString(),"yyyy'-'MM'-'dd'T'hh:mm:ss");
          //d=QDateTime::fromString(q.value(0).toString(),"yyyy'-'MM'-'dd'T'hh:mm:ss");

        d=QDateTime ::fromString(q.value(0).toString(),"dd'-'MM'-'yyyy' 'hh:mm");


        ui->calendarWidget->setDateTextFormat(d.date(), currentDayHighlight);
       }
    }

    void MainWindow::on_afficherRV_clicked()
    {
        ui->stackedWidget_2->setCurrentIndex(12);
        page=12;
        Rendezvous r;
        r.afficher(ui);
    }

    void MainWindow::on_enregistrerRV_2_clicked()
    {
        Rendezvous r;
         r.modifier(ui);

        ui->stackedWidget->setCurrentIndex(12);
        page=12;
       r.afficher(ui);
    }

    void MainWindow::on_modifierRV_clicked()
    {
       if (ui->tableRV->selectionModel()->hasSelection())
            {
                ui->stackedWidget_2->setCurrentIndex(11);
                page=11;

            }
            Rendezvous r;
            //r.afficher(ui);
            ui->codeRV_2->setText(ui->tableRV->model()->data(ui->tableRV->model()->index(ui->tableRV->selectionModel()->currentIndex().row(),0)).toString());

            ui->dateTimeEdit_2->setDateTime(ui->tableRV->model()->data(ui->tableRV->model()->index(ui->tableRV->selectionModel()->currentIndex().row(),1)).toDateTime());

             ui->dateTimeEdit_2->setTime(ui->tableRV->model()->data(ui->tableRV->model()->index(ui->tableRV->selectionModel()->currentIndex().row(),1)).toTime());
            ui->ouvrierRV_2->setText(ui->tableRV->model()->data(ui->tableRV->model()->index(ui->tableRV->selectionModel()->currentIndex().row(),2)).toString());


    }

    void MainWindow::on_supprimerRV_clicked()
    {
        Rendezvous r;
        QMessageBox::StandardButton reply=QMessageBox::question(this,tr("suppression rendez_vous"),tr("Etes-vous sur de vouloir supprimer ce rendez_vous ?"),QMessageBox::Yes|QMessageBox::No);
        if (reply==QMessageBox::Yes)
        {
        if(ui->tableRV->selectionModel()->hasSelection())
        {

            r.set_crv(ui->tableRV->model()->data(ui->tableRV->model()->index(ui->tableRV->selectionModel()->currentIndex().row(),0)).toInt());
           r.set_cin(ui->tableRV->model()->data(ui->tableRV->model()->index(ui->tableRV->selectionModel()->currentIndex().row(),2)).toInt());
            r.set_date(ui->tableRV->model()->data(ui->tableRV->model()->index(ui->tableRV->selectionModel()->currentIndex().row(),1)).toDateTime());


        }
        if(r.supprimer(ui)==true)
        {

            r.ajouterHistorique();
        }
        r.afficher(ui);

        //
       /* Rendezvous r;
        if(ui->tableRV->selectionModel()->hasSelection())
        {
            r.supprimer(ui);

        }

        r.afficher(ui);*/
        }
    }

    void MainWindow::on_statistique_clicked()
    {
            Ouvrier o;
            ui->stackedWidget_2->setCurrentIndex(13);
            page=13;
                o.makePlot(ui->customPlot);
    }

    void MainWindow::on_enregistrerAccordination_clicked()
    {
        Materiaux m(ui->code_3->text().toInt(),ui->nom_3->text(),ui->qte_3->text().toInt(),ui->accorde->text().toInt());
        m.accorder();

      ui->stackedWidget_2->setCurrentIndex(4);
      page=4;
      m.afficher(ui);
    }

    void MainWindow::on_precedent_clicked()
    {
        if(page==1)
        {
            ui->stackedWidget_2->setCurrentIndex(0);
        }
        if(page==2)
        {
            ui->stackedWidget_2->setCurrentIndex(1);
        }
        if(page==3)
        {
            ui->stackedWidget_2->setCurrentIndex(1);
        }
        if(page==4)
        {
            ui->stackedWidget_2->setCurrentIndex(0);
        }
        if(page==5)
        {
            ui->stackedWidget_2->setCurrentIndex(4);
        }
        if(page==6)
        {
            ui->stackedWidget_2->setCurrentIndex(4);
        }
        if(page==7)
        {
            ui->stackedWidget_2->setCurrentIndex(4);
        }
        if(page==8)
        {
            ui->stackedWidget_2->setCurrentIndex(0);
        }
        if(page==9)
        {
            ui->stackedWidget_2->setCurrentIndex(0);
        }
        if(page==10)
        {
            ui->stackedWidget_2->setCurrentIndex(9);
        }
        if(page==11)
        {
            ui->stackedWidget_2->setCurrentIndex(9);
        }
        if(page==12)
        {
            ui->stackedWidget_2->setCurrentIndex(9);
        }
        if(page==13)
        {
            ui->stackedWidget_2->setCurrentIndex(0);
        }

    }

    void MainWindow::on_tableMateriaux_clicked(const QModelIndex &index)
    {
        Materiaux m;
            qint8 duree=2000;

            if(ui->tableMateriaux->selectionModel()->hasSelection())
            {
                QString titre(ui->tableMateriaux->model()->data(ui->tableMateriaux->model()->index(ui->tableMateriaux->selectionModel()->currentIndex().row(),1)).toString());
                if((ui->tableMateriaux->model()->data(ui->tableMateriaux->model()->index(ui->tableMateriaux->selectionModel()->currentIndex().row(),2)).toInt())<=2&&((ui->tableMateriaux->model()->data(ui->tableMateriaux->model()->index(ui->tableMateriaux->selectionModel()->currentIndex().row(),2)).toInt())!=0))
                {
                    QString text("Stock arrive a epuisé");

                    notification->show();

                    notification->showMessage(titre,text,QSystemTrayIcon::Information,duree);
                }
                if((ui->tableMateriaux->model()->data(ui->tableMateriaux->model()->index(ui->tableMateriaux->selectionModel()->currentIndex().row(),2)).toInt())==0)
                {
                    QString text("Stock epuisé!");

                    notification->show();
                    notification->showMessage(titre,text,QSystemTrayIcon::Critical,duree);
                }
                m.a(ui);
            }

    }

    void MainWindow::on_ajouterMateriel_2_clicked()
    {

        if(ui->tableMateriaux->selectionModel()->hasSelection())
        {
        ui->stackedWidget_2->setCurrentIndex(7);
        page=7;
        }

    ui->code_3->setText(ui->tableMateriaux->model()->data(ui->tableMateriaux->model()->index(ui->tableMateriaux->selectionModel()->currentIndex().row(),0)).toString());

    ui->nom_3->setText(ui->tableMateriaux->model()->data(ui->tableMateriaux->model()->index(ui->tableMateriaux->selectionModel()->currentIndex().row(),1)).toString());

    ui->qte_3->setText(ui->tableMateriaux->model()->data(ui->tableMateriaux->model()->index(ui->tableMateriaux->selectionModel()->currentIndex().row(),2)).toString());
    ui->accorde->setText(ui->tableMateriaux->model()->data(ui->tableMateriaux->model()->index(ui->tableMateriaux->selectionModel()->currentIndex().row(),3)).toString());
    }

    void MainWindow::on_enregistrerRV_clicked()
    {
        Rendezvous r;
        r.ajouter(ui);
        QTextCharFormat currentDayHighlight;
        currentDayHighlight.setBackground(Qt::cyan);
       // QDate today = QDate::currentDate();

       ui->calendarWidget->setDateTextFormat(ui->calendarWidget->selectedDate(), currentDayHighlight);
    }

    void MainWindow::on_historique_clicked()
    {
        ui->stackedWidget_2->setCurrentIndex(8);
        page=8;
        Materiaux m;
        Ouvrier o;
        Rendezvous r;
        o.afficherHistorique(ui);
        m.afficherHistorique(ui);
        r.afficherHistorique(ui);
    }

    void MainWindow::on_calendarWidget_clicked(const QDate &date)
    {
        ui->dateTimeEdit->setDate(ui->calendarWidget->selectedDate());
    }

void MainWindow::on_gestionContacts_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_gestion_client_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(15);
}

void MainWindow::on_gestion_fournisseur_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(18);

}

void MainWindow::on_gestion_bouquet_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(21);
}

void MainWindow::on_Fidelisation_client_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(26);
}

void MainWindow::on_Messagerie_fournisseur_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(30);
}

void MainWindow::on_ajout_client_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(16);
}

void MainWindow::on_consult_client_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(17);
}

void MainWindow::on_ajout_four_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(19);
}

void MainWindow::on_consult_four_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(20);
}

void MainWindow::on_ajout_bouquet_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(22);
}

void MainWindow::on_affectation_bouquet_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(23);
}

void MainWindow::on_consutation_bouquet_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(24);
}

void MainWindow::on_statistique_bouquet_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(25);
}

void MainWindow::on_Fidelisation_client_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(27);
}

void MainWindow::on_Fidelisation_client_3_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(28);
}

void MainWindow::on_Fidelisation_client_4_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(29);
}

void MainWindow::on_Fidelisation_client_5_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(31);
}


void MainWindow::on_Fidelisation_client_6_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(32);
}

void MainWindow::on_Ajouter_client_clicked()
{
    client c;
    QMessageBox::StandardButton reply=QMessageBox::question(this,tr("Ajout client"),tr("Etes-vous sur de vouloir ajouter ce client ?"),QMessageBox::Yes|QMessageBox::No);
    if (reply==QMessageBox::Yes)
{
             c.Ajouter_client(ui);
                   popup.setPopupText("le client a ete ajoute");
                   popup.show();
                   QMessageBox::information(this,tr("ajout client"),tr("le client est ajouté avec succes ")) ;
  }
  else
  popup.setPopupText("Echec !! ");
  popup.show();

}

void MainWindow::on_Rech_button_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
QSqlQuery aff ;
aff.prepare("SELECT cin,nom,prenom,date_naiss,sexe,mail,adresse,ville,code_postal,telephone FROM CLIENT where NOM LIKE ? ");
aff.bindValue(0,ui->Recher_Nom_Client->text()+"%");

aff.exec();

             model->setQuery(aff);
             model->setHeaderData(0, Qt::Horizontal, tr("cin"));
             model->setHeaderData(1, Qt::Horizontal, tr("nom"));
             model->setHeaderData(2, Qt::Horizontal, tr("prenom"));
             model->setHeaderData(3, Qt::Horizontal, tr("date_naiss"));
             model->setHeaderData(4, Qt::Horizontal, tr("sexe"));
             model->setHeaderData(5, Qt::Horizontal, tr("mail"));
             model->setHeaderData(6, Qt::Horizontal, tr("adresse"));
             model->setHeaderData(7, Qt::Horizontal, tr("ville"));
             model->setHeaderData(8, Qt::Horizontal, tr("code_postal"));
             model->setHeaderData(9, Qt::Horizontal, tr("telephone"));
            ui->table_aff_client->setModel(model);
            if (model->lastError().isValid())
                qDebug() << model->lastError();
            ui->table_aff_client->show();
}

void MainWindow::on_afficher_client_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
            model->setQuery("SELECT cin,nom,prenom,date_naiss,sexe,mail,adresse,ville,code_postal,telephone FROM CLIENT");
            model->setHeaderData(0, Qt::Horizontal, tr("cin"));
            model->setHeaderData(1, Qt::Horizontal, tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, tr("date_naiss"));
            model->setHeaderData(4, Qt::Horizontal, tr("sexe"));
            model->setHeaderData(5, Qt::Horizontal, tr("mail"));
            model->setHeaderData(6, Qt::Horizontal, tr("adresse"));
            model->setHeaderData(7, Qt::Horizontal, tr("ville"));
            model->setHeaderData(8, Qt::Horizontal, tr("code_postal"));
            model->setHeaderData(9, Qt::Horizontal, tr("telephone"));


            ui->table_aff_client->setModel(model);
            if (model->lastError().isValid())
                qDebug() << model->lastError();
            ui->table_aff_client->show();
}

void MainWindow::on_Tri_Nom_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
            model->setQuery("SELECT cin,nom,prenom,date_naiss,sexe,mail,adresse,ville,code_postal,telephone FROM CLIENT ORDER BY NOM");
            model->setHeaderData(0, Qt::Horizontal, tr("cin"));
            model->setHeaderData(1, Qt::Horizontal, tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, tr("date_naiss"));
            model->setHeaderData(4, Qt::Horizontal, tr("sexe"));
            model->setHeaderData(5, Qt::Horizontal, tr("mail"));
            model->setHeaderData(6, Qt::Horizontal, tr("adresse"));
            model->setHeaderData(7, Qt::Horizontal, tr("ville"));
            model->setHeaderData(8, Qt::Horizontal, tr("code_postal"));
            model->setHeaderData(9, Qt::Horizontal, tr("telephone"));


            ui->table_aff_client->setModel(model);
            if (model->lastError().isValid())
                qDebug() << model->lastError();
            ui->table_aff_client->show();
}

void MainWindow::on_Modifier_client_clicked()
{
    QSqlQuery qry ;
       client c ;
       QMessageBox::StandardButton reply=QMessageBox::question(this,tr("modification client"),tr("Etes-vous sur de vouloir modifier ce client ?"),QMessageBox::Yes|QMessageBox::No);
       if (reply==QMessageBox::Yes)
       {
           c.Modifier_client(ui);

                QSqlQueryModel *model = new QSqlQueryModel;
                        model->setQuery("SELECT cin,nom,prenom,date_naiss,sexe,mail,adresse,ville,code_postal,telephone FROM CLIENT");
                        model->setHeaderData(0, Qt::Horizontal, tr("cin"));
                        model->setHeaderData(1, Qt::Horizontal, tr("nom"));
                        model->setHeaderData(2, Qt::Horizontal, tr("prenom"));
                        model->setHeaderData(3, Qt::Horizontal, tr("date_naiss"));
                        model->setHeaderData(4, Qt::Horizontal, tr("sexe"));
                        model->setHeaderData(5, Qt::Horizontal, tr("mail"));
                        model->setHeaderData(6, Qt::Horizontal, tr("adresse"));
                        model->setHeaderData(7, Qt::Horizontal, tr("ville"));
                        model->setHeaderData(8, Qt::Horizontal, tr("code_postal"));
                        model->setHeaderData(9, Qt::Horizontal, tr("telephone"));


                        ui->table_aff_client->setModel(model);
                        if (model->lastError().isValid())
                            qDebug() << model->lastError();
                        ui->table_aff_client->show();
                        popup.setPopupText("le client est modifié avec succes");
                        popup.show();
                        QMessageBox::information(this,tr("modification client"),tr("le client est modifié avec succes ")) ;
       }
       else
       popup.setPopupText("Echec !! ");
       popup.show();


}

void MainWindow::on_table_aff_client_clicked(const QModelIndex &index)
{
    QString valeur=ui->table_aff_client->model()->data(index).toString();
    QSqlQuery q ;
    client c;
q.prepare("SELECT * FROM CLIENT WHERE CIN='"+valeur+"' ");
if (q.exec())
{
    while(q.next())
    {
           c.setCIN_client(q.value(0).toInt());
           c.setMail_client(q.value(6).toString());
           c.setAdresse_client(q.value(7).toString());
           c.setVille_client(q.value(8).toString());
           c.setCode_postal_client(q.value(9).toInt());
           c.setTelephone_client(q.value(12).toInt());
           ui->label_cin->setText(QString::number(c.getCIN_client()));

            ui->Tel_modif->setText(QString::number(c.getTelephone_client()));
             ui->Mail_modif->setText(c.getMail_client());
              ui->Adresse_modif->setText(c.getAdresse_client());
               ui->Ville_modif->setText(c.getVille_client());
                ui->Code_modif->setText(QString::number(c.getCode_postal_client()));



    }
}
}

void MainWindow::on_supprimer_client_clicked()
{
    client c ;
    QMessageBox::StandardButton reply=QMessageBox::question(this,tr("suppression client"),tr("Etes-vous sur de vouloir supprimer ce client ?"),QMessageBox::Yes|QMessageBox::No);
    if (reply==QMessageBox::Yes)
    {
     c.Supprimer_client(ui);



               QSqlQueryModel *model = new QSqlQueryModel;
                       model->setQuery("SELECT cin,nom,prenom,date_naiss,sexe,mail,adresse,ville,code_postal,telephone FROM CLIENT");
                       model->setHeaderData(0, Qt::Horizontal, tr("cin"));
                       model->setHeaderData(1, Qt::Horizontal, tr("nom"));
                       model->setHeaderData(2, Qt::Horizontal, tr("prenom"));
                       model->setHeaderData(3, Qt::Horizontal, tr("date_naiss"));
                       model->setHeaderData(4, Qt::Horizontal, tr("sexe"));
                       model->setHeaderData(5, Qt::Horizontal, tr("mail"));
                       model->setHeaderData(6, Qt::Horizontal, tr("adresse"));
                       model->setHeaderData(7, Qt::Horizontal, tr("ville"));
                       model->setHeaderData(8, Qt::Horizontal, tr("code_postal"));
                       model->setHeaderData(9, Qt::Horizontal, tr("telephone"));


                       ui->table_aff_client->setModel(model);
                       if (model->lastError().isValid())
                           qDebug() << model->lastError();
                       ui->table_aff_client->show();
                       popup.setPopupText("le client est supprimé");
                       popup.show();
                       QMessageBox::information(this,tr("suppression client"),tr("le client est supprimé avec succes ")) ;
    }
}

void MainWindow::on_ajouter_fournisseur_clicked()
{
    fournisseur f;
    QMessageBox::StandardButton reply=QMessageBox::question(this,tr("Ajout fournisseur"),tr("Etes-vous sur de vouloir ajouter ce fournisseur ?"),QMessageBox::Yes|QMessageBox::No);
    if (reply==QMessageBox::Yes){
    f.Ajouter_fournisseur(ui);
    popup.setPopupText("le fournisseur est ajouté");
    popup.show();
     QMessageBox::information(this,tr("Ajout fournisseur"),tr("le fournisseur est ajouté avec succes ")) ;
    }
  else

    popup.setPopupText("Echec !! ");
    popup.show();


}

void MainWindow::on_annuler_fournisseur_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(18);
}

void MainWindow::on_Rech_fournisseur_clicked()
{

    QSqlQueryModel *model = new QSqlQueryModel;
QSqlQuery aff ;
aff.prepare("SELECT * FROM FOURNISSEUR where MATIERE LIKE ? ");
aff.bindValue(0,ui->Recher_matiere_fournisseur->text()+"%");

aff.exec();

             model->setQuery(aff);
             model->setHeaderData(0, Qt::Horizontal, tr("id"));
             model->setHeaderData(1, Qt::Horizontal, tr("nom"));
             model->setHeaderData(2, Qt::Horizontal, tr("matiere"));
             model->setHeaderData(3, Qt::Horizontal, tr("telephone"));
             model->setHeaderData(4, Qt::Horizontal, tr("mail"));
             model->setHeaderData(5, Qt::Horizontal, tr("ville"));
             model->setHeaderData(6, Qt::Horizontal, tr("code_postal"));
             model->setHeaderData(7, Qt::Horizontal, tr("adresse"));
            ui->affichage_fournisseur->setModel(model);
            if (model->lastError().isValid())
                qDebug() << model->lastError();
            ui->affichage_fournisseur->show();

}

void MainWindow::on_afficher_fournisseur_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
            model->setQuery("SELECT * FROM fournisseur");
            model->setHeaderData(0, Qt::Horizontal, tr("id"));
            model->setHeaderData(1, Qt::Horizontal, tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, tr("matiere"));
            model->setHeaderData(3, Qt::Horizontal, tr("telephone"));
            model->setHeaderData(4, Qt::Horizontal, tr("mail"));
            model->setHeaderData(5, Qt::Horizontal, tr("ville"));
            model->setHeaderData(6, Qt::Horizontal, tr("code_postal"));
            model->setHeaderData(7, Qt::Horizontal, tr("adresse"));


            ui->affichage_fournisseur->setModel(model);
            if (model->lastError().isValid())
                qDebug() << model->lastError();
            ui->affichage_fournisseur->show();
}

void MainWindow::on_Tri_Nom_fournisseur_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM FOURNISSEUR ORDER BY NOM");
    model->setHeaderData(0, Qt::Horizontal, tr("id"));
    model->setHeaderData(1, Qt::Horizontal, tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, tr("matiere"));
    model->setHeaderData(3, Qt::Horizontal, tr("telephone"));
    model->setHeaderData(4, Qt::Horizontal, tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, tr("ville"));
    model->setHeaderData(6, Qt::Horizontal, tr("code_postal"));
    model->setHeaderData(7, Qt::Horizontal, tr("adresse"));


    ui->affichage_fournisseur->setModel(model);
    if (model->lastError().isValid())
        qDebug() << model->lastError();
    ui->affichage_fournisseur->show();
}

void MainWindow::on_affichage_fournisseur_clicked(const QModelIndex &index)
{
    QString valeur=ui->affichage_fournisseur->model()->data(index).toString();
    QSqlQuery q ;
    fournisseur c;
q.prepare("SELECT * FROM fournisseur WHERE ID='"+valeur+"' ");
if (q.exec())
{
    while(q.next())
    {
           c.setID_fournisseur(q.value(0).toInt());
           c.setMail_fournisseur(q.value(4).toString());
           c.setAdresse_fournisseur(q.value(7).toString());
           c.setVille_fournisseur(q.value(5).toString());
           c.setCode_postal_fournisseur(q.value(6).toInt());
           c.setTelephone_fournisseur(q.value(3).toInt());
           c.setmatiere_fournisseur(q.value(2).toString());
           ui->label_id_fournisseur->setText(QString::number(c.getID_fournisseur()));
           ui->Tel_modif_four->setText(QString::number(c.getTelephone_fournisseur()));
           ui->Mail_modif_four->setText(c.getMail_fournisseur());
           ui->Adresse_modif_four->setText(c.getAdresse_fournisseur());
           ui->Ville_modif_four->setText(c.getVille_fournisseur());
           ui->Code_modif_four->setText(QString::number(c.getCode_postal_fournisseur()));
           ui->Matiere_modif_four->setText(c.getmatiere_fournisseur());



    }
}
}

void MainWindow::on_modifier_fournisseur_clicked()
{
    fournisseur f ;
    QMessageBox::StandardButton reply=QMessageBox::question(this,tr("Modification fournisseur"),tr("Etes-vous sur de vouloir modifier ce fournisseur ?"),QMessageBox::Yes|QMessageBox::No);
    if (reply==QMessageBox::Yes){
    f.Modifier_fournisseur(ui);




                QSqlQueryModel *model = new QSqlQueryModel;
                        model->setQuery("SELECT * FROM FOURNISSEUR");
                        model->setHeaderData(0, Qt::Horizontal, tr("id"));
                        model->setHeaderData(1, Qt::Horizontal, tr("nom"));
                        model->setHeaderData(2, Qt::Horizontal, tr("matiere"));
                        model->setHeaderData(3, Qt::Horizontal, tr("telephone"));
                        model->setHeaderData(4, Qt::Horizontal, tr("mail"));
                        model->setHeaderData(5, Qt::Horizontal, tr("ville"));
                        model->setHeaderData(6, Qt::Horizontal, tr("code_postal"));
                        model->setHeaderData(7, Qt::Horizontal, tr("adresse"));


                        ui->affichage_fournisseur->setModel(model);
                        if (model->lastError().isValid())
                            qDebug() << model->lastError();
                        ui->affichage_fournisseur->show();
                        popup.setPopupText(" Modification Reussite !  ");
                                               popup.show();
                  QMessageBox::information(this,tr("Modification fournisseur"),tr("le fournisseur est modifié avec succes ")) ;
    }

        else
    popup.setPopupText("Echec !! ");
    popup.show();

}

void MainWindow::on_supprimer_fournisseur_clicked()
{
    fournisseur f ;
    QMessageBox::StandardButton reply=QMessageBox::question(this,tr("Modification fournisseur"),tr("Etes-vous sur de vouloir modifier ce fournisseur ?"),QMessageBox::Yes|QMessageBox::No);
    if (reply==QMessageBox::Yes){
    f.Supprimer_fournisseur(ui);


                  popup.setPopupText("le fournisseur est supprimé");
                  popup.show();
              QSqlQueryModel *model = new QSqlQueryModel;
                      model->setQuery("SELECT * FROM fournisseur");
                      model->setHeaderData(0, Qt::Horizontal, tr("id"));
                      model->setHeaderData(1, Qt::Horizontal, tr("nom"));
                      model->setHeaderData(2, Qt::Horizontal, tr("matiere"));
                      model->setHeaderData(3, Qt::Horizontal, tr("telephone"));
                      model->setHeaderData(4, Qt::Horizontal, tr("mail"));
                      model->setHeaderData(5, Qt::Horizontal, tr("ville"));
                      model->setHeaderData(6, Qt::Horizontal, tr("code_postal"));
                      model->setHeaderData(7, Qt::Horizontal, tr("adresse"));


                      ui->affichage_fournisseur->setModel(model);
                      if (model->lastError().isValid())
                          qDebug() << model->lastError();
                      ui->affichage_fournisseur->show();
                      popup.setPopupText("le fournisseur est supprimé");
                      popup.show();
                      QMessageBox::information(this,tr("Suppression fournisseur"),tr("le fournisseur est supprimé avec succes ")) ;
    }
    else

    popup.setPopupText("Echec !! ");
    popup.show();


}

void MainWindow::on_ajouter_bouquet_clicked()
{
    bouquet b;
               b.Ajouter_bouquet(ui);
               popup.setPopupText("le bouquet est ajouté avec succes ");
        popup.show();



}

void MainWindow::on_bouquet_client_clicked(const QModelIndex &index)
{
    client Pr,Cl;
    QString valeur=ui->bouquet_client->model()->data(index).toString();
    QSqlQuery q ;

q.prepare("SELECT * FROM CLIENT WHERE CIN='"+valeur+"' ");
if (q.exec())
{
    while(q.next())
    {
           Cl.setCIN_client(q.value(0).toInt());

    }
}
}

void MainWindow::on_bouquet_bouquet_clicked(const QModelIndex &index)
{
    client Pr,Cl;
    QString valeur=ui->bouquet_bouquet->model()->data(index).toString();
        QSqlQuery q ;

    q.prepare("SELECT * FROM BOUQUET WHERE ID_BOUQUET='"+valeur+"' ");
    if (q.exec())
    {
        while(q.next())
        {  qDebug() << q.value(0);

               Cl.setID_bouquet(q.value(0).toInt());
                      qDebug() << Cl.getID_bouquet();

        }
    }
}

void MainWindow::on_actua_bouquet_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
            model->setQuery("SELECT * FROM CLIENT");
            model->setHeaderData(0, Qt::Horizontal, tr("CIN"));
            model->setHeaderData(1, Qt::Horizontal, tr("NOM"));
            model->setHeaderData(2, Qt::Horizontal, tr("PRENOM"));
            model->setHeaderData(3, Qt::Horizontal, tr("AGE"));
            model->setHeaderData(4, Qt::Horizontal, tr("DATE_NAISS"));
            model->setHeaderData(5, Qt::Horizontal, tr("SEXE"));
            model->setHeaderData(6, Qt::Horizontal, tr("MAIL"));
            model->setHeaderData(7, Qt::Horizontal, tr("ADRESSE"));
            model->setHeaderData(8, Qt::Horizontal, tr("VILLE"));
            model->setHeaderData(9, Qt::Horizontal, tr("CODE_POSTAL"));
            model->setHeaderData(10, Qt::Horizontal, tr("POINTS	"));
            model->setHeaderData(11, Qt::Horizontal, tr("COUPON"));
            model->setHeaderData(12, Qt::Horizontal, tr("TELEPHONE"));
            model->setHeaderData(13, Qt::Horizontal, tr("MESSAGE"));
            model->setHeaderData(14, Qt::Horizontal, tr("DATE_AJOUT"));
            model->setHeaderData(15, Qt::Horizontal, tr("REMISE"));
            model->setHeaderData(16, Qt::Horizontal, tr("ID_BOUQUET"));

            ui->bouquet_client->setModel(model);
            if (model->lastError().isValid())
                qDebug() << model->lastError();
            ui->bouquet_client->show();

QSqlQueryModel *model1 = new QSqlQueryModel;

                    model1->setQuery("SELECT ID_BOUQUET,NOM_BOUQUET FROM BOUQUET");
                     model1->setHeaderData(0, Qt::Horizontal, tr("ID BOUQUET"));
                    model1->setHeaderData(1, Qt::Horizontal, tr("NOM BOUQUET"));


                    ui->bouquet_bouquet->setModel(model1);
                    if (model1->lastError().isValid())
                        qDebug() << model1->lastError();
                    ui->bouquet_bouquet->show();
}

void MainWindow::on_affecter_bouquet_clicked()
{
    client Pr,Cl;
    QSqlQuery qry ;



       qry.prepare("UPDATE CLIENT SET ID_BOUQUET =? WHERE CIN = (?)");
       qry.bindValue(0,QString::number(Cl.getID_bouquet()));
       qDebug() << Cl.getID_bouquet();

       qry.bindValue(1,QString::number(Cl.getCIN_client()));
                if(qry.exec())
                {
                    popup.setPopupText(" l'affectation est reussite !  ");
                                           popup.show();

                }
                else
                { popup.setPopupText(" ECHEC d'affectation affectation  !  ");
                    popup.show();}

}

void MainWindow::on_afficher_les_bouquets_2_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQueryModel *model1 = new QSqlQueryModel;

            model->setQuery("SELECT cin,nom,prenom,id_bouquet FROM CLIENT");
            model->setHeaderData(0, Qt::Horizontal, tr("cin"));
            model->setHeaderData(1, Qt::Horizontal, tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, tr("id_bouquet"));
            model1->setQuery("SELECT id_bouquet,nom_bouquet FROM BOUQUET");
            model1->setHeaderData(0, Qt::Horizontal, tr("ID_bouquet"));
            model1->setHeaderData(1, Qt::Horizontal, tr("Nom_bouquet"));



            ui->affichage_bouquet_3->setModel(model);
            if (model->lastError().isValid())
                qDebug() << model->lastError();
            ui->affichage_bouquet_3->show();
            ui->affichage_bouquet_4->setModel(model1);
            if (model->lastError().isValid())
                qDebug() << model->lastError();
            ui->affichage_bouquet_4->show();
}

void MainWindow::on_commandLinkButton_2_clicked()
{
   /* int reparation,desinsectation,electricite,menage,peinture,cours,demenagement,plomberie,jardinage,transport,baby_sitting,soignants,total ;
       QSqlQuery aff_total, aff_reparation ,aff_desinsectation,aff_electricite,aff_menage,aff_peinture,aff_cours,aff_demenagement,aff_plomberie,aff_jardinage,aff_transport,aff_babbysitting,aff_soignants;
       aff_total.prepare("select COUNT(*) from BOUQUET ");
       aff_total.exec();
       aff_total.next();
      total = aff_total.value(0).toInt();

       aff_reparation.prepare("select COUNT(*) from BOUQUET WHERE REPARATION	='Y'  ");
       aff_reparation.exec();
       aff_reparation.next();
      reparation = aff_reparation.value(0).toInt();

      aff_desinsectation.prepare("select COUNT(*) from BOUQUET WHERE DESINSECTISATION='Y'  ");
      aff_desinsectation.exec();
      aff_desinsectation.next();
     desinsectation = aff_desinsectation.value(0).toInt();

     aff_electricite.prepare("select COUNT(*) from BOUQUET WHERE ELECTRICITE ='Y' ");
     aff_electricite.exec();
     aff_electricite.next();
    electricite = aff_electricite.value(0).toInt();

    aff_menage.prepare("select COUNT(*) from BOUQUET WHERE MENAGE ='Y'  ");
    aff_menage.exec();
    aff_menage.next();
   menage = aff_menage.value(0).toInt();

   aff_peinture.prepare("select COUNT(*) from BOUQUET WHERE PEINTURE ='Y'  ");
   aff_peinture.exec();
   aff_peinture.next();
  peinture = aff_peinture.value(0).toInt();

  aff_cours.prepare("select COUNT(*) from BOUQUET WHERE COURS_PART ='Y' ");
  aff_cours.exec();
  aff_cours.next();
 cours = aff_cours.value(0).toInt();

 aff_demenagement.prepare("select COUNT(*) from BOUQUET WHERE DEMENAGEMENT ='Y' ");
 aff_demenagement.exec();
 aff_demenagement.next();
demenagement = aff_demenagement.value(0).toInt();

aff_plomberie.prepare("select COUNT(*) from BOUQUET WHERE PLOMBERIE ='Y'  ");
aff_plomberie.exec();
aff_plomberie.next();
plomberie = aff_plomberie.value(0).toInt();

aff_jardinage.prepare("select COUNT(*) from BOUQUET WHERE JARDINAGE ='Y'  ");
aff_jardinage.exec();
aff_jardinage.next();
jardinage = aff_jardinage.value(0).toInt();


aff_transport.prepare("select COUNT(*) from BOUQUET WHERE TRANSPORT ='Y'  ");
aff_transport.exec();
aff_transport.next();
transport = aff_transport.value(0).toInt();

aff_babbysitting.prepare("select COUNT(*) from BOUQUET WHERE BABY_SITTING ='Y'  ");
aff_babbysitting.exec();
aff_babbysitting.next();
baby_sitting = aff_babbysitting.value(0).toInt();

aff_soignants.prepare("select COUNT(*) from BOUQUET WHERE SOIGNANTS ='Y'  ");
aff_soignants.exec();
aff_soignants.next();
soignants = aff_soignants.value(0).toInt();












       auto layout = new QBoxLayout(QBoxLayout::LeftToRight, this->ui->stat_bouquet_2);

       chartView = new QChartView();
       barSeries = new QBarSeries(this);
       auto axisY = new QValueAxis(this);
       auto axisX = new QBarCategoryAxis(this);

       axisX->append(QStringList {"reparation","desinsectation","electricite","menage","peinture","cours_part","demenagement","plomberie","jardinage","transport","baby_sitting","soignants"});
       axisY->setTickCount(total);
       axisY->setRange(0,total);
      // axisY->setLabelFormat("%f");

        chartView->chart()->setAxisX(axisX);
       chartView->chart()->setAxisY(axisY);

     //  loadData();





           auto barSet = new QBarSet("Stat. Bouquet", this);

           *barSet << reparation<<desinsectation<<electricite<<menage<<peinture<<cours<<demenagement<<plomberie<<jardinage<<transport<<baby_sitting<<soignants ;
qDebug() << reparation<<desinsectation<<electricite<<menage<<peinture<<cours<<demenagement<<plomberie<<jardinage<<transport<<baby_sitting<<soignants ;
           barSeries->append(barSet);



       chartView->setRenderHint(QPainter::Antialiasing);
       chartView->chart()->addSeries(barSeries);
          chartView->chart()->setAnimationOptions(QChart::AllAnimations);
       chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
       chartView->chart()->legend()->setFont(QFont("Arial", 9));

     layout->addWidget(chartView);*/
}

void MainWindow::on_actualiser_parrain_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT cin,nom,prenom,sexe,telephone FROM CLIENT");
    model->setHeaderData(0, Qt::Horizontal, tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, tr("sexe"));
    model->setHeaderData(4, Qt::Horizontal, tr("telephone"));



    ui->cin_parrain->setModel(model);
    if (model->lastError().isValid())
        qDebug() << model->lastError();
    ui->cin_parrain->show();
    QSqlQueryModel *model1 = new QSqlQueryModel;

    model1->setQuery("SELECT cin,nom,prenom,sexe,telephone FROM CLIENT");
    model1->setHeaderData(0, Qt::Horizontal, tr("cin"));
    model1->setHeaderData(1, Qt::Horizontal, tr("nom"));
    model1->setHeaderData(2, Qt::Horizontal, tr("prenom"));
    model1->setHeaderData(4, Qt::Horizontal, tr("telephone"));


    ui->nom_client_parrain->setModel(model1);
    if (model1->lastError().isValid())
        qDebug() << model1->lastError();
    ui->nom_client_parrain->show();

}

void MainWindow::on_attribution_remise_parrain_clicked()
{
    client Pr;
    QSqlQuery qry ;

       qry.prepare("UPDATE CLIENT SET CP_20 =?  WHERE CIN = ?");
        qry.bindValue(0,ui->Remise->currentText().toInt());
       qry.bindValue(1,QString::number(Pr.getCIN_client()));



                if(qry.exec())
                {
                    popup.setPopupText("la remise est attribué au parrain !");
                    popup.show();

                }
                else
                { popup.setPopupText("ECHEC d'attribution de la remise !! ");
                    popup.show();}

}

void MainWindow::on_cin_parrain_activated(const QModelIndex &index)
{
    client Pr,Cl;
    QString val=ui->cin_parrain->model()->data(index).toString();
       QSqlQuery qry ;
   qry.prepare("SELECT * FROM CLIENT WHERE CIN='"+val+"' ");

   if (qry.exec())
   {
       while(qry.next())
       {Pr.setCIN_client(qry.value(0).toInt());
            Pr.setNom_client(qry.value(1).toString());

              ui->Label_parrain->setText( qry.value(1).toString());

       }
   }
}

void MainWindow::on_nom_client_parrain_activated(const QModelIndex &index)
{
    client Pr,Cl;
    QString val=ui->nom_client_parrain->model()->data(index).toString();
       QSqlQuery qry ;
   qry.prepare("SELECT * FROM CLIENT WHERE CIN='"+val+"' ");

   if (qry.exec())
   {
       while(qry.next())
       {Cl.setCIN_client(qry.value(0).toInt());
            Cl.setNom_client(qry.value(1).toString());

              ui->Label_client->setText( qry.value(1).toString());

       }
   }
}

void MainWindow::on_table_attribution_coupon_clicked(const QModelIndex &index)
{
    client Pr,Cl;
    QString valeur=ui->table_attribution_coupon->model()->data(index).toString();
       QSqlQuery q ;

   q.prepare("SELECT * FROM CLIENT WHERE CIN='"+valeur+"' ");
   if (q.exec())
   {
       while(q.next())
       {

              Cl.setCIN_client(q.value(0).toInt());
                Cl.setCoupon_client(q.value(11).toInt());
       }
   }
}

void MainWindow::on_attribuer_des_coupons_clicked()
{
    client Pr,Cl;
    int nv_nb_coupon=Cl.getCoupon_client()+ ui->nb_coupon->text().toInt();
    QSqlQuery qry ;

       qry.prepare("UPDATE CLIENT SET CP_10 =?  WHERE CIN= ?");
       qry.bindValue(0,nv_nb_coupon);
        qry.bindValue(1,QString::number(Cl.getCIN_client()));


                if(qry.exec())
                {
                    popup.setPopupText(" L'attribution est reussite !  ");
                                           popup.show();
                QSqlQueryModel *model = new QSqlQueryModel;
                model->setQuery("SELECT cin,nom,prenom,CP_10 FROM CLIENT");
                model->setHeaderData(0, Qt::Horizontal, tr("cin"));
                model->setHeaderData(1, Qt::Horizontal, tr("nom"));
                model->setHeaderData(2, Qt::Horizontal, tr("prenom"));
                model->setHeaderData(3, Qt::Horizontal, tr("coupon 10%"));


                        ui->table_attribution_coupon->setModel(model);
                        if (model->lastError().isValid())
                            qDebug() << model->lastError();
                        ui->table_attribution_coupon->show();}

                else
                { popup.setPopupText(" ECHEC !  ");
                    popup.show();}
}

void MainWindow::on_trier_coupon_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
            model->setQuery("SELECT cin,nom,prenom,cp_10 FROM CLIENT ORDER BY cp_10");
            model->setHeaderData(0, Qt::Horizontal, tr("cin"));
            model->setHeaderData(1, Qt::Horizontal, tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, tr("coupon 10%"));




            ui->table_attribution_coupon->setModel(model);
            if (model->lastError().isValid())
                qDebug() << model->lastError();
            ui->table_attribution_coupon->show();
}

void MainWindow::on_afficher_coupon_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
            model->setQuery("SELECT cin,nom,prenom,cp_10 FROM CLIENT");
            model->setHeaderData(0, Qt::Horizontal, tr("cin"));
            model->setHeaderData(1, Qt::Horizontal, tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, tr("coupon 10%"));




            ui->table_attribution_coupon->setModel(model);
            if (model->lastError().isValid())
                qDebug() << model->lastError();
            ui->table_attribution_coupon->show();
}

void MainWindow::on_table_attribution_points_clicked(const QModelIndex &index)
{
    client Pr,Cl;
    QString valeur=ui->table_attribution_points->model()->data(index).toString();
       QSqlQuery q ;

   q.prepare("SELECT * FROM CLIENT WHERE CIN='"+valeur+"' ");
   if (q.exec())
   {
       while(q.next())
       {

              Cl.setCIN_client(q.value(0).toInt());
                Cl.setPoints_client(q.value(10).toInt());
       }
   }
}

void MainWindow::on_attribuer_points_clicked()
{
    client Pr,Cl;
    int nv_nb_coupon=Cl.getPoints_client()+ ui->spinBox_2->text().toInt();
    QSqlQuery qry ;

       qry.prepare("UPDATE CLIENT SET points =?  WHERE CIN= ?");
       qry.bindValue(0,nv_nb_coupon);
        qry.bindValue(1,QString::number(Cl.getCIN_client()));


                if(qry.exec())
                {
                    popup.setPopupText(" L'attribution est reussite !  ");
                                           popup.show();
                QSqlQueryModel *model = new QSqlQueryModel;
                model->setQuery("SELECT cin,nom,prenom,points FROM CLIENT");
                model->setHeaderData(0, Qt::Horizontal, tr("cin"));
                model->setHeaderData(1, Qt::Horizontal, tr("nom"));
                model->setHeaderData(2, Qt::Horizontal, tr("prenom"));
                model->setHeaderData(3, Qt::Horizontal, tr("Points"));


                        ui->table_attribution_points->setModel(model);
                        if (model->lastError().isValid())
                            qDebug() << model->lastError();
                        ui->table_attribution_points->show();}

                else
                { popup.setPopupText(" ECHEC !  ");
                    popup.show();}
}

void MainWindow::on_trier_points_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
            model->setQuery("SELECT cin,nom,prenom,points FROM CLIENT ORDER BY points");
            model->setHeaderData(0, Qt::Horizontal, tr("cin"));
            model->setHeaderData(1, Qt::Horizontal, tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, tr("points"));




            ui->table_attribution_points->setModel(model);
            if (model->lastError().isValid())
                qDebug() << model->lastError();
            ui->table_attribution_points->show();
}

void MainWindow::on_afficher_points_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
            model->setQuery("SELECT cin,nom,prenom,points FROM CLIENT ");
            model->setHeaderData(0, Qt::Horizontal, tr("cin"));
            model->setHeaderData(1, Qt::Horizontal, tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, tr("points"));




            ui->table_attribution_points->setModel(model);
            if (model->lastError().isValid())
                qDebug() << model->lastError();
            ui->table_attribution_points->show();
}

void MainWindow::on_Ajouter_msg_clicked()
{
    fournisseur c ;
    QSqlQuery qry1,qry ;

c.setID_fournisseur(ui->cin_msg->text().toLong());
c.setMessage_fournisseur(ui->Message_client->text());
c.setdate_ajout(ui->dateEdit->date());


//long CIN_client= c.setCIN_client();
//QString Message_client= c.setMessage_client();

       qry.prepare("UPDATE fournisseur SET message = (?),DATE_AJOUT=? WHERE ID = (?)");
       qry.bindValue(0,c.getMessage_fournisseur());
       qry.bindValue(1,c.getdate_ajout());

       qry.bindValue(2,QString::number(c.getID_fournisseur()));

                if(qry.exec())
                {
                    popup.setPopupText("le fournisseur a ajouté un message !");
                    popup.show();

                }
                else
                {popup.setPopupText("ECHEC d'ajout du message !! ");
                    popup.show();
                   }

}

void MainWindow::on_afficher_msg_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT ID,nom,message,date_ajout FROM fournisseur ");
    model->setHeaderData(0, Qt::Horizontal, tr("id"));
    model->setHeaderData(1, Qt::Horizontal, tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, tr("message"));
    model->setHeaderData(3, Qt::Horizontal, tr("date d'ajout"));






            ui->Consulter_msg->setModel(model);
            if (model->lastError().isValid())
                qDebug() << model->lastError();
            ui->Consulter_msg->show();
}

void MainWindow::on_trier_msg_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel;
            model->setQuery("SELECT ID,nom,message,date_ajout FROM fournisseur ORDER BY DATE_AJOUT");
            model->setHeaderData(0, Qt::Horizontal, tr("id"));
            model->setHeaderData(1, Qt::Horizontal, tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, tr("message"));
            model->setHeaderData(3, Qt::Horizontal, tr("date d'ajout"));





            ui->Consulter_msg->setModel(model);
            if (model->lastError().isValid())
                qDebug() << model->lastError();
            ui->Consulter_msg->show();
}

void MainWindow::on_gestion_rec_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(33);
}

void MainWindow::on_sav_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(33);
}

void MainWindow::on_ajouter_rec_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(34);
}

void MainWindow::on_modifier_rec_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(35);
}

void MainWindow::on_afficher_rec_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(36);
    Reclamatio r;
    r.afficher_reclamation(ui);
}

void MainWindow::on_suprimer_rec_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(37);
}

void MainWindow::on_id_vente_textEdited(const QString &arg1)
{
    Reclamatio r;

    QSqlQuery q;
        q.prepare("select * from VENTES where ID_VENTE=:ID_Vente");
        q.bindValue(":ID_Vente",arg1);
        q.exec();
        q.next();

        //std::cout<<q.value(6).toString()<< std::endl;
        QString e="AV";


    if(e==q.value(6).toString()){
          qint8 duree=1000;
          QString titre;
          Reclamatio r;
          r.ajouter_reclamation(ui);

        QString text("reclamation ajouter!");

        notification->show();
        notification->showMessage(titre,text,QSystemTrayIcon::Critical,duree);
    }
else if(e!=q.value(6).toString()){
        qint8 duree=1000;
        QString titre;
        QString text("dsl cette services ne considere comme un sav!");


        notification->show();
        notification->showMessage(titre,text,QSystemTrayIcon::Critical,duree);
    }
}


void MainWindow::on_id_2_textEdited(const QString &arg1)
{
    QSqlQuery qry;
    qry.prepare("select * from reclamation where id=:id");
    qry.bindValue(":id",arg1);
    qry.exec();
    qry.next();
    ui->nom_rec_2->setText(qry.value(1).toString());
    ui->code_4->setText(qry.value(2).toString());
    ui->date_rec_2->setText(qry.value(3).toString());
    ui->lieu_2->setText(qry.value(4).toString());
    ui->rec_2->setText(qry.value(5).toString());

}

void MainWindow::on_modifier_ter_clicked()
{
    Reclamatio r;
    r.modifier_reclamation(ui);
}

void MainWindow::on_tri_rec_clicked()
{
    Reclamatio r;
    r.tri_reclamation(ui);
}

void MainWindow::on_supprimer_rec_id_clicked()
{
    Reclamatio r;
    r.supprimer_reclamation(ui);


}

void MainWindow::on_gestion_inter_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(38);

}

void MainWindow::on_ajouter_inter_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(39);
}

void MainWindow::on_modifier_rec_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(40);
}

void MainWindow::on_supp_inter_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(41);

}

void MainWindow::on_afficher_inter_clicked()
{
    intervention i;
    i.afficher_intervention(ui);
}

void MainWindow::on_rechecher_inter_textEdited(const QString &arg1)
{
    intervention i;
    i.rechercher(ui);
}

void MainWindow::on_tri_inter_clicked()
{
    intervention i;
    i.tri_intervention(ui);
}

void MainWindow::on_ajouetr_inter_ter_clicked()
{
    intervention i;
    i.ajouter_intervention(ui);
}

void MainWindow::on_terminer_inter_mod_clicked()
{
    intervention i;
    i.modifier_intervention(ui);
}

void MainWindow::on_ci_2_textEdited(const QString &arg1)
{
    QSqlQuery qry;
    qry.prepare("select * from intervention where CI=:CI");
    qry.bindValue(":CI",arg1);
    qry.exec();
    qry.next();
    ui->co_2->setText(qry.value(1).toString());
    ui->nom_ouv_2->setText(qry.value(2).toString());
    ui->nom_serv2->setText(qry.value(3).toString());
    ui->nom_client_3->setText(qry.value(4).toString());
    ui->date_inter_2->setDate(qry.value(5).toDate());
    ui->id_client_2->setText(qry.value(6).toString());
    ui->deg_pri_2->setText(qry.value(7).toString());
}

void MainWindow::on_supp_inter_2_clicked()
{
    intervention i;
    i.supprimer_intervention(ui);
}

void MainWindow::on_imprimer_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tableView_3->model()->rowCount();
        const int columnCount = ui->tableView_3->model()->columnCount();

        out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("Ventes")
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
            "<table border=1 cellspacing=0 cellpadding=2>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tableView_3->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tableView_3->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tableView_3->isColumnHidden(column)) {
                    QString data = ui->tableView_3->model()->data(ui->tableView_3->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
            "</body>\n"
            "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

        QPrinter printer;

        QPrintDialog *dialog = new QPrintDialog(&printer, this);
        if (dialog->exec() == QDialog::Accepted) {
            document->print(&printer);
        }

       delete document;

}

void MainWindow::on_afficher_g_clicked()
{
    garantie g;

    QString titre;

     g.afficher(ui);
}



void MainWindow::on_rechercher_g_textEdited(const QString &arg1)
{
    garantie g;
    g.rechercher(ui);
}

void MainWindow::on_asc_clicked()
{
    garantie g;
    g.tri(ui);
}

void MainWindow::on_desc_clicked()
{
    garantie g;
    g.tri_2(ui);
}

void MainWindow::on_tablegarantie_clicked(const QModelIndex &index)
{
    garantie g;
        qint8 duree=1000;
       QDate m=QDate::currentDate();


        if(ui->tablegarantie->selectionModel()->hasSelection())
        {
            QString titre(ui->tablegarantie->model()->data(ui->tablegarantie->model()->index(ui->tablegarantie->selectionModel()->currentIndex().row(),1)).toString());
            ui->Titre_garantie->setText(titre);
            if((ui->tablegarantie->model()->data(ui->tablegarantie->model()->index(ui->tablegarantie->selectionModel()->currentIndex().row(),2)).toDate().addDays(-7))<=m && (ui->tablegarantie->model()->data(ui->tablegarantie->model()->index(ui->tablegarantie->selectionModel()->currentIndex().row(),2)).toDate()>m))
            {
                QString text("Cette garantie sera bientôt expirée.");
                ui->Etat_garantie->setText("Bientôt expirée.");


                notification->show();
                notification->showMessage(titre,text,QSystemTrayIcon::Information,duree);
            }
            if((ui->tablegarantie->model()->data(ui->tablegarantie->model()->index(ui->tablegarantie->selectionModel()->currentIndex().row(),2)).toDate())<=m)
            {
                QString text("Cette garantie est expirée.");
                ui->Etat_garantie->setText("Expirée.");
                notification->show();
                notification->showMessage(titre,text,QSystemTrayIcon::Critical,duree);
            }
            if((ui->tablegarantie->model()->data(ui->tablegarantie->model()->index(ui->tablegarantie->selectionModel()->currentIndex().row(),2)).toDate()).addDays(-7)>=m &&(ui->tablegarantie->model()->data(ui->tablegarantie->model()->index(ui->tablegarantie->selectionModel()->currentIndex().row(),2)).toDate())>m)
            {
                 ui->Etat_garantie->setText("valable.");
            }


        }


}

void MainWindow::on_gestion_gar_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(42);

}

void MainWindow::on_mail_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(43);
}

void MainWindow::on_envoyer_clicked()
{
    smtp *s = new smtp();
    //s->sendMail();
    s->setDestMail(ui->destMail->text());
    s->setDestNom(ui->destNom->text());
    s->setMailTitre(ui->mailTitre->text());
    s->setContenue(ui->contenue->toPlainText());
    s->sendMail();
}

void MainWindow::on_stat_clicked()
{ ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_2->setCurrentIndex(44);

}
  void MainWindow::makeplot2()
  {
// prepare data:
QVector<double> x3(3), y3(20);
for (int i=0; i<x3.size(); ++i)
{
  x3[i] = i+1;

}

// create and configure plottables:
//    QCPGraph *graph1 = ui->customPlot->addGraph();
//    graph1->setData(x1, y1);
//    graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
//    graph1->setPen(QPen(QColor(120, 120, 120), 2));

//    QCPGraph *graph2 = ui->customPlot->addGraph();
//    graph2->setData(x2, y2);
//    graph2->setPen(Qt::NoPen);
//    graph2->setBrush(QColor(200, 200, 200, 20));
//    graph2->setChannelFillGraph(graph1);
intervention i;
QCPBars *bars1 = new QCPBars(ui->customPlot2->xAxis, ui->customPlot2->yAxis);
bars1->setWidth(2/(double)x3.size());
bars1->setData(x3, i.statstique());
bars1->setPen(Qt::NoPen);
bars1->setBrush(QColor(200, 40, 60, 170));

QVector<double> ticks;
QVector<QString> labels;
ticks << 1 << 2 << 3  ;
labels << "jardinage" << "bany_sitter" << "chaffeur";
QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
 textTicker->addTicks(ticks, labels);
ui->customPlot2->xAxis->setTicker(textTicker);
ui->customPlot2->xAxis->setTickLabelRotation(60);
ui->customPlot2->xAxis->setSubTicks(false);
ui->customPlot2->xAxis->setTickLength(0, 4);
ui->customPlot2->xAxis->setRange(0, 8);
ui->customPlot2->xAxis->setBasePen(QPen(Qt::white));
ui->customPlot2->xAxis->setTickPen(QPen(Qt::white));
ui->customPlot2->xAxis->grid()->setVisible(true);
ui->customPlot2->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
ui->customPlot2->xAxis->setTickLabelColor(Qt::white);
ui->customPlot2->xAxis->setLabelColor(Qt::white);
//set yaxis
ui->customPlot2->yAxis->setRange(0,4);
ui->customPlot2->yAxis->setPadding(5); // a bit more space to the left border
ui->customPlot2->yAxis->setLabel("Nombre d'interventions");
 ui->customPlot2->yAxis->setSubTicks(false);
ui->customPlot2->yAxis->setBasePen(QPen(Qt::white));
ui->customPlot2->yAxis->setTickPen(QPen(Qt::white));
ui->customPlot2->yAxis->setSubTickPen(QPen(Qt::white));
ui->customPlot2->yAxis->grid()->setSubGridVisible(true);
ui->customPlot2->yAxis->setTickLabelColor(Qt::white);
ui->customPlot2->yAxis->setLabelColor(Qt::white);
ui->customPlot2->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
ui->customPlot2->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));


//    QCPBars *bars2 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
//    bars2->setWidth(9/(double)x4.size());
//    bars2->setData(x4, y4);
//    bars2->setPen(Qt::NoPen);
//    bars2->setBrush(QColor(10, 100, 50, 70));
//    bars2->moveAbove(bars1);

// move bars above graphs and grid below bars:
ui->customPlot2->addLayer("abovemain", ui->customPlot2->layer("main"), QCustomPlot::limAbove);
ui->customPlot2->addLayer("belowmain", ui->customPlot2->layer("main"), QCustomPlot::limBelow);
ui->customPlot2->xAxis->grid()->setLayer("belowmain");
ui->customPlot2->yAxis->grid()->setLayer("belowmain");

// set some pens, brushes and backgrounds:
ui->customPlot2->xAxis->setBasePen(QPen(Qt::white, 1));
ui->customPlot2->yAxis->setBasePen(QPen(Qt::white, 1));
ui->customPlot2->xAxis->setTickPen(QPen(Qt::transparent, 1));
ui->customPlot2->yAxis->setTickPen(QPen(Qt::white, 1));
ui->customPlot2->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
ui->customPlot2->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
ui->customPlot2->xAxis->setTickLabelColor(Qt::white);
ui->customPlot2->yAxis->setTickLabelColor(Qt::white);
ui->customPlot2->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
ui->customPlot2->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
ui->customPlot2->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
ui->customPlot2->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
// ui->customPlot->xAxis->grid()->setSubGridVisible(true);
// ui->customPlot->yAxis->grid()->setSubGridVisible(true);
ui->customPlot2->xAxis->grid()->setZeroLinePen(Qt::NoPen);
ui->customPlot2->yAxis->grid()->setZeroLinePen(Qt::NoPen);
ui->customPlot2->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
ui->customPlot2->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
QLinearGradient plotGradient;
plotGradient.setStart(0, 0);
plotGradient.setFinalStop(0, 350);
plotGradient.setColorAt(0, QColor(10, 50, 80));
plotGradient.setColorAt(1, QColor(10, 20, 50));
ui->customPlot2->setBackground(plotGradient);
QLinearGradient axisRectGradient;
axisRectGradient.setStart(0, 0);
axisRectGradient.setFinalStop(0, 350);
axisRectGradient.setColorAt(0, QColor(10, 50, 80));
axisRectGradient.setColorAt(1, QColor(0, 0, 30));
ui->customPlot2->axisRect()->setBackground(axisRectGradient);

ui->customPlot2->rescaleAxes();
ui->customPlot2->xAxis->setRange(0, 4);
ui->customPlot2->replot();
}

void MainWindow::on_rechercher_rec_textEdited(const QString &arg1)
{
    Reclamatio r;
    r.rechercher_reclamation(ui);
}

void MainWindow::on_ajouterCompte_clicked()
{
   ui->stackedWidget_2->setCurrentIndex(46);
   page=46;
   ui->precedent->setVisible(true);
   ui->precedent->setEnabled(true);
}

void MainWindow::on_enregistrerCompte_clicked()
{
    Login l(ui->codeCompte->text(),ui->typeCompte->currentText(),ui->loginCompte->text(),ui->mpCompte->text());
    l.ajouter();
    ui->tableCompte->setModel(l.afficher());
    ui->stackedWidget_2->setCurrentIndex(47);
    page=47;


}

void MainWindow::on_supprimerCompte_clicked()
{
    Login l;
    if(ui->tableCompte->selectionModel()->hasSelection())
    {
        l.set_code(ui->tableCompte->model()->data(ui->tableCompte->model()->index(ui->tableCompte->selectionModel()->currentIndex().row(),0)).toString());

    }

    l.supprimer();
    ui->tableCompte->setModel(l.afficher());
}

void MainWindow::on_modifierCompte_clicked()
{
    Login l;

    if(ui->tableCompte->selectionModel()->hasSelection())
    {
        ui->stackedWidget_2->setCurrentIndex(48);
        page=48;

    }
    ui->codeCompte_2->setText(ui->tableCompte->model()->data(ui->tableCompte->model()->index(ui->tableCompte->selectionModel()->currentIndex().row(),0)).toString());


    ui->loginCompte_2->setText(ui->tableCompte->model()->data(ui->tableCompte->model()->index(ui->tableCompte->selectionModel()->currentIndex().row(),1)).toString());

    ui->mpCompte_2->setText(ui->tableCompte->model()->data(ui->tableCompte->model()->index(ui->tableCompte->selectionModel()->currentIndex().row(),2)).toString());
    //ui->typeCompte_2->setText(ui->tableCompte->model()->data(ui->tableCompte->model()->index(ui->tableCompte->selectionModel()->currentIndex().row(),3)).toString());

     //ui->tableCompte->setModel(l.afficher());
}

void MainWindow::on_enregistrerCompte_2_clicked()
{
    Login l(ui->codeCompte_2->text(),ui->typeCompte_2->currentText(),ui->loginCompte_2->text(),ui->mpCompte_2->text());
    l.modifier();
    ui->stackedWidget_2->setCurrentIndex(47);
    page=47;

    ui->tableCompte->setModel(l.afficher());

}

void MainWindow::on_recupererHO_clicked()
{
    QSqlQuery q;
    Ouvrier o;
    if(ui->TableHO->selectionModel()->hasSelection())
    {
        o.set_CIN(ui->TableHO->model()->data(ui->TableHO->model()->index(ui->TableHO->selectionModel()->currentIndex().row(),0)).toString());
        o.set_Nom(ui->TableHO->model()->data(ui->TableHO->model()->index(ui->TableHO->selectionModel()->currentIndex().row(),1)).toString());
        o.set_Prenom(ui->TableHO->model()->data(ui->TableHO->model()->index(ui->TableHO->selectionModel()->currentIndex().row(),2)).toString());
        o.set_Age(ui->TableHO->model()->data(ui->TableHO->model()->index(ui->TableHO->selectionModel()->currentIndex().row(),3)).toInt());
        o.set_Telephone(ui->TableHO->model()->data(ui->TableHO->model()->index(ui->TableHO->selectionModel()->currentIndex().row(),4)).toInt());
        o.set_Adresse(ui->TableHO->model()->data(ui->TableHO->model()->index(ui->TableHO->selectionModel()->currentIndex().row(),5)).toString());
        o.set_Sexe(ui->TableHO->model()->data(ui->TableHO->model()->index(ui->TableHO->selectionModel()->currentIndex().row(),6)).toString());
        o.set_Specialite(ui->TableHO->model()->data(ui->TableHO->model()->index(ui->TableHO->selectionModel()->currentIndex().row(),7)).toString());
        o.set_Email(ui->TableHO->model()->data(ui->TableHO->model()->index(ui->TableHO->selectionModel()->currentIndex().row(),8)).toString());

          o.supprimerHistorique();
          o.afficherHistorique(ui);
          o.ajouter();
        }
}

void MainWindow::on_recupererHM_clicked()
{
    QSqlQuery q;
    Materiaux m;
    if(ui->TableHM->selectionModel()->hasSelection())
    {
        m.set_Code(ui->TableHM->model()->data(ui->TableHM->model()->index(ui->TableHM->selectionModel()->currentIndex().row(),0)).toInt());
        m.set_Nom(ui->TableHM->model()->data(ui->TableHM->model()->index(ui->TableHM->selectionModel()->currentIndex().row(),1)).toString());
        m.set_Qte(ui->TableHM->model()->data(ui->TableHM->model()->index(ui->TableHM->selectionModel()->currentIndex().row(),2)).toInt());

          m.supprimerHistorique();
          m.afficherHistorique(ui);
          m.ajouter();
        }
}
//************************************************MODULE VENTES************************************************************
void MainWindow::on_RafraichirVentes_clicked()
{
    Vente a;
    a.searchInTable(ui,ui->Search_bar_ventes->text());
    a.FillListeVentesExp(ui);
}

void MainWindow::on_Search_bar_ventes_textEdited(const QString &arg1)
{
    Vente a;
    a.searchInTable(ui,arg1);
}

void MainWindow::on_tableView_Ventes_activated(const QModelIndex &index)
{
    QModelIndexList selection = ui->tableView_Ventes->selectionModel()->selectedRows();

    // Multiple rows can be selected

    if(selection.count()>1)
    {
        return;
    }

        QModelIndex ind = selection.at(0);
        int myRow = ind.row();
    QString state = (ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(myRow,6)).toString());
    QString title  = (ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(myRow,2)).toString());
    ui->titre_de_la_vente->setText(title);
    ui->etat_vente->setText(state);
    qDebug()<<state;
    if(state=="Etude de faisabilité")
    {
        ui->progressBar->setValue(13);
    }
    if(state=="Négociation")
    {
        ui->progressBar->setValue(38);
    }

    if(state=="Execution")
    {
        ui->progressBar->setValue(63);
    }

    if(state=="AV")
    {
        ui->progressBar->setValue(84);
    }


}



//----------------------------------------AJOUT-------------------------------------------

void MainWindow::on_AjouterVente_clicked()
{
    Vente a;
    ui->stackedWidget_2->setCurrentIndex(50);
    a.ShowTableService(ui);
    ui->V_lineEdit_Service->setReadOnly(true);
    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Base,Qt::gray);
    palette->setColor(QPalette::Text,Qt::darkGray);
    ui->V_lineEdit_Service->setPalette(*palette);
}

void MainWindow::on_V_pushButton_Confirmer_clicked()
{
    Vente a;
    qDebug()<<"Error?";
    if(a.ConfirmerAjout(ui,this))
     notification->showMessage("Info","Vente ajoutée!",QSystemTrayIcon::Information,15000);
    else
    notification->showMessage("Info","la vente n'a pas pu être ajoutée.",QSystemTrayIcon::Information,15000);

    ui->stackedWidget_2->setCurrentIndex(49);
}


void MainWindow::on_V_pushButton_Annuler_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(49);
}

//----------------------------------------FIN AJOUT-------------------------------------------


//----------------------------------------SUPPRESSION-------------------------------------------

void MainWindow::on_SupprimerVente_clicked()
{
    Vente a;
    if(a.supprimerVente(ui,this))
        notification->showMessage("Info","Suppression réussie!",QSystemTrayIcon::Information,15000);
    else
        notification->showMessage("Info","La modification n'a pas pu être effectuée.",QSystemTrayIcon::Information,15000);
}
//----------------------------------------FIN SUPPRESSION-------------------------------------------


//----------------------------------------MODIFIER-------------------------------------------

void MainWindow::on_ModifierVente_clicked()
{
    Vente a;
    a.modifierVente(ui);
    a.ShowTableService(ui);
    ui->V_lineEdit_Service_2->setReadOnly(true);
    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Base,Qt::gray);
    palette->setColor(QPalette::Text,Qt::darkGray);
    ui->V_lineEdit_Service_2->setPalette(*palette);
}

void MainWindow::on_V_pushButton_Confirmer_2_clicked()
{
    Vente a;
    if(a.ConfirmerModifierVente(ui,this))
        notification->showMessage("Info","Modification réussie!",QSystemTrayIcon::Information,15000);
    else
        notification->showMessage("Info","La modification n'a pas pu être effectuée!",QSystemTrayIcon::Information,15000);
    ui->stackedWidget_2->setCurrentIndex(49);
}

void MainWindow::on_V_pushButton_Annuler_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(49);

}
//----------------------------------------FIN MODIFIER-------------------------------------------

//----------------------------------------STATISTIQUES-------------------------------------------

void MainWindow::makeplot_ventes()
{
    Vente a;
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->V_CustomPlot->setBackground(QBrush(gradient));

    // create empty bar chart objects:
    QCPBars *regen = new QCPBars(ui->V_CustomPlot->xAxis, ui->V_CustomPlot->yAxis);
    QCPBars *nuclear = new QCPBars(ui->V_CustomPlot->xAxis, ui->V_CustomPlot->yAxis);
    QCPBars *fossil = new QCPBars(ui->V_CustomPlot->xAxis, ui->V_CustomPlot->yAxis);
    regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders
    nuclear->setAntialiased(false);
    fossil->setAntialiased(false);
    regen->setStackingGap(1);
    nuclear->setStackingGap(1);
    fossil->setStackingGap(1);
    // set names and colors:
    fossil->setName("Nombre de ventes");
    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(111, 9, 176));
    /*nuclear->setName("Nuclear");
    nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    nuclear->setBrush(QColor(250, 170, 20));
    regen->setName("Nombre de ventes");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));*/
    // stack bars on top of each other:
    nuclear->moveAbove(fossil);
    regen->moveAbove(nuclear);

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    labels << "Ce mois" << "Cette année" ;//<< "Germany" << "France" << "UK" << "Italy" << "Canada";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->V_CustomPlot->xAxis->setTicker(textTicker);
    ui->V_CustomPlot->xAxis->setTickLabelRotation(60);
    ui->V_CustomPlot->xAxis->setSubTicks(false);
    ui->V_CustomPlot->xAxis->setTickLength(0, 4);
    ui->V_CustomPlot->xAxis->setRange(0, 8);
    ui->V_CustomPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->V_CustomPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->V_CustomPlot->xAxis->grid()->setVisible(true);
    ui->V_CustomPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->V_CustomPlot->xAxis->setTickLabelColor(Qt::white);
    ui->V_CustomPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->V_CustomPlot->yAxis->setRange(0, 12.1);
    ui->V_CustomPlot->yAxis->setPadding(5); // a bit more space to the left border
    ui->V_CustomPlot->yAxis->setLabel("Ventes lancées par période temporelle");
    ui->V_CustomPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->V_CustomPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->V_CustomPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->V_CustomPlot->yAxis->grid()->setSubGridVisible(true);
    ui->V_CustomPlot->yAxis->setTickLabelColor(Qt::white);
    ui->V_CustomPlot->yAxis->setLabelColor(Qt::white);
    ui->V_CustomPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->V_CustomPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
   // QVector<double> fossilData, nuclearData, regenData;
    QVector <double> data=a.UI_Stats_VL(ui);
   /* fossilData  << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;
    nuclearData << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8 << 0.09*5.2 << 0.00*4.2 << 0.07*11.2;
    regenData   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;
    fossil->setData(ticks, fossilData);
    nuclear->setData(ticks, nuclearData);
    regen->setData(ticks, regenData);*/
     fossil->setData(ticks, data);
    // setup legend:
    ui->V_CustomPlot->legend->setVisible(true);
    ui->V_CustomPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->V_CustomPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->V_CustomPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->V_CustomPlot->legend->setFont(legendFont);
    ui->V_CustomPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}




void MainWindow::on_Statistiques_Ventes_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(52);
    makeplot_ventes();
}

void MainWindow::on_V_pushButton_RetourStat_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(49);

}
//----------------------------------------FIN STATISTIQUES-------------------------------------------


//----------------------------------------IMPRESSION-------------------------------------------

void MainWindow::on_ImprimerVente_clicked()
{


    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_Ventes->model()->rowCount();
    const int columnCount = ui->tableView_Ventes->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("Ventes")
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableView_Ventes->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_Ventes->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_Ventes->isColumnHidden(column)) {
                QString data = ui->tableView_Ventes->model()->data(ui->tableView_Ventes->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    if (dialog->exec() == QDialog::Accepted) {
        document->print(&printer);
    }

   delete document;
}
//----------------------------------------FIN IMPRESSION-------------------------------------------

//-------------------------------------------NAVIGATION-----------------------------------------------


void MainWindow::on_vente_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->stackedWidget_2->setCurrentIndex(49);

}

void MainWindow::on_gestionOuvriers_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(49);

}

void MainWindow::on_historique_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(53);
}

void MainWindow::on_planification_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(55);
}

//----------------------------------------FIN NAVIGATION-------------------------------------------

//***************************************PISTES ET OPP********************************************

//----------------------------------------AJOUT-------------------------------------------



void MainWindow::on_PO_pushButton_ajouter_clicked()
{
        ui->stackedWidget_2->setCurrentIndex(54);
}

void MainWindow::on_PO_Ajout_Confirmer_clicked()
{
    PisteOpp a;

    if(a.ConfirmerAjout(ui,this))
    {
    notification->showMessage("Info","Ajout réussi!",QSystemTrayIcon::Information,15000);
    a.searchInTablePistes(ui,ui->PO_lineEdit_recherche->text());
    a.searchInTableOpp(ui,ui->PO_lineEdit_rechercheOpp->text());
    }

    else
    notification->showMessage("Info","Ajout non abouti.",QSystemTrayIcon::Information,15000);
    ui->stackedWidget_2->setCurrentIndex(53);
}


//----------------------------------------FIN AJOUT-------------------------------------------

//----------------------------------------MODIFICATION-------------------------------------------


void MainWindow::on_PO_pushButton_modifier_clicked()
{
    PisteOpp a;
    a.modifierPiste(ui);
}

void MainWindow::on_PO_pushButton_modifier_Opp_clicked()
{
    PisteOpp a;
    a.modifierOpp(ui);
}

void MainWindow::on_PO_Ajout_Confirmer_2_clicked()
{
    PisteOpp a;
    a.ConfirmerModifier(ui,this);
    a.searchInTablePistes(ui,ui->PO_lineEdit_recherche->text());
    a.searchInTableOpp(ui,ui->PO_lineEdit_rechercheOpp->text());
    ui->stackedWidget_2->setCurrentIndex(53);

}

//----------------------------------------FIN MODIF-------------------------------------------

//----------------------------------------SUPPRESSION-------------------------------------------


void MainWindow::on_PO_pushButton_supprimer_clicked()
{
    PisteOpp h;
    h.supprimerPiste(ui);
}

void MainWindow::on_PO_pushButton_supprimer_Opp_clicked()
{
    PisteOpp h;
    h.supprimerOpp(ui);
}

//----------------------------------------FIN SUPPRESSION-------------------------------------------


//----------------------------------------RAFRAICHIR-------------------------------------------

void MainWindow::on_PO_Rafraichir_clicked()
{
    PisteOpp a;
    a.searchInTablePistes(ui,ui->PO_lineEdit_recherche->text());
    a.searchInTableOpp(ui,ui->PO_lineEdit_rechercheOpp->text());

}
//----------------------------------------FIN RAFRAICHIR-------------------------------------------

//----------------------------------------RECHERCHE-------------------------------------------


void MainWindow::on_PO_lineEdit_recherche_textEdited(const QString &arg1)
{
    PisteOpp h;
    h.searchInTablePistes(ui,arg1);
}

void MainWindow::on_PO_lineEdit_rechercheOpp_textEdited(const QString &arg1)
{
    PisteOpp h;
    h.searchInTableOpp(ui,arg1);
}
//----------------------------------------FIN RECHERCHE-------------------------------------------
//***************************************SERVICES********************************************

//----------------------------------------RECHERCHE-------------------------------------------

void MainWindow::on_S_lineEdit_Recherche_textEdited(const QString &arg1)
{
    Service a;
    a.searchInTable(ui,arg1);
}

//----------------------------------------FIN RECHERCHE-------------------------------------------

//----------------------------------------RAFRAICHIR-------------------------------------------

void MainWindow::on_S_pushButton_Rafraichir_clicked()
{
    Service a;
    a.searchInTable(ui,ui->S_lineEdit_Recherche->text());
}
//----------------------------------------FIN RAFRAICHIR-------------------------------------------
//----------------------------------------AJOUT-------------------------------------------


void MainWindow::on_S_pushButton_AjouterService_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(56);
}


void MainWindow::on_S_pushButton_Confirmer_clicked()
{
    Service a;
    if(a.ConfirmerAjout(ui,this))
    {
        notification->showMessage("Info","Ajout réussi!",QSystemTrayIcon::Information,15000);
        a.searchInTable(ui,ui->S_lineEdit_Recherche->text());
        ui->stackedWidget_2->setCurrentIndex(55);

    }
    else
    {
        notification->showMessage("Info","Ajout non abouti.",QSystemTrayIcon::Information,15000);

    }

}


void MainWindow::on_S_pushButton_Annuler_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(55);

}
//----------------------------------------FIN AJOUT-------------------------------------------

//----------------------------------------SUPPRESSION-------------------------------------------

void MainWindow::on_S_pushButton_SupprimerService_clicked()
{
    Service a;
    if(a.supprimerService(ui))
        notification->showMessage("Info","Suppression réussie!",QSystemTrayIcon::Information,15000);
    else
        notification->showMessage("Info","Suppression non aboutie.",QSystemTrayIcon::Information,15000);
}
//----------------------------------------FIN SUPPRESSION-------------------------------------------

//----------------------------------------MODIFICATION-------------------------------------------

void MainWindow::on_S_pushButton_ModifierService_clicked()
{
    Service a;
    a.modifierService(ui);
}

void MainWindow::on_S_pushButton_Confirmer_2_clicked()
{
    Service a;
    if(a.ConfirmerModifier(ui,this))
    {
        notification->showMessage("Info","Modification réussie!",QSystemTrayIcon::Information,15000);
        ui->stackedWidget_2->setCurrentIndex(55);
    }
    else
        notification->showMessage("Info","Modification non aboutie.",QSystemTrayIcon::Information,15000);
}

void MainWindow::on_S_pushButton_Annuler_2_clicked()
{
        ui->stackedWidget_2->setCurrentIndex(55);
}

//----------------------------------------FIN MODIFICATION-------------------------------------------

void MainWindow::on_calendarWidget_2_clicked(const QDate &date)
{
     ui->dateTimeEdit_2->setDate(ui->calendarWidget_2->selectedDate());
}

void MainWindow::on_trierQte_clicked()
{
    Materiaux m;
    ui->tableMateriaux->setModel(m.triQte());
}

void MainWindow::on_trierNom_clicked()
{
    Ouvrier o;
    ui->tableOuvrier->setModel(o.triNom());
}

void MainWindow::on_trierSpecialite_clicked()
{
    Ouvrier o;
    ui->tableOuvrier->setModel(o.triSpecialite());
}

void MainWindow::on_recupererHR_clicked()
{
    QSqlQuery q;
   Rendezvous r;

    if(ui->TableHR->selectionModel()->hasSelection())
    {
         r.set_crv(ui->tableRV->model()->data(ui->tableRV->model()->index(ui->tableRV->selectionModel()->currentIndex().row(),0)).toInt());
        r.set_cin(ui->TableHR->model()->data(ui->TableHR->model()->index(ui->TableHR->selectionModel()->currentIndex().row(),2)).toInt());
       // r.set_date(QDateTime::toString("dd'-'MM'-'yyyy' 'hh:mm",ui->TableHR->model()->data(ui->TableHR->model()->index(ui->TableHR->selectionModel()->currentIndex().row(),1)).toDateTime()));
        r.set_date(ui->TableHR->model()->data(ui->TableHR->model()->index(ui->TableHR->selectionModel()->currentIndex().row(),1)).toDateTime());
       QString a=r.get_date().toString("dd'-'MM'-'yyyy' 'hh:mm");


          r.supprimerHistorique();
          r.afficherHistorique(ui);
          r.ajouter(ui);
        }
}

void MainWindow::on_analyse_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_ajoutercompagne_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(60);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(60);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(62);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(61);
}

void MainWindow::on_affichercompagnes_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(61);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(63);
}

void MainWindow::on_meilleur_service_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(64);
}

void MainWindow::on_c_fidele_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(65);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(66);
}
void makePlot();
void MainWindow::on_ajouter_2_clicked()
{

    QString a;
        if (ui->autorisation->checkState()==Qt::Checked)
        {a="autorisée";}
        else{a="non autorisée";}
        Compagne c(ui->id->text().toInt(),ui->nomcompagne->text(),ui->type->currentText(),a,
    ui->duree->text(),ui->priorite->currentText(),ui->description->text(),ui->cible->currentText(),ui->budget->text().toInt());
    if (c.verifier())
         {
        if( c.ajoutercompagne())
           QMessageBox::information(this,"Ajouter compagne","Compagne ajoutée");}
    else{QMessageBox::information(this,"Ajouter compagne","Veuillez remplir les champs vides");}
}

void MainWindow::on_mettreajour_clicked()
{
    QString a;
        if (ui->autorisation->checkState()==Qt::Checked)
        {a="autorisée";}
        else{a="non autorisée";}
        Compagne c(ui->idsupprimer->text().toInt(),ui->nomcompagne->text(),ui->type->currentText(),a,
         ui->duree->text(),ui->priorite->currentText(),ui->description->text(),ui->cible->currentText(),ui->budget->text().toInt());
    c.modifiercompagne();
     QMessageBox::information(this,"Modifier compagne","Compagne modifiée");
}

void MainWindow::on_affichercompagnes_2_clicked()
{ ui->stackedWidget_2->setCurrentIndex(61);

}

void MainWindow::on_annuler_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_supprimercompagne_clicked()
{
    Compagne c;
    c.supprimercompagne(ui->idsupprimer->text().toInt());
}

void MainWindow::on_modifiercompagne_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(60);
}

void MainWindow::on_imprimer_2_clicked()
{
    this->printer= new QPrinter();
    QPrintDialog * printer_dialog =new QPrintDialog(printer);
    if (printer_dialog->exec() == QDialog::Accepted) {
        QPainter *painter = new QPainter(printer);
        ui->tableView->render(painter);
}
}

void MainWindow::on_exporter_clicked()
{
    QTableView *v = new QTableView;

            v->setModel(ui->tableView->model());


            QPrinter printer(QPrinter::PrinterResolution);

                         printer.setOutputFormat(QPrinter::PdfFormat);

                         printer.setPaperSize(QPrinter::A4);

                        // printer.setOrientation(QPrinter::Landscape);

                         printer.setOutputFileName("L:\\file.pdf");


                         QTextDocument doc;



                         QString text("<html><body><h1><center><font color=green>LA LISTE DES RECLAMATIONS</font></h1>");

                         text.append("<br><center><table  border='1' cellspacing='5'><thead>");

                         text.append("<tr>");

                         //for (int i = 0; i <  ui->tableWidget->columnCount(); i++) {

                      //       text.append("<th>").append( ui->tableView->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString()).append("</th>");

                      //   }


                         text.append("<th>ID RECLAMATION</th><th>DESCRIPTION</th><th>ID CLIENT</th><th>TYPE</th><th>REGION</th><th>DATE</th><th>NOM</th><th>PRENOM</th>");

                         text.append("</tr></thead>");

                         text.append("<tbody>");

                         for (int i = 0; i <  ui->tableView->model()->rowCount(); i++) {

                             text.append("<tr>");

                             for (int j = 0; j < 8; j++) {

                                 //QTableWidgetItem *item =  ui->tableView->model()->item(i, j);

                                 //if (!item || item->text().isEmpty()) {

                                  //    ui->tableView->model()->setItem(i, j, new QTabletableViewItem("0"));

                                 //}

                                 text.append("<td>").append( ui->tableView->model()->data(ui->tableView->model()->index(i,j)).toString()).append("</td>");


                             }

                                            text.append("</tr>");

                                        }

                                        text.append("</tbody></table>");

                                        doc.setHtml(text);

                                        doc.setPageSize(printer.pageRect().size());

                                        doc.print(&printer);

}

void MainWindow::on_affichercompagne_clicked()
{
    Compagne c;
        ui->tableView_4->setModel(c.affichercompagne());
}

void MainWindow::on_rechercher_clicked()
{
    Compagne c ;
        c.recherchercompagne(ui->champrecherche->text(),ui->tableView2);
}






void MainWindow::on_sendmail_clicked()
{
    Smtp2 *s=new Smtp2("ines.akez@esprit.tn","118EEWGW","smtp.gmail.com",465);
    s->sendMail("ines.akez@esprit.tn","ines.akez@esprit.tn","Félicitation!","House Care vous remercie de votre fidélité et vous offre des coupons gratuits! ");

}

void MainWindow::on_pushButton_8_clicked()
{ QSqlQueryModel *m= new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("select noms,count(prenomc) nb_service from CLIENT_SERVICE group by noms order by count(prenomc) desc");
    qry.exec();
    m->setQuery(qry);
    ui->MaxService->setModel(m);
    return ;
}



void MainWindow::on_maxtab_clicked(const QModelIndex &index)
{QString val=ui->maxtab->model()->data(index).toString();
    QSqlQueryModel *m= new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("select * from client_service where prenomc= '"+val+"'");
    qry.exec();
    m->setQuery(qry);
    ui->tableDetail->setModel(m);
    return ;

}
