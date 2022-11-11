#include "tcphandler.h"
TCPHandler::TCPHandler(QObject *parent)
    : QObject{parent}
{
    m_tcpServer = new QTcpServer(this);
    connectSignalsSlots();

    if(m_tcpServer->listen(QHostAddress::AnyIPv4,m_port.toInt()) )
    {
        qDebug() << "Server Started";
        m_deviceConnected = true;
    }
    else
    {
        assert("Failed to start TCP Server");
        m_deviceConnected = false;
    }
}

bool TCPHandler::deviceConnected()
{
    return m_deviceConnected;
}


void TCPHandler::connectDevice()
{
    m_tcpSocket = m_tcpServer->nextPendingConnection();
    qDebug() << "Client connected!";
    connect(m_tcpSocket, SIGNAL(readyRead()),this, SLOT(tcpDataRecievedSlot()));
}

void TCPHandler::tcpDataRecievedSlot()
{
    QByteArray byteData{};
    byteData = m_tcpSocket->readAll();
    QString dataStr{ byteData.toHex(' ') };
    while(dataStr.length() > 41)
        dataStr.remove(0,1);

    qDebug() << dataStr;

}

void TCPHandler::connectSignalsSlots()
{
    connect(m_tcpServer, SIGNAL(newConnection()), this ,SLOT(connectDevice()));
}
