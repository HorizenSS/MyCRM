#ifndef GARANTIE_H
#define GARANTIE_H
#include <QMainWindow>
#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>



class garantie
{
private:
    long CS;

    QString NOM_SERVICE;
    QString NOM_OUV;
    long ID_OUV;
    QString NOM_CLIENT;
    long ID_CLIENT;
    QString ADRESS;
    QDate  DATE_FIN;
    QDate Q;




public:

    garantie();
    garantie(long,QString,QString,long,QString,long,QString,QDate);
    bool ajouter_service_sous_garantie(Ui::MainWindow *ui);
    bool modifier(Ui::MainWindow *ui);
    bool afficher(Ui::MainWindow *ui);
    bool rechercher(Ui::MainWindow *ui);
    bool tri(Ui::MainWindow *ui);
    bool actualiser(Ui::MainWindow *ui);
    void sendmail(Ui::MainWindow *ui);
    void mailsent(QString);
    bool tri_2(Ui::MainWindow *ui);

};
#endif // GARANTIE_H
