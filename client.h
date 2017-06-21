#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    explicit Client(QObject *parent,QTcpSocket * socket);
    virtual void setSocket(QTcpSocket * socket);
signals:

public slots:
    virtual void receiveData();
    virtual void disconnect();
private:
    QTcpSocket * socket;

};

#endif // CLIENT_H
