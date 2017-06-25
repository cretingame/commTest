#ifndef SCIENZCLIENT_H
#define SCIENZCLIENT_H

#include <QObject>
#include <QtNetwork>

class ScienzServer;

class ScienzClient : public QObject
{
    Q_OBJECT
public:
    explicit ScienzClient(QObject *parent = 0);
    explicit ScienzClient(QObject *parent,QTcpSocket * socket);
    virtual void setSocket(QTcpSocket * socket);
    virtual void setServer(ScienzServer * server);
    virtual ~ScienzClient();
signals:

public slots:
    virtual void receiveData();
    virtual void disconnect();
private:
    QTcpSocket * socket;
    ScienzServer * server;

};

#endif // CLIENT_H
