#ifndef CONNECTIONSOCKET_H
#define CONNECTIONSOCKET_H

#include <QObject>
#include <QTcpSocket>

class ConnectionSocket : public QObject
{
    Q_OBJECT

public:
    explicit ConnectionSocket(QObject *parent = nullptr);
    void connect();

private:
    QTcpSocket *socket;
    void test();

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

signals:
};

#endif // CONNECTIONSOCKET_H
