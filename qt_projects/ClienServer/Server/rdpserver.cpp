#include "rdpserver.h"

RDPServer::RDPServer(quint16 port, QObject *parent)
    : QObject (parent)
    , m_tcpServer(new QTcpServer(this))
    , m_nextBlockSize(0)
{
    connect(m_tcpServer, &QTcpServer::newConnection,this,
                            &RDPServer::onNewConnection);

    if(!m_tcpServer->listen(QHostAddress::AnyIPv4, port)){
        qDebug().noquote() << "Unable to start the server"
                           << m_tcpServer->errorString();
    }
}

void RDPServer::onNewConnection(){
    QTcpSocket* socket = m_tcpServer->nextPendingConnection();
    connect(socket, &QTcpSocket::disconnected,socket,
                            &QTcpSocket::deleteLater);
    connect(socket, &QTcpSocket::readyRead, this,
                            &RDPServer::onReadyRead);
}

void RDPServer::onReadyRead(){
    QTcpSocket* socket = qobject_cast<QTcpSocket* > (sender());
    QDataStream stream(socket);
    stream.setVersion(QDataStream::Qt_5_11);

    for(; ; ){
        if(!m_nextBlockSize){
            if(socket->bytesAvailable() < sizeof (quint64)){
                break;
            }
            stream >> m_nextBlockSize;
        }
        if(socket->bytesAvailable() < m_nextBlockSize){
            break;
        }

        QString text;
        stream >> text;
        qDebug().noquote() << text;
        m_nextBlockSize = 0;
    }
}
