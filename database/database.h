#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <memory>

#include "../operation/fileread.h"

class Database
{
public:
    Database()
    {
        QScopedPointer<FileRead> fileRead(new FileRead("db.cfg"));
        QVector<QString> dbConfig = fileRead->readFile();
        db_.setHostName(dbConfig[0].replace("\n", ""));
        db_.setPort(dbConfig[1].replace("\n", "").toInt());
        db_.setDatabaseName(dbConfig[2].replace("\n", ""));
        db_.setUserName(dbConfig[3].replace("\n", ""));
        db_.setPassword(dbConfig[4].replace("\n", ""));
    }
    ~Database(){}

    bool connect()
    {
        if(db_.isOpen()) {
            return true;
        } else {
            return false;
        }
    }

private:
    QSqlDatabase db_ = QSqlDatabase::addDatabase("QMYSQL");
};

#endif // DATABASE_H
