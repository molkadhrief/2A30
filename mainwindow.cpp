#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"etudiant.h"
#include"dialog.h"
#include<QIntValidator>
#include"az.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->line_id->setValidator(new QIntValidator(0,99999999,this));
    ui->tab_Etudiant->setModel(e.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  Etudiant e;
e.setnom(ui->linenom->text());
e.setprenom(ui->lineprenom->text());
e.setid(ui->line_id())

Dialog d;
d.setEtudiant(e);
d.exec();
}

void MainWindow::on_pb_supp_clicked()
{

    Etudiant e1;e1.setid(ui->le_id_supp->text().toInt());
    bool test=e1.supprimer(e1.getid());
    QMessageBox Msgbox;
    if (test)
    {Msgbox.setText("suppression avec succes");}
    ui->tab_etudiant->setmodel(e.afficher())
    else
        Msgbox.settext("echec de suppresion");
    msgbox.exec();
}
