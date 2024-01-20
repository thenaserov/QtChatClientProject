 #include "mainwindow.h"

#include <QApplication>
#include "connectionsocket.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    ConnectionSocket socket;
    socket.test();
    return a.exec();
}
