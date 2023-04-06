#include "loginscreen.h"
#include "./ui_loginscreen.h"

#include "database/database.h"

LoginScreen::LoginScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginScreen)
{
    ui->setupUi(this);

    QScopedPointer<Database> db(new Database());
    if(db->connect()) {
        ui->statusbar->showMessage("Połączono z bazą danych");
    } else {
        ui->statusbar->showMessage("Nie udało się połączyć z bazą danych");
    }
}

LoginScreen::~LoginScreen()
{
    delete ui;
}

