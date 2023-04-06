#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QKeyEvent>
#include <QCloseEvent>
#include <QMainWindow>

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

    void database();
    void showMainWindow();

    void updateUsers();
    void setCurrentUserToFile(QString currentUser);
    void getLastUserFromFile(const QVector<QString> &lastUser);

    void keyPressEvent(QKeyEvent *event);
    void closeEvent(QCloseEvent *event);
};
#endif // LOGINSCREEN_H
