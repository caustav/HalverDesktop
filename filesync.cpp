#include "filesync.h"

FileSync::FileSync()
{

}

void FileSync::doSync()
{

    receiver.receive();

//    sender.reset();
//    sender.setDestinationIPAddress("192.168.0.106");
//    QFile file;
//    sender.sendAsFile(file);
//    sender.runDispatcher();
}
