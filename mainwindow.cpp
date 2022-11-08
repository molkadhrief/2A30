#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "billet.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QIntValidator>
#include <QMessageBox>
#include <QDesktopServices>
#include <QFileDialog>
#include <QPushButton>
#include <QPdfWriter>
#include <QPainter>
#include "dialog_stats.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_ID_ajout->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_DES->setInputMask("AAAAAAAAAAAAAAAAAA");
    ui->lineEdit_CLASS->setInputMask("AAAAAAAAAAAAAAAA");
    ui->comboBox->setModel(etmp.afficher_id());
    ui->tableView->setModel(etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
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


//bouton ajouter
void MainWindow::on_AJOUTER_clicked()
{
        int ID_B=ui->lineEdit_ID_ajout->text().toInt();
        QString DESTINATION=ui->lineEdit_DES->text();
        QString CLASSE=ui->lineEdit_CLASS->text();
        QDate DATE_DEP_B=ui->dateEdit_datedep->date();
        QDate DATE_AR_B=ui->dateEdit_datear->date();
        Billet B(ID_B,DATE_DEP_B,DATE_AR_B,DESTINATION,CLASSE);
        bool test=B.ajouter();
        QMessageBox msgBox;
        if (test)
         {  ui->tableView->setModel(B.afficher());
            msgBox.setText("Ajout avec succes");

       } else
            msgBox.setText("Echec d ajout");
        msgBox.exec();
}
//bouton modifier
void MainWindow::on_modifier_clicked()
{
        int ID_B=ui->lineEdit_ID_ajout->text().toInt();
        QString DESTINATION=ui->lineEdit_DES->text();
        QString CLASSE=ui->lineEdit_CLASS->text();
        QDate DATE_AR_B=ui->dateEdit_datear->date();
        QDate DATE_DEP_B=ui->dateEdit_datedep->date();
        Billet B(ID_B,DATE_DEP_B,DATE_AR_B,DESTINATION,CLASSE);
        bool test=etmp.modifier();
        if(test)
        {
            ui->labelinfo->setText("Modification effectué");
            ui->tableView->setModel(etmp.afficher());
            ui->comboBox->setModel(etmp.afficher_id());
        }
        else
        {
            ui->labelinfo->setText("Modification non effectué");
        }
}
//Selection avec combo box
void MainWindow::on_comboBox_currentIndexChanged(QString)
{
        int id=ui->comboBox->currentText().toInt();
        QString id_1=QString::number(id);
        QSqlQuery query ;
        query.prepare("SELECT * FROM  BILLETS where ID_B='"+id_1+"'");
        if(query.exec())
        {
            while (query.next())
            {
                ui->lineEdit_ID_ajout->setText(query.value(0).toString()) ;
                ui->dateEdit_datedep->setDate(query.value(1).toDate());
                ui->dateEdit_datear->setDate(query.value(2).toDate());
                ui->lineEdit_DES->setText(query.value(3).toString()) ;
                ui->lineEdit_CLASS->setText(query.value(4).toString());

            }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("NOT OK "),
                                  QObject::tr("ECHEC DE chargement .\n""Click Cancel to exit."), QMessageBox::Cancel);
        }


}
//bouton supprimer
void MainWindow::on_SUPRIMER_clicked()
{
    Billet b ;
        b.setID_B(ui->comboBox->currentText().toInt());
        bool test=b.supprimer(b.getID_B());
        if(test)
        {
            ui->labelinfo->setText("Suppression effectué");
            ui->tableView->setModel(b.afficher());
            ui->comboBox->setModel(b.afficher_id());
        }
        else
        {
            ui->labelinfo->setText("Suppression non effectué");
        }
}

void MainWindow::on_CHERCHER_textChanged(const QString &arg1)
{
    ui->tableView->setModel(etmp.chercher(arg1));
}
//bouton tri par id
void MainWindow::on_TRIE_ID_clicked()
{
        ui->labelinfo->setText("Tri par ID effectué");
        ui->tableView->setModel(etmp.tri_id());
}

//bouton tri par classe
void MainWindow::on_TRIE_CLASS_clicked()
{
    ui->labelinfo->setText("Tri par Classe effectué");
    ui->tableView->setModel(etmp.tri_classe());
}
//bouton pdf
void MainWindow::on_PDF_clicked()
{QPdfWriter pdf("D:/projetcplusplus/gestionbillet.pdf");

    QPainter painter(&pdf);

    int i = 4000;


    painter.drawText(3000,1500,"LISTE DES BILLETS");
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 50));
    painter.drawRect(2700,200,6300,2600);
    painter.drawRect(0,3000,9600,500);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(300,3300,"ID_B");
    painter.drawText(2300,3300,"DATE_DEP_B");
    painter.drawText(4300,3300,"DATE_AR_B");
    painter.drawText(6000,3300,"DESTINATION");
    painter.drawText(8300,3300,"CLASSE");
    QSqlQuery query;
    query.prepare("select * from BILLETS");
    query.exec();
    while (query.next())
    {
        painter.drawText(300,i,query.value(0).toString());
        painter.drawText(2300,i,query.value(1).toString());
        painter.drawText(4300,i,query.value(2).toString());
        painter.drawText(6300,i,query.value(3).toString());
        painter.drawText(8000,i,query.value(4).toString());
        i = i +500;
    }

    int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("D:/projetcplusplus/gestionbillet.pdf"));

        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
}
//bouton statistique
void MainWindow::on_STAT_clicked()
{
    Dialog_stats stats;
    stats.setModal(true);
    stats.exec();
}
