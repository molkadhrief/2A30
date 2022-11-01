#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "connection.h"
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDesktopServices>
#include <QSqlQueryModel>
#include <QDoubleValidator>
#include <QPushButton>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_cin->setValidator( new QIntValidator(0, 99999999, this));
    ui->lineEdit_nom->setInputMask("AAAAAAAAAAAAAAAAAAAA");
    ui->lineEdit_prenom->setInputMask("AAAAAAAAAAAAAAAAAA");
    ui->lineEdit_poste->setInputMask("AAAAAAAAAAAAAAAAAA");
    ui->lineEdit_adresse->setInputMask("AAAAAAAAAAAAAAAAAA");
    ui->lineEdit_matricule->setInputMask("AAAAAAAAAAAAAAAAAA");
    ui->tableView_Employe->setModel (E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    int CIN=ui->lineEdit_cin->text().toInt();
        QString NOM=ui->lineEdit_nom->text();
        QString PRENOM=ui->lineEdit_prenom->text();
        QString POSTE=ui->lineEdit_poste->text();
        QString ADRESSE=ui->lineEdit_adresse->text();
        QString MATRICULE=ui->lineEdit_matricule->text();

        Employe E(CIN,NOM,PRENOM,POSTE,ADRESSE,MATRICULE);

        bool test=E.ajouter();
        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                                     QObject::tr("Ajout effectué.\n""Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_Employe->setModel(E.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                  QObject::tr("Ajout non effectué.\n""Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void MainWindow::on_pushButton_SUPP_clicked()
{
    Employe E;
       int cin=ui->lineEdit_cinS->text().toInt();
        bool test=E.supprimer(cin);
        if(test)
        {
                QMessageBox::information(nullptr, QObject::tr("Ok"),
                                         QObject::tr("Suppression effectué.\n""Click Cancel to exit."), QMessageBox::Cancel);
           ui->tableView_Employe->setModel(E.afficher());
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                      QObject::tr("Suppression non effectué.\n" "Click Cancel to exit."), QMessageBox::Cancel);
            }
}



void MainWindow::on_pushButton_mod1_clicked()
{
    int CIN=ui->lineEdit_modCIN->text().toInt();
        QString NOM=ui->lineEdit_modNom->text();
        QString PRENOM=ui->lineEdit_modPrenom->text();
        QString POSTE=ui->lineEdit_modPoste->text();
        QString ADRESSE=ui->lineEdit_modAdresse->text();
        QString MATRICULE=ui->lineEdit_mod1->text();
        Employe E(CIN,NOM,PRENOM,POSTE,ADRESSE,MATRICULE);

        bool test=E.modifier();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("Ok"),
                                     QObject::tr("Modification effectuée.\n""Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_Employe->setModel(E.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                                  QObject::tr("Modification non effectuée.\n""Click Cancel to exit."), QMessageBox::Cancel);
        }
}
