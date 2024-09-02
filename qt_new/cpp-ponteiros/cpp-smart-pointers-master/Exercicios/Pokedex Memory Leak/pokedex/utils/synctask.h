#ifndef SYNCTASK_H
#define SYNCTASK_H

#include <functional>
#include <QObject>
#include <QThread>

class SyncTask {
public:
    static void runSync( std::function<void()> callBack );
};

#endif // SYNCTASK_H
