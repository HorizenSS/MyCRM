#include "smtp.h"
#include <QDebug>
#include "src/SmtpMime"
smtp::smtp(QString dest, QString nom, QString titre, QString contenue){
    this->destMail = dest;
    this->destNom = nom;
    this->mailTitre = titre;
    this->contenue = contenue;
}

void smtp::sendMail(){
    // This is a first demo application of the SmtpClient for Qt project

            // First we need to create an SmtpClient object
            // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

            SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

            // We need to set the username (your email address) and the password
            // for smtp authentification.

            smtp.setUser("ali.sd1919@gmail.com");
            smtp.setPassword("alisd1919");

            // Now we create a MimeMessage object. This will be the email.
            MimeMessage message;

            message.setSender(new EmailAddress("ali.sd1919@gmail.com", "House Care"));
            message.addRecipient(new EmailAddress(destMail,destNom));
            message.setSubject(mailTitre);

            // Now add some text to the email.
            // First we create a MimeText object.

            MimeText text;

            text.setText(contenue);

            // Now add it to the mail

            message.addPart(&text);
            // Now we can send the mail

            if (!smtp.connectToHost()) {
                qDebug() << "Failed to connect to host!" << endl;
              //  return -1;
            }

            if (!smtp.login()) {
                qDebug() << "Failed to login!" << endl;
                //return -2;
            }

            if (!smtp.sendMail(message)) {
                qDebug() << "Failed to send mail!" << endl;
                //return -3;
            }

            smtp.quit();

}
