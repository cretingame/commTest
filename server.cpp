#include "server.h"

Server::Server(QObject *parent) : QTcpServer(parent)
{
    if (!listen()) {
        qDebug() << tr("Unable to start the server: %1.").arg(errorString());
        close();
        return;
    }



    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();

    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }

    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    qDebug() << "Server is running: " << ipAddress << ":" << this->serverPort();

    connect(this,SIGNAL(newConnection()),this,SLOT(linkClient()));

}

Server::~Server()
{

}

void Server::linkClient() {
    //QByteArray block;
    //QDataStream out(&block,QIODevice::WriteOnly);
    //out.setVersion(QDataStream::Qt_5_5);
    //out << "HELLO !";

    qDebug() << "New connection !";
    QTcpSocket * clientConnection = this->nextPendingConnection();
    Client * client = new Client();
    client -> setSocket(clientConnection);
    connect(client,SIGNAL(destroyed(QObject*)),this,SLOT(removeClient(QObject*)));
    addClient(client);
    //clientConnection->write(block);
    //clientConnection->disconnectFromHost();
    //delete clientConnection;
}

void Server::addClient(Client *client)
{
    clientList.append(client);
}

void Server::removeClient(QObject *object)
{
    //TODO
    //Client * client = object;
    //clientList.removeOne(client);
}
