#include "eventdebug.h"

EventDebug::EventDebug(QObject *parent) : QObject(parent)
{

}

void EventDebug::eventCatch()
{
    qDebug() << "msg";
}
