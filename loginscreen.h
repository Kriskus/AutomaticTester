#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QKeyEvent>
#include <QCloseEvent>
#include <QMainWindow>
#include <memory>

#include "database/query/queryuser.h"
#include "database/database.h"
#include "structure/user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginScreen; }
QT_END_NAMESPACE

class LoginScreen : public QMainWindow
{
    Q_OBJECT

public:
    LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();

private:
    Ui::LoginScreen *ui;
    std::unique_ptr<QueryUser> queryUser = std::make_unique<QueryUser> ();
    QVector<std::shared_ptr<User>> users_;

    unsigned int currentUserId_{0};

    void database();
    void showMainWindow();

    void updateUsers(const QVector<std::shared_ptr<User>>& users);
    void setCurrentUserToFile(QString currentUser);
    void getLastUserFromFile(const QVector<QString> &lastUser);

    void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event);
};
#endif // LOGINSCREEN_H
