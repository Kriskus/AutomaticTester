#ifndef USER_H
#define USER_H

#include <QString>

class User {

public:
    User(unsigned int id, const QString& name, const QString& password, bool userType)
        : id_(id)
        , name_(name)
        , password_(password)
        , userType_(userType)
    {}

    ~User() {}

    unsigned int getId() const { return id_; }
    QString getName() const { return name_; }
    QString getPassword() const { return password_; }
    bool getUserType() const { return admin_; }

    bool checkPassword(const QString& password) {
        return password_ == password;
    }

    bool checkUserPermission(unsigned int idUserCreator) {
        if(admin_) {
            return true;
        } else if(id_ == idUserCreator) {
            return true;
        }
        return false;
    }

private:
    unsigned int id_;
    QString name_;
    QString password_;
    bool admin_;
};

#endif // USER_H
