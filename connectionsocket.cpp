#include "connectionsocket.h"

ConnectionSocket::ConnectionSocket(QObject *parent)
    : QObject{parent}
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));
    qDebug() << "Connecting,..";
    socket->connectToHost(QHostAddress::LocalHost, 85855);
    if(!socket->waitForDisconnected(1000))
    {
        qDebug() << "Error: " << socket->errorString();
    }
}

void ConnectionSocket::connect()
{
    socket = new QTcpSocket(this);
    socket->connectToHost(QHostAddress::LocalHost, 85855);

    if(socket->waitForConnected(3000))
    {
        qDebug() << "Connected!";

        // send
        socket->write("hello server\r\n\r\n\r\n\r\n");
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        qDebug() << "Reading: " << socket->bytesAvailable();

        qDebug() << socket->readAll();

        socket->close();
    }
    else
    {
        qDebug() << "Not connected!";
    }
    // sent
    // got
    // closed
}

void ConnectionSocket::connected()
{
    qDebug() << "Connected!";
    socket->write("HEAD / HTTP/1.0\r\n\r\n\r\n\r\n");
}

void ConnectionSocket::disconnected()
{
    qDebug() << "Disconnected!";
}

void ConnectionSocket::bytesWritten(qint64 bytes)
{
    qDebug() << "We wrote: " << bytes;
}

void ConnectionSocket::readyRead()
{
    qDebug() << "Reading...";
    qDebug() << socket->readAll();
}
