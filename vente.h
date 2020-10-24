#ifndef VENTE_H
#define VENTE_H

#include "mainwindow.h"

#include <QDialog>
#include <QLineEdit>
#include <iostream>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDate>
#include <QString>
#include <QMessageBox>
#include <QSqlQueryModel>

class Vente
{



public:
    Vente();
    Vente(int ID_vente,int ID_contact,QString titre,QDate date_debut,QDate date_fin,QString service,QString etat,QString type_paiement,int tarif_pre,int tarif_fin,int pourcent_paye,QString cp10,QString cp20, QString options,QString notes,QDate date_fgarantie);

    void setDate_debut(QDate Date_debut) { this->date_debut = Date_debut; }
    QDate getDate_debut() { return this->date_debut; }

    void setTitre(QString titre) { this->titre = titre; }
    QString getTitre() { return this->titre; }

    void setService(QString service) { this->service = service; }
    QString getService() { return this->service; }

    void setEtat(QString etat) { this->etat = etat; }
    QString getEtat() { return this->etat; }

    void setNotes(QString notes) { this->notes = notes; }
    QString getNotes() { return this->notes; }

    void setType_paiement(QString type_paiement) { this->type_paiement = type_paiement; }
    QString getType_paiement() { return this->type_paiement; }

    void setOptions(QString options) { this->options = options; }
    QString getOptions() { return this->options; }

    void setTarif_pre(double tarif_pre) { this->tarif_pre = tarif_pre; }
    int getTarif_pre() { return this->tarif_pre; }

    void setPourcent_paye(double pourcent_paye) { this->pourcent_paye = pourcent_paye; }
    int getPourcent_paye() { return this->pourcent_paye; }

    void setID_vente(int ID_vente) { this->ID_vente = ID_vente; }
    int getID_vente() { return this->ID_vente; }

    void setID_contact(int ID_contact) { this->ID_contact = ID_contact; }
    int getID_contact() { return this->ID_contact; }



    void FillListeVentesExp(Ui::MainWindow* ui);

    void ShowTableService(Ui::MainWindow * ui);
    bool ConfirmerAjout(Ui::MainWindow * ui, MainWindow *parent);
    bool addToTable();
    bool supprimerVente(Ui::MainWindow *ui,MainWindow* parent);
    bool deleteFromTable(QString c, MainWindow *parent);
    bool modifierVente(Ui::MainWindow* ui);
    bool ConfirmerModifierVente(Ui::MainWindow* ui, MainWindow *parent);
    QSqlQuery Stats_VL(int opt);
    QVector <double> UI_Stats_VL(Ui::MainWindow* ui);









  /*  bool deleteFromTable(QString c);
    void Rafraichir_VNonConclues(Ui::MainWindow * ui);
    bool addToTable();
    bool ConfirmerAjout(Ui::Fiche_vente * ui);
    void searchInTable(Ui::VenteWindow * ui,QString a);
    bool supprimerVente(Ui::VenteWindow * ui);

    bool modifierVente(Ui::VenteWindow* ui);
    bool ConfirmerModifierVente(Ui::modifier_fiche_vente* ui);

    bool existe();

*/

    void searchInTable(Ui::MainWindow * ui, QString a);



private:
    int ID_vente;
    int ID_contact;
    QString titre;
    QDate date_debut;
    QDate date_exp;
    QString service;
    QString etat;
    QString type_paiement;
    int tarif_pre;
    int tarif_fin;
    int pourcent_paye;
    QString CP10;
    QString CP20;
    QString options;
    QString notes;
   // MainWindow* MM;
    QDate date_fgarantie;











};

#endif // VENTE_H
