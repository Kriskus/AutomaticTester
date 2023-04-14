#ifndef USER_H
#define USER_H

#include <QString>

class User {

public:
    User(unsigned int id, const QString& name, const QString& password, bool admin)
        : id_(id)
        , name_(name)
        , password_(password)
        , admin_(admin)
    {}

    ~User() {}

    unsigned int getId() const { return id_; }
    QString getName() const { return name_; }
    QString getPassword() const { return password_; }
    bool getPermission() const { return admin_; }

    bool checkPassword(const QString& password) { return password_ == password; }
    bool checkUserPermission(unsigned int idUserCreator) { return id_ == idUserCreator; }

private:
    unsigned int id_;
    QString name_;
    QString password_;
    bool admin_;
};

#endif // USER_H
