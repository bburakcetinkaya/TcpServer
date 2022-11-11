#include <QCoreApplication>
#include <tcphandler.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TCPHandler tcp;


    return a.exec();
}
