#ifndef INTERVENTION_H
#define INTERVENTION_H
#include <QMainWindow>
#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class intervention
{private:
    long  CI;
    long CODE_OUV;
    long ID_CLIENT;
    QString NOM_CLIENT;
    QString NOM_SERVICE;
    QString NOM_OUV;
    QString DEG;
    QDate DATE_INTER;
     int PRIX;
public:
    intervention();
    intervention(long,long,long,QString,QString,QString,QDate,QString,int);
    bool ajouter_intervention(Ui::MainWindow *ui);
    bool modifier_intervention(Ui::MainWindow *ui);
    bool afficher_intervention(Ui::MainWindow *ui);
    bool supprimer_intervention(Ui::MainWindow *ui);
    bool rechercher(Ui::MainWindow *ui);
    bool tri_intervention(Ui::MainWindow *ui);
    QVector<double> statstique();
   int CountFromDatabase(QString,QString);
};

#endif // INTERVENTION_H
