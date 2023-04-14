#ifndef QUERY_H
#define QUERY_H

#include <QObject>
#include <QSqlQuery>
#include <QVector>
#include <QVariant>
#include <memory>

#include "../../structure/user.h"

class QueryUser {
public:
    QueryUser();
    ~QueryUser();

    void userSELECT();
    void userINSERT();
    void userDELETE();
    void userUPDATE();

private:
    QVector<std::shared_ptr<User>> users{};
    QSqlQuery query_;

signals:
    void sendUsers(QVector<std::shared_ptr<User>>);
};

#endif // QUERY_H
