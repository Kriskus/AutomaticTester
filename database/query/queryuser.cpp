#include "queryuser.h"

#include <QDebug>
#include <QSqlQuery>
#include <QVariant>


QueryUser::QueryUser()
{

}

QueryUser::~QueryUser()
{

}

void QueryUser::userSELECT()
{
    QSqlQuery query;
    query.exec("SELECT * FROM Uzytkownicy;");
    while(query.next()) {
        users_.push_back(std::make_shared<User> (query.value(0).toInt(), query.value(1).toString(), query.value(3).toString(), query.value(2).toBool()));
    }
    emit sendUsers(users_);
}

void QueryUser::userINSERT()
{

}

void QueryUser::userDELETE()
{

}

void QueryUser::userUPDATE()
{

}
