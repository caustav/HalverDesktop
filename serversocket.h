#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include "filemeatadata.h"
#include "qtcpsocketext.h"
#include "socketcapsule.h"

#include <qtcpserver.h>


class ServerSocket : public QObject
{
    Q_OBJECT
    public:
        explicit ServerSocket(QObject *parent = 0);

    signals:

        void newConnectionEnd(QTcpSocket* socket);

    public slots:
        void newConnection();
        void onDisconnected(QTcpSocket* sock);
        void onReadyRead(QTcpSocket* sock);

    private:
        QTcpServer* server;
//        QTcpSocket* socket;
        FileMeatadata* fileMetadata;
        bool stateChange;
        QMap<int, QTcpSocketExt*> map;
        int socketCount;

        static int FILE_CHUNK;

        void receiveMetadata(QTcpSocket* sock);
        void receiveContent(QTcpSocket* sock);
};

#endif // SERVERSOCKET_H
