#include "connection.h"

Connection::Connection()
{

}
bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projetcpp");
db.setUserName("EyaNehdi");
db.setPassword("EyaNehdi");

if (db.open())
test=true;





    return  test;
}
