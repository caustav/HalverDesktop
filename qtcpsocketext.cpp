#include "qtcpsocketext.h"

QTcpSocketExt::QTcpSocketExt(QTcpSocket * socket)
    : qTcpSocket (socket)
{
    connect(qTcpSocket, SIGNAL(readyRead()), this, SLOT (slotReadyRead()));
    connect(qTcpSocket, SIGNAL(connected()), this, SLOT(slotConnected()));
    connect(qTcpSocket, SIGNAL(disconnected()), this, SLOT(slotDisconnected()));
}

QTcpSocketExt::~QTcpSocketExt()
{

}

void QTcpSocketExt::slotReadyRead()
{
    emit dataReady(this->qTcpSocket);
}

void QTcpSocketExt::slotConnected()
{
    emit newConnection(this->qTcpSocket);
}

void QTcpSocketExt::slotDisconnected()
{
    emit lostConnection(this->qTcpSocket);
}

