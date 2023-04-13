#ifndef QUERY_H
#define QUERY_H

#include <QObject>
#include <QVector>

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
    QVector<QScopedPointer<User>> users{};
};

#endif // QUERY_H
