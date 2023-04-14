#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>

#include "../operation/fileread.h"

class Database : public QObject
{
    Q_OBJECT
public:
    Database()
    {
        QScopedPointer<FileRead> fileRead(new FileRead("db.cfg"));
        QVector<QString> dbConfig = fileRead->readFile();
        for(QString &line: dbConfig) {
            line.replace("\n", "");
            line.replace("\r", "");
        }
        if(dbConfig.size() > 2) {
        fileRead.reset();
        db_.setHostName(dbConfig[0]);
        db_.setPort(3306);
        db_.setDatabaseName(dbConfig[1]);
        db_.setUserName(dbConfig[2]);
        db_.setPassword(dbConfig[3]);
        }
    }
    ~Database(){}

    void connect()
    {
        if(db_.open()) {
            emit connectionStatus("Połączono z bazą danych.", 5000);
        } else {
            emit connectionStatus(db_.lastError().text(), 5000);
        }
    }

private:
    QSqlDatabase db_ = QSqlDatabase::addDatabase("QMYSQL");

signals:
    void connectionStatus(QString, int);
};

#endif // DATABASE_H
