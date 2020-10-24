#ifndef BOUQUET_H
#define BOUQUET_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QString>
#include<QDate>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QMainWindow>
class bouquet
{private:

    long ID_bouquet;
    QString Nom_bouquet ;
    QString reparation_bouquet ;
    QString desinsectation_bouquet ;
    QString electricite_bouquet ;
    QString Menage_bouquet ;
    QString Peinture_bouquet ;
    QString coursparticulier_bouquet;
    QString demenagement_bouquet;
    QString plomberie_bouquet;
    QString jardinage_bouquet;
    QString transport_bouquet;
    QString soignant_bouquet;
    QString babysitting_bouquet;



public:

    bool Ajouter_bouquet(Ui::MainWindow *ui);
    bouquet( long ID_bouquet= 0,QString Nom_bouquet="" , QString reparation_bouquet="" ,QString desinsectation_bouquet="",QString electricite_bouquet="",QString Menage_bouquet="" ,QString Peinture_bouquet="",QString coursparticulier_bouquet="" ,QString demenagement_bouquet="",QString plomberie_bouquet="",QString jardinage_bouquet="",QString transport_bouquet="",QString soignant_bouquet="",QString babysitting_bouquet="")
    {
        this->ID_bouquet=ID_bouquet;
        this->Nom_bouquet=Nom_bouquet;
        this->reparation_bouquet=reparation_bouquet;
        this->desinsectation_bouquet=desinsectation_bouquet;
        this->electricite_bouquet=electricite_bouquet;
        this->Menage_bouquet=Menage_bouquet;
        this->Peinture_bouquet=Peinture_bouquet;
        this->coursparticulier_bouquet=coursparticulier_bouquet;
        this->demenagement_bouquet=demenagement_bouquet;
        this->plomberie_bouquet=plomberie_bouquet;
        this->jardinage_bouquet=jardinage_bouquet;
        this->transport_bouquet=transport_bouquet;
        this->soignant_bouquet=soignant_bouquet;
        this->babysitting_bouquet=babysitting_bouquet;


    }


    long getID_bouquet(){return ID_bouquet;};
    QString getNom_bouquet(){return Nom_bouquet;};
    QString getreparation_bouquet(){return reparation_bouquet;};
    QString getdesinsectation_bouquet(){return desinsectation_bouquet;};
    QString getelectricite_bouquet(){return electricite_bouquet;};
    QString getmenage_bouquet(){return Menage_bouquet;};
    QString getPeinture_bouquet(){return Peinture_bouquet;};
    QString getcoursparticulier_bouquet(){return coursparticulier_bouquet;};
    QString getdemenagement_bouquet(){return demenagement_bouquet;};
    QString getplomberie_bouquet(){return plomberie_bouquet;};
   QString getjardinage_bouquet(){return jardinage_bouquet;};
   QString gettransport_bouquet(){return transport_bouquet;};
   QString getsoignant_bouquet(){return soignant_bouquet;};
   QString getbabysitting_bouquet(){return babysitting_bouquet;};

   void setID_bouquet (long ID_bouquet)
   {
        this->ID_bouquet=ID_bouquet;
   }
    void setNom_bouquet (QString Nom_bouquet)
    {
         this->Nom_bouquet=Nom_bouquet;
    }
    void setreparation_bouquet (QString reparation_bouquet)
    {
         this->reparation_bouquet=reparation_bouquet;
    }

    void setdesinsectation_bouquet (QString desinsectation_bouquet)
    {
         this->desinsectation_bouquet=desinsectation_bouquet;
    }
    void setelectricite_bouquet (QString electricite_bouquet)
    {
         this->electricite_bouquet=electricite_bouquet;
    }
    void setmenage_bouquet (QString Menage_bouquet)
    {
         this->Menage_bouquet=Menage_bouquet;
    }
    void setPeinture_bouquet (QString Peinture_bouquet)
    {
         this->Peinture_bouquet=Peinture_bouquet;
    }
    void setcoursparticulier_bouquet (QString coursparticulier_bouquet)
    {
         this->coursparticulier_bouquet=coursparticulier_bouquet;
    }
    void setdemenagement_bouquet (QString demenagement_bouquet)
    {
         this->demenagement_bouquet=demenagement_bouquet;
    }
    void setplomberie_bouquet (QString plomberie_bouquet)
    {
         this->plomberie_bouquet=plomberie_bouquet;
    }
    void setjardinage_bouquet (QString jardinage_bouquet)
    {
         this->jardinage_bouquet=jardinage_bouquet;
    }
    void settransport_bouquet (QString transport_bouquet)
    {
         this->transport_bouquet=transport_bouquet;
    }
    void setsoignant_bouquet (QString soignant_bouquet)
    {
         this->soignant_bouquet=soignant_bouquet;
    }
    void setbabysitting_bouquet (QString babysitting_bouquet)
    {
         this->babysitting_bouquet=babysitting_bouquet;
    }
};
#endif // BOUQUET_H
