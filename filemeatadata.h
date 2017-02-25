#ifndef FILEMEATADATA_H
#define FILEMEATADATA_H

#include <QString>



class FileMeatadata
{
public:
    FileMeatadata();

    void setFileName(QString name)
    {
        this->name = name;
    }

    void setFileSize(QString size)
    {
        this->size = size;
    }

    QString getFileName()
    {
        return name;
    }

    QString setFileSize()
    {
        return size;
    }

private:
    QString name;
    QString size;
};

#endif // FILEMEATADATA_H
