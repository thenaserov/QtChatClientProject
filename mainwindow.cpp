#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new ConnectionSocket();
    socket->connect();
    ui->leTypeMessage->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendMessage(QString textToSend)
{
}

void MainWindow::on_btnSend_clicked()
{
    QString textToSend = ui->leTypeMessage->text();
    sendMessage(textToSend);
}

