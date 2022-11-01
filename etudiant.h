#ifndef ETUDIANT_H
#define ETUDIANT_H
#include<QSqlQueryModel>
#include<QString>
class Etudiant
{
public:
    Etudiant();
    Etudiant (int,QString,QString);
    int getid();
    QString getnom();
    QString gatprenom();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
bool ajouter();
QSqlQueryModel afficher();
bool supprimer(int);
private:
    int id;
    QString nom,prenom;
};

#endif // ETUDIANT_H
