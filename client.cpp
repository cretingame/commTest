#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{

}

Client::Client(QObject *parent,QTcpSocket * socket) : QObject(parent)
{
    this->setSocket(socket);
}

void Client::setSocket(QTcpSocket * socket)
{
    this->socket = socket;
    connect(this->socket,&QTcpSocket::readyRead,this,&Client::receiveData);
    connect(this->socket,&QTcpSocket::disconnected,this,&Client::disconnect);
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out << "A new Client !\n";
    this->socket->write(block);
}

void Client::receiveData()
{
    qDebug() << "Received from" << socket->localAddress().toString() << " : " << socket->readAll();
}

void Client::disconnect()
{
    qDebug() << "Client " << socket->localAddress().toString() << " disconnected";
}
