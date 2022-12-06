#include "avion.h"
#include<QSqlQuery>
#include<QtDebug>
avion::avion()
{
    id=0;
          modele="";
          etat="";
          carburant="";
          nb_pas=0;

}
avion::avion(int id,int nb_pas,QString modele,QString etat,QString carburant)
{

    this->id=id;
    this->nb_pas=nb_pas;
   this->etat=etat;
   this->modele=modele;
   this->carburant=carburant;

}
bool avion::ajouter()
{
    QSqlQuery query;
    QString res1 = QString::number(id);
    QString res2 = QString::number(nb_pas);


    //prepare() prend la requête en paramétre pour la préparer a l'exécution
    query.prepare("insert into Avion(identifiant_a,nbr_passagers,modele,etat,carburant)""values( :id, :nb_pas,:modele, :etat, :carburant)");

    //Création des variables liées
    query.bindValue(":id",res1);
    query.bindValue(":nb_pas",res2);
    query.bindValue(":modele",modele);
    query.bindValue(":etat",etat);
     query.bindValue(":carburant",carburant);

    return query.exec();//exec() envoie la requête pour l'exécution





}
bool avion::modifier()
{
    QSqlQuery query ;
    QSqlQuery query1;
    int b=0;
    QString res1 = QString::number(id);
    QString res2 = QString::number(nb_pas);

    query1.prepare("SELECT identifiant_a FROM Avion WHERE identifiant_a=:idA");
    query1.bindValue(":idA",res1);
    query1.exec();
    while(query1.next())
    {
        b++;
    }

    if (b!=0)
    {
    query.prepare("UPDATE Avion set identifiant_a=:identifiant_a,nbr_passagers=:nbr_passagers,modele=:modele,etat=:etat,carburant:=carburant WHERE identifiant_a=:identifiant_a");
    query.bindValue(":id",res1);
    query.bindValue(":nb_pas",res2);
    query.bindValue(":modele",modele);
    query.bindValue(":etat",etat);
    query.bindValue(":carburant",carburant);



    return query.exec();//exec() envoie la requête pour l'exécution
}
    else
    {
        return false;
    }
}





QSqlQueryModel * avion::afficher()
{


QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from Avion");
return model;

}




bool avion::supprimer(int idA)
{

               QSqlQuery query;
               QSqlQuery query1;
               int b=0;
               QString res=QString::number(idA);

               query1.prepare("SELECT identifiant_a FROM Avion WHERE identifiant_a=:idA");
               query1.bindValue(":idA",res);
               query1.exec();
               while(query1.next())
               {
                   b++;
               }

               if (b!=0)
               {


               query.prepare("Delete from Avion where identifiant_a=:idA");
               query.bindValue(":idA",res);
               return query.exec(); }

               else
               {
                   return false;
               }
    }
QSqlQueryModel * avion::AfficherTrieID()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Avion ORDER BY identifiant_a");

    return model;
}




QSqlQueryModel * avion::rechercherID(QString id)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from Avion where identifiant_a like ?");
    q.addBindValue("%"+ id +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}
QString avion:: apercu_pdf()
 {
    QString text="          ****** avion  ******      \n \n " ;
     QSqlQuery query ;
     QString i,x,z,a,b;


      query.exec("select * from Avion  ");
      while (query.next())
      {
         i=query.value(0).toString();
         x=query.value(1).toString();
         z=query.value(2).toString();
         a=query.value(3).toString();
         b=query.value(4).toString();
        text += "\n identifiant_a  : "+i+"\n\n - nbr_passagers : "+ z+"\n - modele : "+ x+"\n - etat:"+a+"\n - carburant:"+b+"\n"  ;


     }

             return text ;
 }



