#ifndef FILESYNC_H
#define FILESYNC_H

#include "receiver.h"
#include "sender.h"



class FileSync
{
public:
    FileSync();

    public :
    static const int PORT = 8888;
    static const int READ_METADATA = 0;
    static const int WRITE_FILECONTENT = 1;
    static const int COMMIT_FILE = 2;

    void doSync();

    private:
        Sender sender;
        Receiver receiver;
};

#endif // FILESYNC_H
