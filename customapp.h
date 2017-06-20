#ifndef CUSTOMAPP_H
#define CUSTOMAPP_H

#include <QProcess>

class CustomApp  : public QProcess
{
    Q_OBJECT
public:
    CustomApp();
    ~CustomApp();
//signals:
    //virtual void started(QPrivateSignal signal);
};


#endif // CUSTOMAPP_H
