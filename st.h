#ifndef ST_H
#define ST_H
#include <QDialog>
#include <QVector>
#include <QWidget>
#include "connection.h"
#include "ui_mainwindow.h"

namespace Ui {
class st;
}

class st : public QWidget
{
    Q_OBJECT

public:
    explicit st(QWidget *parent = 0);
    ~st();
    QVector<double> Statistique();
        void makePlot() ;
        int calculer(QString);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_menu_stat_clicked();

    void on_customPLot_destroyed();

private:
    Ui::st *ui;
};

#endif // ST_H
