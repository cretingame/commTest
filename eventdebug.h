#ifndef EVENTDEBUG_H
#define EVENTDEBUG_H

#include <QObject>
#include <QString>
#include <QDebug>

class EventDebug : public QObject
{
    Q_OBJECT
public:
    explicit EventDebug(QObject *parent = 0);

signals:

public slots:
    void eventCatch();
};

#endif // EVENTDEBUG_H
