#include <iostream>
//#include <string>
//#include <QProcess>
#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include <QDebug>

#include "customapp.h"
#include "server.h"
#include "eventdebug.h"

//using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString program = "ls";
    QStringList arguments;
    arguments << "/home/";


    CustomApp myProcess;
    Server myServer;
    EventDebug myED;

    myED.connect(&myProcess,SIGNAL(started()),&myED,SLOT(eventCatch()));


    myProcess.start(program,arguments);

    if(!myProcess.waitForFinished())
    {
        return 1;
    }

    QString result = myProcess.readAll();

    //stdOutputString = "TEST" ;
    std::cout << "TEST ! " << std::endl;
    std::cout << result.toStdString();


    return a.exec();
}

