#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->checkButton, &QPushButton::clicked, this, &MainWindow::checkEmail);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkEmail() {
    QString email = ui->emailLineEdit->text();

    if (isValidEmail(email))
        ui->resultLabel->setText("Введений текст є дійсною електронною адресою.");
    else
        ui->resultLabel->setText("Введений текст не є дійсною електронною адресою.");
    ui->emailLineEdit->setFocus();
}

bool MainWindow::isValidEmail(const QString& email) {
    QRegularExpression pattern("^\\w+[\\w.-]*@[\\w.-]+\\.\\w+$");
    QRegularExpressionMatch match = pattern.match(email);
    return match.hasMatch();
}
