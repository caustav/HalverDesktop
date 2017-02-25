#include "serversocket.h"
#include <qdatastream.h>
#include <qfile.h>

int ServerSocket::FILE_CHUNK;

ServerSocket::ServerSocket(QObject *parent) :
    QObject(parent)
{
    FILE_CHUNK = 1024;

    server = new QTcpServer(this);

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    if(! server->listen(QHostAddress::Any, 8888))
    {
        qDebug() << "Server could not start";
    }
    else
    {
        qDebug() << "Server started!";
    }

    stateChange = false;
    socketCount = 0;
}

void ServerSocket::newConnection()
{
    QTcpSocketExt* socketExt = new QTcpSocketExt(server->nextPendingConnection());
    map.insert(socketCount, socketExt);
    QTcpSocketExt *sckt = map[socketCount];
    connect(sckt, SIGNAL(dataReady(QTcpSocket*)), this, SLOT(onReadyRead(QTcpSocket*)));
    connect(sckt, SIGNAL(lostConnection(QTcpSocket*)), this, SLOT(onDisconnected(QTcpSocket*)));

    stateChange = true;
    socketCount ++;
}

void ServerSocket::onReadyRead(QTcpSocket* sock)
{
    if (stateChange == false)
    {
        receiveContent(sock);
    }
    else
    {
        char* buffer = new char[1];
        sock->read(buffer, 1);
        int res = buffer[0];
        qDebug(QString::number(res).toLatin1().data());

        if (res == 1)
        {
            fileMetadata = new FileMeatadata();
            receiveMetadata(sock);
        }else if (res == 3)
        {
            fileMetadata = NULL;
            //receiveContent(socket, fileMetadata);
        } else if (res == 2)
        {
            receiveContent(sock);
        }
    }
    stateChange = false;
}

void ServerSocket::onDisconnected(QTcpSocket* sock)
{
    disconnect(sock, SIGNAL(disconnected()));
    disconnect(sock, SIGNAL(readyRead()));
    sock->deleteLater();
}

void ServerSocket::receiveMetadata(QTcpSocket* sock)
{
    char* arrayMetadata = new char[1024];
    int dataRead  = sock->read(arrayMetadata, 1024);
    QChar sep(',');
    QString str(arrayMetadata);
    str = str.trimmed();
    QStringList fileInfo = str.split(sep);
    QString fName = fileInfo[0];
    QString fSize = fileInfo[1];
    fSize = fSize.left(dataRead - fName.length() - 1);
    fileMetadata->setFileName(fName);
    fileMetadata->setFileSize(fSize);
}

void ServerSocket::receiveContent(QTcpSocket* sock)
{
    //SocketCapsule* capsule = map[sock];
    //capsule->id = 1;

    QString filePath = "E:\\Temp\\New\\" + fileMetadata->getFileName();
    QFile file(filePath);
    file.open(QIODevice::ReadWrite| QIODevice::Append);
    QDataStream out(&file);

    while(sock->bytesAvailable() > 0){
        char* fileContent = new char[FILE_CHUNK];
        int bytesRead = 0;
        int bufferLength = 0;
        while(bufferLength < FILE_CHUNK)
        {
            bytesRead = sock->read(fileContent, FILE_CHUNK);
            if (bytesRead == -1 || bytesRead == 0){
                break;
            }
            bufferLength += bytesRead;
        }
        out.writeRawData(fileContent, bufferLength);
        sock->flush();
        sock->waitForBytesWritten();
    }

}
