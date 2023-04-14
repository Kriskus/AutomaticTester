#include "loginscreen.h"
#include "ui_loginscreen.h"

#include <QMessageBox>

LoginScreen::LoginScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginScreen)
{
    ui->setupUi(this);

    connect(ui->pushButtonExit, &QPushButton::clicked, this, &LoginScreen::close);
    connect(ui->pushButtonLogIn, &QPushButton::clicked, this, &LoginScreen::showMainWindow);

    database();

    connect(ui->comboBoxUser, &QComboBox::currentIndexChanged, [this](int id) {currentUserId_ = id;});
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
    connect(queryUser.get(), &QueryUser::sendUsers, this, &LoginScreen::updateUsers);
    queryUser->userSELECT();
}

void LoginScreen::showMainWindow()
{
    if(users_[currentUserId_].get()->checkPassword(ui->lineEditPassword->text())) {
        ui->statusbar->showMessage("Password correct!");
    } else {
        ui->statusbar->showMessage("Password incorrect!");
    }
}

void LoginScreen::updateUsers(const QVector<std::shared_ptr<User> > &users)
{
    users_ = users;
    for(auto user : users_) {
        ui->comboBoxUser->addItem(user.get()->getName());
    }
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

