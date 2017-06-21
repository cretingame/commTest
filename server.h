#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork>
//#include <QTcpServer>
#include <QDebug>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    virtual ~Server();
signals:

public slots:
    void reply();
};

#endif // SERVER_H
