#include "employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDoubleValidator>

Employe::Employe()
{
CIN=0; NOM=" "; PRENOM=" "; POSTE=" "; ADRESSE=" "; MATRICULE=" ";
}
Employe::Employe(int CIN,QString NOM,QString PRENOM,QString POSTE,QString ADRESSE,QString MATRICULE)
{this->CIN=CIN; this->NOM=NOM; this->PRENOM=PRENOM; this->POSTE=POSTE; this->ADRESSE=ADRESSE; this->MATRICULE=MATRICULE;}
int Employe::getcin() {return CIN;}
QString Employe::getnom() {return NOM;}
QString Employe::getprenom() {return PRENOM;}
QString Employe::getposte() {return POSTE;}
QString Employe::getadresse() {return ADRESSE;}
QString Employe::getmatricule() {return MATRICULE;}
void Employe::setcin(int CIN) {this->CIN=CIN;}
void Employe::setnom(QString NOM) {this->NOM=NOM;}
void Employe::setprenom(QString PRENOM) {this->PRENOM=PRENOM;}
void Employe::setposte(QString POSTE) {this->POSTE=POSTE;}
void Employe::setadresse(QString ADRESSE) {this->ADRESSE=ADRESSE;}
void Employe::setmatricule(QString MATRICULE) {this->MATRICULE=MATRICULE;}
bool Employe::ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(CIN);
    query.prepare("INSERT INTO EMPLOYE(CIN, NOM,PRENOM,POSTE,ADRESSE,MATRICULE )" "VALUES (:CIN, :NOM, :PRENOM, :POSTE, :ADRESSE, :MATRICULE)");
    query.bindValue(":CIN", CIN);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":POSTE",POSTE);
    query.bindValue(":ADRESSE",ADRESSE);
    query.bindValue(":MATRICULE",MATRICULE);
    return query.exec();
}
bool Employe::supprimer(QString MATRICULE)
{
    QSqlQuery query;
             query.prepare("DELETE FROM EMPLOYE where MATRICULE= :MATRICULE");
             query.bindValue(0, MATRICULE);
        return query.exec();
}
QSqlQueryModel* Employe::afficher()

{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM EMPLOYE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("POSTE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("MATRICULE"));
    return model;
}
