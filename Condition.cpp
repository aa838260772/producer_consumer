#include "Condition.h"
#include <stdexcept>
#include "MutexLock.h"

using namespace std;

Condition::Condition(MutexLock &lock)
    :lock_(lock)
{
    if(pthread_cond_init(&cond_, NULL)){
        throw std::runtime_error("pthread_cond_init");
    }
}

Condition::~Condition()
{
    if(pthread_cond_destroy(&cond_)){
        throw std::runtime_error("pthread_cond_destroy");
    }
}

void Condition::wait()
{
    if(pthread_cond_wait(&cond_, lock_.getmutexlockptr())){
        throw std::runtime_error("pthread_cond_wait");
    }
}

void Condition::notify()
{
    if(pthread_cond_signal(&cond_)){
        throw std::runtime_error("pthread_cond_signal");
    }
}

void Condition::notifyall()
{
    if(pthread_cond_broadcast(&cond_)){
        throw std::runtime_error("pthread_cond_notifyall");
    }
}



