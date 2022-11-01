#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDoubleValidator>

class Employe
{
public:
    Employe();
    Employe(int,QString,QString,QString,QString,QString);
    int getcin();
    QString getnom();
    QString getprenom();
    QString getposte();
    QString getadresse();
    QString getmatricule();
    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    void setposte(QString);
    void setadresse(QString);
    void setmatricule(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
private:
    int CIN;
    QString NOM,PRENOM,POSTE,ADRESSE,MATRICULE;
};

#endif // EMPLOYE_H
