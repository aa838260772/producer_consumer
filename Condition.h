#ifndef _CONDITION_
#define _CONDITION_


#include <pthread.h>

class MutexLock;

class Condition
{
 public:
     Condition(MutexLock &lock);
     ~Condition();
      void wait();
      void notify();
      void notifyall();
      
 private:
      pthread_cond_t cond_;
      MutexLock &lock_;
};


#endif /*H*/ 
