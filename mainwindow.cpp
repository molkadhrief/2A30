#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "webaxwidget.h"
#include "avion.h"
#include <QMessageBox>
#include <QApplication>
#include <QMessageBox>
#include<QDebug>
#include<QLineEdit>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QDebug>
#include<QLineEdit>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QSettings>
#include <QDataStream>
#include <QPrinter>
#include <QPrintDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QDesktopServices>
#include <QFileDialog>
#include <QPushButton>
#include <QRadioButton>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QHttpMultiPart>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimer>
#include <QEventLoop>
#include <QPdfWriter>
#include <QPainter>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

      setAttribute(Qt::WA_TranslucentBackground);
  update_id();
      //setWindowFlags(Qt::FramelessWindowHint);
      //ui->tableView->setModel(r.afficher());
  QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                         QCoreApplication::organizationName(), QCoreApplication::applicationName());

      ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESPRIT/@36.9016729,10.1713215,15z");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    int id=ui->id->text().toInt();
    int nb_pas=ui->nb->text().toInt();
        QString modele=ui->md->text();
        QString etat=ui->et->currentText();
        QString carburant=ui->ca->text();





        avion a (id,nb_pas,modele,etat,carburant);
        ui->tableView->setModel(a.afficher());

        bool test= a.ajouter();


          if(test)//si requête executée ==>QMessageBox::information
          {


              QMessageBox::information(nullptr,QObject::tr("ok"),
                      QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
          }

          else //si requête non exécutée ==>QMessageBox::critical
              QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                    QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);
      ui->tableView->setModel(a.afficher());  }




void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
           QSqlQuery qry;
           qry.prepare("select * from Avion where"
                       "identifiant_a='"+val+"' or nb_passagers='"+val+"' or modele='"+val+"' or etat='"+val+"' or carburant ='"+val+"'");
           if(qry.exec())
             {while (qry.next())
            { ui->id->setText(qry.value(0).toString());
              ui->nb->setText(qry.value(1).toString());
              ui->md->setText(qry.value(2).toString());
              ui->et->setCurrentText(qry.value(3).toString());
              ui->ca->setText(qry.value(4).toString());


             }
         }
}

void MainWindow::on_pushButton_2_clicked()
{
    int idaa =ui->id->text().toInt();
               bool test = a.supprimer(idaa);
               if(test)
               {
                   //refresh affichage
                   ui->tableView->setModel(a.afficher());
                  // update_id();
                   QMessageBox::information(nullptr,QObject::tr("ok"),
                                            QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

               }
               else
                   QMessageBox::critical(nullptr,QObject::tr("not ok"),

        QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::update_id()
{

       QSqlQueryModel *m=new QSqlQueryModel();
       QSqlQuery *querry=new QSqlQuery();
       querry->prepare("SELECT identifiant_a FROM Avion");
       querry->exec();
       m->setQuery(*querry);

}
void MainWindow::on_tabWidget_2_tabBarClicked(int index)
{
    qDeleteAll(ui->tabWidget_2->widget(0)->children());
    QWidget* piestats = new QWidget(this);
    piestats = piechart();
    QGridLayout* layout1 = new QGridLayout(this);
    layout1->addWidget(piestats, 0, 0); // Top-Left
    layout1->addWidget(NULL, 0, 1); // Top-Right
    layout1->addWidget(NULL, 1, 0); // Bottom-Left
    layout1->addWidget(NULL, 1, 1); // Bottom-Right
    ui->tab_4->setLayout(layout1);
}

void MainWindow::on_pushButton_3_clicked()
{
    //Récuprération des informations saisies dans les 3 champs
    int id=ui->id->text().toInt();
    int nb_pas=ui->nb->text().toInt();
        QString modele=ui->md->text();
        QString etat=ui->et->currentText();
        QString carburant=ui->ca->text();




    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
avion k (id,nb_pas,modele,etat,carburant);

    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
    bool test =k.ajouter();


      if(test)//si requête executée ==>QMessageBox::information
      {


          QMessageBox::information(nullptr,QObject::tr("ok"),
                  QObject::tr("modification effectué \n Click Cancel to exit."), QMessageBox::Cancel);
      }

      else //si requête non exécutée ==>QMessageBox::critical
          QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                QObject::tr("modification non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);
    ui->tableView->setModel(a.afficher());

}

void MainWindow::on_pushButton_5_clicked()
{
        ui->tableView->setModel(a.AfficherTrieID());
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tableView->setModel(a.rechercherID(arg1));

}

void MainWindow::on_pushButton_4_clicked()
{
    avion c;

             QString text=c.apercu_pdf();
             ui->imp->setText(text);

             QPrinter printer ;
             printer.setPrinterName("imprim");
             QPrintDialog dialog (&printer,this);
             if(dialog.exec()==QDialog::Rejected) return ;
             ui->imp->print(&printer);
}
