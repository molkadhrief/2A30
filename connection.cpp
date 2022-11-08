#include "connection.h"

Connection::Connection()
{

}
bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("ProjetA2");
db.setUserName("Touta");
db.setPassword("Touta");

if (db.open())
test=true;





    return  test;
}
