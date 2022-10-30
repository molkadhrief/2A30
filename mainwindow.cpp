#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "billet.h"
#include <QIntValidator>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_ID_ajout->setValidator(new QIntValidator(0,9999999,this));
ui->tablebillet->setModel(B.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

//bouton ajouter
void MainWindow::on_pushButton_valider_ajout_clicked()
{
    QString ID_B=ui->lineEdit_ID_ajout->text();
    QString DESTINATION=ui->lineEdit_destination_ajout->text();
    QString CLASSE=ui->lineEdit_classe_ajout->text();
    QDate DATE_DEP_B=ui->dateEdit_datedep_ajout->date();
    QDate DATE_AR_B=ui->dateEdit_datear_ajout->date();
    Billet B(ID_B,DATE_DEP_B,DATE_AR_B,DESTINATION,CLASSE);
    bool test=B.ajouter();
    QMessageBox msgBox;
    if (test)
     {  ui->tablebillet->setModel(B.afficher());
        msgBox.setText("Ajout avec succes");

   } else
        msgBox.setText("Echec d ajout");
    msgBox.exec();

}
//bouton supprimer
void MainWindow::on_pushButton_valider_supp_clicked()
{
Billet B;
QString ID_B(ui->lineEdit_ID_supp->text());
bool test=B.supprimer(ID_B);
QMessageBox msgBox;
if (test)
   { ui->tablebillet->setModel(B.afficher());
    msgBox.setText("Suppression avec succes");

}else
    msgBox.setText("Echec de suppression");
msgBox.exec();
}


// acceder au different widgets
void MainWindow::on_pushButton_b_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_valider_login_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_ab_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_affb_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_eb_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_mb_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_annuler_login_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_annuler_ajout_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_annuler_aff_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_annuler_supp_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_annuler_mod_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
