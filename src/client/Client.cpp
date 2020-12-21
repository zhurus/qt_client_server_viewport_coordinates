#include "client/Client.h"

#include "Viewport.h"
#include <QHBoxLayout>


Client::Client(int port, QWidget *parent)
    : QWidget(parent),
      m_port(port)
{
    m_scene = new QGraphicsScene(0, 0, 400, 400, this);
    m_viewport = new Viewport(m_scene, this);
    m_portInp = new QLineEdit(QString::number(m_port), this);
    m_connectBtn = new QPushButton("Connect", this);
    m_socketStateInfo = new QLabel("Not connected", this);

    QHBoxLayout* l = new QHBoxLayout(this);
    QVBoxLayout* vl = new QVBoxLayout();
    vl->addWidget(m_portInp);
    vl->addWidget(m_connectBtn);
    vl->addWidget(m_socketStateInfo);

    l->addWidget(m_viewport);
    l->addLayout(vl);

    m_socket = new QTcpSocket(this);
//    connect(m_socket, &QTcpSocket::stateChanged,
//            this, &Client::socketStateChanged);
    connect(m_socket, &QTcpSocket::disconnected,
            this, &Client::disconnected);
    connect(m_socket, &QTcpSocket::connected,
            this, &Client::connected);

    connect(m_connectBtn, &QPushButton::clicked,
            this, &Client::connectToServer);
    connect(m_viewport, &Viewport::mouseClicked,
            this, &Client::sendCoordinates);
}


void Client::connectToServer() const
{
    m_socket->connectToHost("localhost", m_port);
}

void Client::sendCoordinates(const QPoint& point)
{
    int s = m_socket->state();
    if(s == QTcpSocket::SocketState::ConnectedState) {
        QByteArray ba;
        QDataStream out(&ba, QIODevice::WriteOnly);
        out << point.x() << point.y();
        m_socket->write(ba);
    }
}

//void Client::socketStateChanged(const QAbstractSocket::SocketState state)
//{
//    QString text;
//    switch (state) {
//    case QAbstractSocket::SocketState::ConnectedState:
//        text = "connected";
//        break;
//    case QAbstractSocket::SocketState::UnconnectedState:
//        text = "unconnected";
//        break;
//    case QAbstractSocket::SocketState::ClosingState:
//        text = "closing";
//        break;
//    case QAbstractSocket::SocketState::BoundState:
//        text = "bound";
//        break;
//    default:
//        break;
//    }
//    m_socketStateInfo->setText(text);
//}

void Client::disconnected()
{
    m_socketStateInfo->setText("disconnected");
}

void Client::connected()
{
    m_socketStateInfo->setText("connected");
}

int Client::getPort() const
{
    return m_port;
}

void Client::setPort(int port)
{
    m_port = port;
}
