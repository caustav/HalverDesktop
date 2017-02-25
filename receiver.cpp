#include "receiver.h"
#include "serversocket.h"

#include <QDataStream>
#include <QTcpServer>


Receiver::Receiver()
{

}

Receiver::~Receiver()
{
    workerThread.quit();
    workerThread.wait();
}

void Receiver::receive()
{
    qInfo() << "Receiver::receive";
    serverSocket = new ServerSocket();
}

