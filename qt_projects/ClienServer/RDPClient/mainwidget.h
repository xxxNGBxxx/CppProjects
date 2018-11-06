#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtWidgets>
#include <QtNetwork>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget() = default;
protected:
    QTcpSocket* m_socket;
    QTextEdit* m_logs;
    QLineEdit* m_line;
    QPushButton* m_sendButton;
    void onConnected();
    void onError(QAbstractSocket::SocketError error);
    void sendData();
};

#endif // MAINWIDGET_H
