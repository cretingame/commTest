#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork>
//#include <QTcpServer>
#include <QDebug>
#include "client.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    virtual ~Server();
    virtual void addClient(Client *client);
    virtual void removeClient();
signals:

public slots:
    virtual void newConnection();
private:
    QList<Client*> clientList;
};

#endif // SERVER_H
