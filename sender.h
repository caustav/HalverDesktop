#ifndef SENDER_H
#define SENDER_H

#include <QFile>
#include <QThread>

class WorkerThread : public QThread
{
    Q_OBJECT
    void run() {
        QString result;
        emit send();
        emit resultReady(result);
    }
    signals:
        void resultReady(const QString &s);
        void send();
};

class Sender : public QObject
{
    Q_OBJECT

    private:
        QList<WorkerThread*> threads;

        bool sendMetadata();
        bool sendContent();
        bool sendEOF();

    public:
        Sender();

        void reset();
        void sendAsFile(QFile& f);
        void runDispatcher();
        void setDestinationIPAddress(QString ipaddress);

    public slots:
        void send();
};

#endif // SENDER_H
