#pragma once


#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

#include <QTcpSocket>


class Viewport;

class Client : public QWidget
{
	Q_OBJECT
    using Scene_t = QGraphicsScene;
public:
    explicit Client(int port = 1234, QWidget *parent = nullptr);
	~Client() override = default;

    int getPort() const;
    void setPort(int port);

public slots:
    void connectToServer() const;
	void sendCoordinates(const QPoint&point);
//    void socketStateChanged(const QAbstractSocket::SocketState state);
    void disconnected();
    void connected();

private:
    Viewport* m_viewport;
    Scene_t* m_scene;
    QLineEdit* m_portInp;
    QPushButton* m_connectBtn;
    QLabel* m_socketStateInfo;

    QTcpSocket* m_socket;
    int m_port;
    bool isConnected = {false};
};
