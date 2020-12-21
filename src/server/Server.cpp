#include "server/Server.h"

#include <QTcpSocket>
#include <QDataStream>
#include <iostream>


Server::Server(int port): QObject()
{
    m_server.listen(QHostAddress::Any, port);
    std::cout << "Server is listening the port " << port << std::endl;
    connect(&m_server, &QTcpServer::newConnection,
            this, &Server::onNewConnection);
}

Server::~Server()
{}

void Server::onNewConnection()
{
    std::cout << "new client connected" << std::endl;
    QTcpSocket* pSocket{m_server.nextPendingConnection()};
    m_clients.push_back(pSocket);
    connect(pSocket, &QTcpSocket::readyRead,
            this, &Server::readData);
    connect(pSocket, &QTcpSocket::disconnected,
            this, &Server::clientDisconnected);
}

void Server::readData() const
{
    auto pClient = qobject_cast<QTcpSocket*>(sender());
    while(pClient->bytesAvailable() < 2 * sizeof(int)) {}
    QDataStream stream(pClient);
    int x, y;
    stream >> x;
    stream >> y;
    std::cout << "(" << x << ","<< y << ")" << std::endl;
}

void Server::clientDisconnected()
{
    QTcpSocket* pClient = static_cast<QTcpSocket*>(sender());
    auto client_it = std::find_if(m_clients.begin(), m_clients.end(),
        [pClient](QTcpSocket* iteratee)->bool{
            return iteratee == pClient;
        });
    m_clients.erase(client_it);
    pClient->deleteLater();
    std::cout << "client disconnected" << std::endl;
}
