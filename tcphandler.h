#ifndef TCPHANDLER_H
#define TCPHANDLER_H
#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTcpServer>
class TCPHandler : public QObject
{
    Q_OBJECT
public:
    explicit TCPHandler(QObject *parent = nullptr);
    void tcpSendCommand(std::string command);

    void connectSignalsSlots();
    bool deviceConnected();
//    void setLogManager(LogManager* logManager);

private:
    QTcpSocket *m_tcpSocket;
    QTcpServer *m_tcpServer;
//    LogManager* m_logManager;
    bool m_deviceConnected;
    QString m_port{"10001"};

public slots:
    void connectDevice();
    void tcpDataRecievedSlot();
signals:
    void rfidDataReceived(QString uid);

};

#endif // TCPHANDLER_H
