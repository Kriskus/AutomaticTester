#include "queryuser.h"

#include <QDebug>

QueryUser::QueryUser()
{

}

QueryUser::~QueryUser()
{

}

void QueryUser::userSELECT()
{
    query_.exec("SELECT * FROM Uzytkownicy;");
    while(query_.next()) {
        users.push_back(std::make_shared<User> (query_.value(0).toInt(), query_.value(1).toString(), query_.value(2).toString(), query_.value(4).toBool()));
    }
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
