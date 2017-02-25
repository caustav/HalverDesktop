#include "filesync.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostInfo>

#include <QNetworkInterface>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStringListModel(this);
    QStringList list;
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
//             qDebug() << address.toString();
             list.append(address.toString());
    }
    model->setStringList(list);
    ui->listViewIps->setModel(model);

    FileSync fileSync;
    fileSync.doSync();



    qDebug() << QHostInfo::localHostName();
}

MainWindow::~MainWindow()
{
    delete ui;
}
