#include <QApplication>
#include "rdpserver.h"
int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    RDPServer server(3227);

    return a.exec();
}
