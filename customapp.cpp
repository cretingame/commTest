//#include <iostream>

#include "customapp.h"


CustomApp::CustomApp() : QProcess::QProcess()
{
    //std::cout << "Applications created" << std::endl;
}

CustomApp::~CustomApp()
{
    //std::cout << "Applications destroyed" << std::endl;
}

/*
void CustomApp::started(QPrivateSignal signal)
{
    std::cout << "Applications started" << std::endl;

}
*/
