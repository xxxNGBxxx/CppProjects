#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , m_socket(new QTcpSocket(this))
    , m_logs(new QTextEdit)
    , m_line(new QLineEdit)
    , m_sendButton(new QPushButton("send"))
{
    QGridLayout* grid = new QGridLayout;
    grid->setMargin(5);
    grid->setSpacing(5);
    grid->addWidget(m_logs,0,0,1,2);
    grid->addWidget(m_line,1,0);
    grid->addWidget(m_sendButton, 1, 1);

    setLayout(grid);

    connect(m_socket, &QTcpSocket::connected,this, &MainWidget::onConnected);

    connect(m_socket, QOverload<QTcpSocket::SocketError>::
            of(&QTcpSocket::error), this, &MainWidget::onError);

    connect(m_sendButton, &QPushButton::clicked,this, &MainWidget::sendData);

    m_socket->connectToHost("localhost", 3227);
}

void::MainWidget:: onConnected(){
    QString str("%1:%2");
    str = str.arg(QDateTime::currentDateTime().toString()).arg("localhost");
    m_logs->append(str);
}

void MainWidget::onError(QAbstractSocket::SocketError error){
    QString str("%1: error %2");
    str = str.arg(QDateTime::currentDateTime().toString()).arg(error);
    m_logs->append(str);
    qDebug().noquote() << error;

}

void MainWidget::sendData(){
    QByteArray array;
    QDataStream stream(&array, QIODevice::WriteOnly);
    stream.setVersion(QDataStream::Qt_5_11);

    stream << quint64(0);

    stream << m_line->text();

    stream.device()->seek(0);

    stream << quint64(array.size() - sizeof(quint64));

    m_socket->write(array);

    m_line->clear();
}
