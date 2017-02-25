#include "sender.h"

Sender::Sender()
{

}

void Sender::reset()
{
    threads.clear();
}

void Sender::sendAsFile(QFile& f)
{
    WorkerThread* th = new WorkerThread();
    threads.append(th);
}

void Sender::runDispatcher()
{
    for (int i = 0;  i < threads.count(); i ++)
    {
        WorkerThread* th = threads.at(i);
        connect(th, SIGNAL(send()), this, SLOT(send()));
        th->start();
        th->wait();
    }
}

void Sender::setDestinationIPAddress(QString ipaddress)
{

}

//void Sender::startWorkInAThread()
//{
//    WorkerThread *workerThread = new WorkerThread(this);
//    connect(workerThread, SIGNAL(resultReady(QString)), this, SLOT(handleResults(QString)));
//    connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
//    workerThread->start();
//}

void Sender::send()
{
    if (sendMetadata())
    {
        if (sendContent())
        {
            if (sendEOF())
            {

            }
        }
    }
}

bool Sender::sendMetadata()
{
    return false;
}

bool Sender::sendContent()
{
    return false;
}

bool Sender::sendEOF()
{
    return false;
}
