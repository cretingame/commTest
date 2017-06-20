#include <iostream>
//#include <string>
//#include <QProcess>
#include <QTextStream>
#include <QString>
#include <QDebug>

#include "customapp.h"

//using namespace std;

int main(int argc, char *argv[])
{
    //QTextStream qout(stdout);
    qDebug() << "Salut !";
    //QTextStream cin(stdin);
    //QTextStream cout(stdout);
    //QString stdOutputString = "PU ";

    QString program = "ls";
    QStringList arguments;
    arguments << "/home/";

    //QObject *parent;
    CustomApp myProcess;
    myProcess.start(program,arguments);
    //myProcess.waitForReadyRead();
    //
    if(!myProcess.waitForFinished())
    {
        return 1;
    }

    QString result = myProcess.readAll();

    //stdOutputString = "TEST" ;
    std::cout << "TEST ! " << std::endl;
    std::cout << result.toStdString();
}

