#pragma once


#include <QTcpServer>
#include <QObject>

#include <memory>
#include <vector>


class Server: public QObject
{
    Q_OBJECT
public:
    Server(int port);
    ~Server() override;

public slots:
    void onNewConnection();
    void readData() const;
    void clientDisconnected();

private:
    QTcpServer m_server;
    std::vector<QTcpSocket*> m_clients;
};
