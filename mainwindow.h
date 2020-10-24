#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
//#include <QtCharts/QtCharts>
#include "client.h"
#include "popup.h"
#include <QPdfWriter>
#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>


#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Accueil_clicked();

    void on_gestionInterne_clicked();

    void on_gestionOuvriers_clicked();

    void on_connecter_clicked();

    void on_ajouter_clicked();

    void on_modifier_clicked();

    void on_enregistrerOuvrier_clicked();

    void on_enregistrerModificationOuvrier_clicked();

    void on_supprimer_clicked();

    void on_chercherouv_textEdited(const QString &arg1);

    void on_deconnexion_clicked();

    void on_tableOuvrier_clicked(const QModelIndex &index);



    void on_modifierMateriel_clicked();

    void on_supprimerMateriel_clicked();



    void on_ajouterMateriel_clicked();

    void on_enregistrerMateriel_clicked();

    void on_gestionMateriaux_clicked();



    void on_enregistrerModificationMateriel_clicked();

    void on_planification_clicked();

    void on_ajouterRV_clicked();

    void on_afficherRV_clicked();

    void on_enregistrerRV_2_clicked();

    void on_modifierRV_clicked();

    void on_supprimerRV_clicked();

    void on_statistique_clicked();


        void on_enregistrerAccordination_clicked();

        void on_precedent_clicked();

        void on_tableMateriaux_clicked(const QModelIndex &index);

        void on_ajouterMateriel_2_clicked();

        void on_enregistrerRV_clicked();

        void on_historique_clicked();

        void on_calendarWidget_clicked(const QDate &date);

        void on_gestionContacts_clicked();

        void on_gestion_client_clicked();

        void on_gestion_fournisseur_clicked();

        void on_gestion_bouquet_clicked();

        void on_Fidelisation_client_clicked();

        void on_Messagerie_fournisseur_clicked();

        void on_ajout_client_clicked();

        void on_consult_client_clicked();

        void on_ajout_four_clicked();

        void on_consult_four_clicked();

        void on_ajout_bouquet_clicked();

        void on_affectation_bouquet_clicked();

        void on_consutation_bouquet_clicked();

        void on_statistique_bouquet_clicked();

        void on_Fidelisation_client_2_clicked();

        void on_Fidelisation_client_3_clicked();

        void on_Fidelisation_client_4_clicked();

        void on_Fidelisation_client_5_clicked();

        void on_Fidelisation_client_6_clicked();

        void on_Ajouter_client_clicked();

        void on_Rech_button_clicked();

        void on_afficher_client_clicked();

        void on_Tri_Nom_clicked();

        void on_Modifier_client_clicked();

        void on_table_aff_client_clicked(const QModelIndex &index);

        void on_supprimer_client_clicked();

        void on_ajouter_fournisseur_clicked();

        void on_annuler_fournisseur_clicked();

        void on_Rech_fournisseur_clicked();

        void on_afficher_fournisseur_clicked();

        void on_Tri_Nom_fournisseur_clicked();

        void on_affichage_fournisseur_clicked(const QModelIndex &index);

        void on_modifier_fournisseur_clicked();

        void on_supprimer_fournisseur_clicked();

        void on_ajouter_bouquet_clicked();

        void on_bouquet_client_clicked(const QModelIndex &index);

        void on_bouquet_bouquet_clicked(const QModelIndex &index);

        void on_actua_bouquet_clicked();

        void on_affecter_bouquet_clicked();

        void on_afficher_les_bouquets_2_clicked();

        void on_commandLinkButton_2_clicked();

        void on_actualiser_parrain_clicked();

        void on_attribution_remise_parrain_clicked();

        void on_cin_parrain_activated(const QModelIndex &index);

        void on_nom_client_parrain_activated(const QModelIndex &index);

        void on_table_attribution_coupon_clicked(const QModelIndex &index);

        void on_attribuer_des_coupons_clicked();

        void on_trier_coupon_clicked();

        void on_afficher_coupon_clicked();

        void on_table_attribution_points_clicked(const QModelIndex &index);

        void on_attribuer_points_clicked();

        void on_trier_points_clicked();

        void on_afficher_points_clicked();

        void on_Ajouter_msg_clicked();

        void on_afficher_msg_clicked();

        void on_trier_msg_clicked();

        void on_gestion_rec_clicked();

        void on_sav_clicked();

        void on_ajouter_rec_clicked();

        void on_modifier_rec_clicked();

        void on_afficher_rec_clicked();

        void on_suprimer_rec_clicked();

        void on_id_vente_textEdited(const QString &arg1);

        void on_id_2_textEdited(const QString &arg1);

        void on_modifier_ter_clicked();

        void on_tri_rec_clicked();

        void on_supprimer_rec_id_clicked();

        void on_gestion_inter_clicked();

        void on_ajouter_inter_clicked();

        void on_modifier_rec_2_clicked();

        void on_supp_inter_clicked();

        void on_afficher_inter_clicked();

        void on_rechecher_inter_textEdited(const QString &arg1);

        void on_tri_inter_clicked();

        void on_ajouetr_inter_ter_clicked();

        void on_terminer_inter_mod_clicked();

        void on_ci_2_textEdited(const QString &arg1);

        void on_supp_inter_2_clicked();

        void on_imprimer_clicked();

        void on_afficher_g_clicked();

        void on_actualiser_clicked();

        void on_rechercher_g_textEdited(const QString &arg1);

        void on_asc_clicked();

        void on_desc_clicked();

        void on_tablegarantie_clicked(const QModelIndex &index);

        void on_gestion_gar_clicked();

        void on_mail_clicked();

        void on_envoyer_clicked();

        void on_stat_clicked();
        void makeplot2();

        void on_rechercher_rec_textEdited(const QString &arg1);

        void on_ajouterCompte_clicked();

        void on_enregistrerCompte_clicked();

        void on_supprimerCompte_clicked();

        void on_modifierCompte_clicked();

        void on_enregistrerCompte_2_clicked();

        void on_recupererHO_clicked();

        void on_recupererHM_clicked();

        void on_RafraichirVentes_clicked();

        void on_Search_bar_ventes_textEdited(const QString &arg1);

        void on_AjouterVente_clicked();

        void on_SupprimerVente_clicked();

        void on_ModifierVente_clicked();

        void on_V_pushButton_Confirmer_2_clicked();

        void on_tableView_Ventes_activated(const QModelIndex &index);

        void on_V_pushButton_Annuler_clicked();

        void on_V_pushButton_Confirmer_clicked();

        void on_V_pushButton_Annuler_2_clicked();

        void makeplot_ventes();

        void on_Statistiques_Ventes_clicked();

        void on_ImprimerVente_clicked();

        void on_V_pushButton_RetourStat_clicked();

        void on_vente_clicked();

        void on_gestionOuvriers_2_clicked();

        void on_PO_pushButton_ajouter_clicked();

        void on_PO_Ajout_Confirmer_clicked();

        void on_PO_pushButton_modifier_clicked();

        void on_PO_pushButton_modifier_Opp_clicked();

        void on_PO_Ajout_Confirmer_2_clicked();

        void on_PO_pushButton_supprimer_clicked();

        void on_PO_pushButton_supprimer_Opp_clicked();

        void on_PO_Rafraichir_clicked();

        void on_PO_lineEdit_recherche_textEdited(const QString &arg1);

        void on_PO_lineEdit_rechercheOpp_textEdited(const QString &arg1);

        void on_historique_2_clicked();

        void on_planification_2_clicked();

        void on_S_lineEdit_Recherche_textEdited(const QString &arg1);

        void on_S_pushButton_Rafraichir_clicked();

        void on_S_pushButton_AjouterService_clicked();

        void on_S_pushButton_Confirmer_clicked();

        void on_S_pushButton_Annuler_clicked();

        void on_S_pushButton_SupprimerService_clicked();

        void on_S_pushButton_ModifierService_clicked();

        void on_S_pushButton_Confirmer_2_clicked();

        void on_S_pushButton_Annuler_2_clicked();

        void on_calendarWidget_2_clicked(const QDate &date);

        void on_trierQte_clicked();

        void on_trierNom_clicked();

        void on_trierSpecialite_clicked();

        void on_recupererHR_clicked();

        void on_analyse_clicked();

        void on_ajoutercompagne_clicked();

        void on_pushButton_3_clicked();

        void on_pushButton_2_clicked();

        void on_pushButton_4_clicked();

        void on_affichercompagnes_clicked();

        void on_pushButton_6_clicked();

        void on_meilleur_service_clicked();

        void on_c_fidele_clicked();

        void on_pushButton_7_clicked();

        void on_ajouter_2_clicked();

        void on_mettreajour_clicked();

        void on_affichercompagnes_2_clicked();

        void on_annuler_clicked();

        void on_supprimercompagne_clicked();

        void on_modifiercompagne_clicked();

        void on_imprimer_2_clicked();

        void on_exporter_clicked();

        void on_affichercompagne_clicked();

        void on_rechercher_clicked();

        void on_maxtab_clicked(const QModelIndex &index);


        void on_sendmail_clicked();

        void on_pushButton_8_clicked();

        void on_customPLot_destroyed();

        void on_tableDetail_activated(const QModelIndex &index);

        void on_maxtab_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    int page;
    //client Pr,Cl;
    PopUp popup ;
    QSystemTrayIcon *notification;
  // QtCharts::QChartView *chartView;
   //QtCharts::QBarSeries *barSeries;
    QPrinter *printer;

};

#endif // MAINWINDOW_H
