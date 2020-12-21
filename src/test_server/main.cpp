#include "server/Server.h"

#include <QApplication>

int main (int argc, char** argv)
{
    QApplication a(argc, argv);
    Server server(1234);
    return a.exec();
}
