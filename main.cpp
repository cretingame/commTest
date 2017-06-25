#include <iostream>
//#include <string>
//#include <QProcess>
#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include <QDebug>

#include "customapp.h"
#include "sserver.h"
#include "eventdebug.h"

//using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString program = "ls";
    QStringList arguments;
    arguments << "-la" << "/";


    CustomApp myProcess;
    ScienzServer myServer;
    EventDebug myED;

    myED.connect(&myProcess,SIGNAL(started()),&myED,SLOT(eventCatch()));


    myProcess.start(program,arguments);

    if(!myProcess.waitForFinished())
    {
        return 1; // gérer erreur
    }

    QString result = myProcess.readAll();

    //stdOutputString = "TEST" ;
    std::cout << "TEST ! " << std::endl;
    std::cout << result.toStdString();

    //a.exit();

    return a.exec();
}

