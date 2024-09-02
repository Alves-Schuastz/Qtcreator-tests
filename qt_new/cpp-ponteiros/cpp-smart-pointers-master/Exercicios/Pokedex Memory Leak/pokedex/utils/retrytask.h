#ifndef RETRYTASK_H
#define RETRYTASK_H

#include <functional>

class RetryTask {
public:
    static void exec( std::function<bool()> callBack, const int nrMaxRetry = 3 );
};

#endif // RETRYTASK_H
