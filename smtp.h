#ifndef SMTP_H
#define SMTP_H
#include <QString>
class smtp{
private:
    QString destMail;
    QString destNom;
    QString mailTitre;
    QString contenue;
public:
    smtp(){}
    smtp(QString, QString, QString, QString);
    void setDestMail(QString mail){this->destMail = mail;}
    void setDestNom(QString nom){this->destNom = nom;}
    void setMailTitre(QString titre){this->mailTitre = titre;}
    void setContenue(QString contenue){this->contenue = contenue;}
    QString getDestMail(){return destMail;}
    void sendMail();
};

#endif // SMTP_H
