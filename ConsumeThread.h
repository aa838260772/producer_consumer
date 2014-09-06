#ifndef _CONSUME_H_
#define _CONSUME_H_

#include <pthread.h>

class Buffer;
class ConsumeThread
{
    public:
        ConsumeThread(Buffer &buffer);

        void start() ;
        static void *threadfun(void *arg);
        void run();
        void join();
    private:
        pthread_t tid_;
        Buffer &buffer_;
};

#endif /*CONSUME_H*/ 
