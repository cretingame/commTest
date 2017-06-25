#ifndef SCIENZSERVER_H
#define SCIENZSERVER_H

#include <QObject>
#include <QtNetwork>
#include <QDebug>

class ScienzClient;

class ScienzServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit ScienzServer(QObject *parent = 0);
    virtual ~ScienzServer();
    virtual void addClient(ScienzClient *client);
    virtual void removeClient(ScienzClient *client);
signals:

public slots:
    virtual void newConnection();
private:
    QList<ScienzClient*> clientList;
};

#endif // SERVER_H
