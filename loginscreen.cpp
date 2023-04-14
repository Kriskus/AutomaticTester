#include "loginscreen.h"
#include "./ui_loginscreen.h"

#include <QMessageBox>

#include "database/database.h"

#include "database/query/queryuser.h"

LoginScreen::LoginScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginScreen)
{
    ui->setupUi(this);

    connect(ui->pushButtonExit, &QPushButton::clicked, this, &LoginScreen::close);
    connect(ui->pushButtonLogIn, &QPushButton::clicked, this, &LoginScreen::showMainWindow);

    database();
    getLastUserFromFile({"asd"});
}

LoginScreen::~LoginScreen()
{
    delete ui;
}

void LoginScreen::database()
{
    QScopedPointer<Database> db(new Database());
    connect(db.get(), &Database::connectionStatus, ui->statusbar, &QStatusBar::showMessage);
    db->connect();
    QueryUser query;
    query.userSELECT();
}

void LoginScreen::showMainWindow()
{
    setCurrentUserToFile("asd");
    //ui->statusbar->showMessage("Show Main Window");
}

void LoginScreen::updateUsers()
{
    //ui->statusbar->showMessage("Update users");
}

void LoginScreen::setCurrentUserToFile(QString currentUser)
{
    //ui->statusbar->showMessage("Save current user to file");
}

void LoginScreen::getLastUserFromFile(const QVector<QString> &lastUser)
{
    //ui->statusbar->showMessage("Get last user from file");
}

void LoginScreen::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
        showMainWindow();
}

void LoginScreen::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Informacja", "Czy na pewno chcesz zamknąć aplikację?", QMessageBox::Yes|QMessageBox::No);
    if(reply == QMessageBox::Yes)
        event->accept();
    else
        event->ignore();
}

