#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QDialog>
#include <QHostAddress>
#include <QTcpSocket>
#include <QFile>
#include <QElapsedTimer>

namespace Ui {
class TcpClient;
}

class TcpClient : public QDialog
{
    Q_OBJECT

public:
    explicit TcpClient(QWidget *parent = nullptr);
    ~TcpClient();

    void setHostAddress(QHostAddress address);
    void setFileName(QString fileName);

protected:
    void closeEvent(QCloseEvent *);

private slots:
    void on_tcpClientCancleBtn_clicked();
    void on_tcpClientCloseBtn_clicked();

    void newConnect();
    void readMessage();
    void displayError(QAbstractSocket::SocketError);

private:
    Ui::TcpClient *ui;

    QTcpSocket * tcpClient_socket;
    quint16 blockSize;
    QHostAddress hostAddress;
    qint16 tcpPort;

    qint64 TotalBytes;
    qint64 bytesReceived;
    qint64 bytesToReceive;
    qint64 fileNameSize;
    QString fileName;
    QFile * localFile;
    QByteArray inBlock;

    QElapsedTimer time;

};

#endif // TCPCLIENT_H
