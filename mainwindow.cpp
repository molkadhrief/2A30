#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vol.h"
#include<QMessageBox>
#include<QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_ID->setValidator(new QIntValidator(0, 9999999, this));
    ui->lineEdit_vol_mod->setInputMask("AAAAAAAAAAAAAA");
    ui->lineEdit_duree_mod->setInputMask("AAAAAAAAAAAAAA");
    ui->lineEdit_destination_mod->setInputMask("AAAAAAAAAAAAAA");
    ui->le_destination->setInputMask("AAAAAAAAAAAAAA");
    ui->le_duree->setInputMask("AAAAAAAAAAAAAA");
    ui->tab_vol->setModel(V.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    QString id_vol=ui->le_ID->text();
    QString destination=ui->le_destination->text();
     QString duree=ui->le_duree->text();
     Vol V(id_vol,duree,destination);
     bool test=V.ajouter();
     if(test)
          {
              QMessageBox::information(nullptr, QObject::tr("Ok"),
                   QObject::tr("Ajout effectué.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
              ui->tab_vol->setModel(V.afficher());



          }
          else
          {
              QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                   QObject::tr("Ajout non effectué.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);


          }
}


void MainWindow::on_pushButton_clicked()
{
    QString id_vol=ui->lineEdit_supp->text();
        bool test=V.supprimer(id_vol);

        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("Suppression effectué"),QMessageBox::Cancel);
            ui->tab_vol->setModel(V.afficher());
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                 QObject::tr("Suppression non effectué"),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString id_vol=ui->lineEdit_vol_mod->text();
      QString duree=ui->lineEdit_duree_mod->text();
      QString destination=ui->lineEdit_destination_mod->text();
      Vol V(id_vol,duree,destination);

      bool test=V.modifier();
      if(test)
      {
          QMessageBox::information(nullptr, QObject::tr("ok"),
                               QObject::tr("Modiffication effectué"),QMessageBox::Cancel);
          ui->tab_vol->setModel(V.afficher());
      }
      else
          QMessageBox::critical(nullptr, QObject::tr("not ok"),
                               QObject::tr("Modiffication non effectué"),QMessageBox::Cancel);
}
