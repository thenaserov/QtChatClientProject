#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "connectionsocket.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void sendMessage(QString textToSend);

private slots:

    void on_btnSend_clicked();

private:
    Ui::MainWindow *ui;
    ConnectionSocket *socket;
};
#endif // MAINWINDOW_H
