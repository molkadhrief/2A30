#include "etudiant.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include"az.h"
Etudiant::Etudiant()
{
id=0;nom=" ";prenom=" ";
}
Etudiant::Etudiant (int id,QString nom,QString prenom)
{this->id=id; this->nom=nom; this->prenom=prenom;}
int Etudiant::getid() {return id;}
QString Etudiant::getnom() {return nom;}
QString Etudiant::gatprenom(){return prenom;}
void Etudiant::setid(int id){this->id=id;}
void Etudiant::setnom(QString){this->nom=nom;}
void Etudiant::setprenom(QString){this->prenom=prenom;}
bool Etudiant::ajouter()
{
    bool test=false;
    QSqlQuery query;
    QString id_string=QString::number(id);
    query.prepare("INSERT INTO  Etudiant(:id,nom,prenom)""values(:id,:nom,:prenom)");
        query.bindValue("id",id_string);
            query.bindValue("nom",nom);
                    query.bindValue("prenom",prenom);
                    return query.exec();
    return test;
}

bool Etudiant::supprimer(int id);
{

QSqlQuery query;
query.prepare("Delete from etudiant where id=:id ")
query.bindvalue(0,id_string);

return query.exec();

}

QSqlQueryModel* Etudiant::afficher()
{


 QSqlQueryModel*model=new QSqlQueryModel() ;

 model->setQuery("SELECT name,salary FROM employee");
 model->setHeaderData(0,Qt::Horizontal, QObject::tr("id"));
 model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom"));
 model->setHeaderData(2,Qt::Horizontal, QObject::tr("prenom"));


}
