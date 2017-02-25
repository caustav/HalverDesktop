#ifndef QTCPSOCKETEXT_H
#define QTCPSOCKETEXT_H

#include <qtcpsocket.h>



class QTcpSocketExt : public QObject
{
    Q_OBJECT
    QTcpSocket* qTcpSocket;
public:
    QTcpSocketExt (QTcpSocket*);
    virtual ~QTcpSocketExt();

public slots:
    void slotReadyRead();
    void slotConnected();
    void slotDisconnected();

signals:
    void dataReady (QTcpSocket* socket);
    void newConnection(QTcpSocket* socket);
    void lostConnection(QTcpSocket* socket);
};

#endif // QTCPSOCKETEXT_H
