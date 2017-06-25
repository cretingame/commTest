#include "sclient.h"
#include "sserver.h"

ScienzClient::ScienzClient(QObject *parent) : QObject(parent)
{

}

ScienzClient::ScienzClient(QObject *parent,QTcpSocket * socket) : QObject(parent)
{
    this->setSocket(socket);
}

void ScienzClient::setSocket(QTcpSocket * socket)
{
    this->socket = socket;
    connect(this->socket,&QTcpSocket::readyRead,this,&ScienzClient::receiveData);
    connect(this->socket,&QTcpSocket::disconnected,this,&ScienzClient::disconnect);
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out << "Hello the new Client !\n";
    this->socket->write(block);
}

void ScienzClient::receiveData()
{
    QByteArray data;
    QJsonDocument jsonDoc;
    data = socket->readAll();
    jsonDoc = QJsonDocument::fromBinaryData(data,QJsonDocument::Validate);
    //TODO validation
    qDebug() << "Received from" << socket->localAddress().toString() << " : " << data;
}

void ScienzClient::disconnect()
{
    qDebug() << "Client " << socket->localAddress().toString() << " disconnected";
    this->~ScienzClient();
}

void ScienzClient::setServer(ScienzServer * server)
{
    this->server = server;
}

ScienzClient::~ScienzClient()
{
    if(this->server != NULL)
    {
        server->removeClient(this);
    }
    qDebug() << "Client destroyed !";
}
