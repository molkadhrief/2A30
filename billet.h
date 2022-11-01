#ifndef BILLET_H
#define BILLET_H
#include <QString>
#include <QDate>
#include <QtSql/QSqlQueryModel>
class Billet
{
public:
    Billet();
    Billet(QString,QDate,QDate,QString,QString);

    QString getID_B();
    QString getDESTINATION();
    QString getCLASSE();
    QDate getDATE_DEP_B();
    QDate getDATE_AR_B();

    void setID_B(QString);
    void setDESTINATION(QString);
    void setCLASSE(QString);
    void setDATE_DEP_B(QDate);
    void setDATE_AR_B(QDate);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier();
private:
    QString ID_B,DESTINATION,CLASSE;
    QDate DATE_DEP_B,DATE_AR_B;

};

#endif // BILLET_H
