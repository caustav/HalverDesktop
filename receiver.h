#ifndef RECEIVER_H
#define RECEIVER_H

#include "serversocket.h"

#include <C:/Programs/Qt/5.6/msvc2015_64/include/QtCore/qobject.h>

#include <qtcpserver.h>
#include <qthread.h>

class Worker : public QObject
{
    Q_OBJECT
    QThread workerThread;

public slots:
    void doWork() {
        emit resultReady();
    }

signals:
    void resultReady();
};

class Receiver : public QObject
{
    Q_OBJECT
    QThread workerThread;
    public:
        Receiver();
        ~Receiver();
        void receive();

    private:
        ServerSocket* serverSocket;
};

#endif // RECEIVER_H
