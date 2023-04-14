#ifndef QUERY_H
#define QUERY_H

#include <QObject>
#include <QVector>
#include <memory>

#include "../../structure/user.h"

class QueryUser : public QObject
{
    Q_OBJECT

public:
    QueryUser();
    ~QueryUser();

    void userSELECT();
    void userINSERT();
    void userDELETE();
    void userUPDATE();

private:
    QVector<std::shared_ptr<User>> users_{};

signals:
    void sendUsers(QVector<std::shared_ptr<User>>);
};

#endif // QUERY_H
