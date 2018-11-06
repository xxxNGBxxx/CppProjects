#ifndef RDPSERVER_H
#define RDPSERVER_H

#include <QtWidgets>
#include <QtNetwork>
class RDPServer: public QObject{
    Q_OBJECT
public:
    explicit RDPServer(quint16 port, QObject *parent = nullptr);

protected:
    QTcpServer* m_tcpServer;
    void onNewConnection();
    void onReadyRead();

private:
    quint64 m_nextBlockSize;
};

#endif // RDPSERVER_H
