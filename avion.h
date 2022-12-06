#ifndef AVION_H
#define AVION_H

#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class avion
{
private:
    int id,nb_pas;
    QString modele,etat,carburant;
public:
    avion();
    avion(int,int,QString,QString,QString);
       QString getmodele(){return modele;}
       QString getetat(){return etat;}
QString getcarburant(){return carburant;}
       int getid(){return id;}

       int getnb_pas(){return nb_pas;}


       void setmodele(QString md){modele=md;}
       void setheure_f(QString et){etat=et;}
       void setcarburant(QString ca){carburant=ca;}


       void setid(int Id){this->id=Id;}
       void setnb_pas(int nb_pasa){nb_pas=nb_pasa;}


       bool ajouter();
       bool modifier();

       QSqlQueryModel * afficher();
       bool supprimer(int);
       QSqlQueryModel * AfficherTrieID();
       QSqlQueryModel * rechercherID(QString);
       QString  apercu_pdf();

};
#endif // AVION_H
