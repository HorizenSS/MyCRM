#include "st.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include "mainwindow.h"
#include "connection.h"
#include<QSqlRecord>
#include <iostream>
#include <QSqlQueryModel>

/*st::st(QWidget *parent):QWidget(parent),ui(new Ui::st)

{


    ui->setupUi(this);

    st::makePlot() ;
}*/

/*st::~st()
{
    delete ui;
}*/
void st::makePlot()
{QSqlQuery q1, q2, q3;
    q1.exec("select count(*) from service where prix <=150");
    QSqlQueryModel m, m2,m3;
    m.setQuery(q1);
    int a= m.record(0).value(0).toString().toInt();

    q2.exec("select count(*) from service where prix <=500 and prix>150");

    m2.setQuery(q2);
    int b= m2.record(0).value(0).toString().toInt();


    q3.exec("select count(*) from service where prix <=1000 and prix>500");

    m3.setQuery(q3);
    int c= m3.record(0).value(0).toString().toInt();

    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    //ui->customPLot->setBackground(QBrush(gradient));


    // create empty bar chart objects:

   // QCPBars *fossil = new QCPBars(ui->customPLot->xAxis, ui->customPLot->yAxis);

   // fossil->setAntialiased(false);

    //fossil->setStackingGap(1);
    // set names and colors:
   // fossil->setName("services");
   // fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
 //  fossil->setBrush(QColor(111, 9, 176));

    // stack bars on top of each other:


    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3;
    labels << "<100 dt" << "<500 dt" << "<1000 dt" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    //ui->customPLot->xAxis->setTicker(textTicker);
//    ui->customPLot->xAxis->setSubTicks(false);
//    ui->customPLot->xAxis->setRange(0, 8);
//    ui->customPLot->xAxis->setTickPen(QPen(Qt::white));
//    ui->customPLot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
//    ui->customPLot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
//    ui->customPLot->yAxis->setPadding(5); // a bit more space to the left border
//    ui->customPLot->yAxis->setBasePen(QPen(Qt::white));
//    ui->customPLot->yAxis->setSubTickPen(QPen(Qt::white));
//    ui->customPLot->yAxis->setTickLabelColor(Qt::white);
//    ui->customPLot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
//
    // Add data:
    QVector<double> fossilData;
    fossilData  << a << b << c;

  //  fossil->setData(ticks, fossilData);

    // setup legend:
 //   ui->customPLot->legend->setVisible(true);
//    ui->customPLot->legend->setBrush(QColor(255, 255, 255, 100));
//    QFont legendFont = font();
 //   legendFont.setPointSize(10);
//    ui->customPLot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

int st::calculer(QString categorie)
{
    QSqlQuery q ;
    int i=0;
    q.prepare("select count(*) from service where categorie=:cat");
   q.bindValue(":cat",categorie);
   if (q.exec())
   {
    while (q.next())
    {
      i=q.value(0).toInt();
    }
   }
   return i;
}

void st::on_pushButton_clicked()
{//houni pour faire apparaitre la statistique !
   st::makePlot() ;

}

//void st::on_pushButton_2_clicked()
//{

//}

void st::on_menu_stat_clicked()
{
    MainWindow *m= new MainWindow(this);
           this->hide();
            m->show();
}
