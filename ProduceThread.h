#ifndef _PRODUCE_H_
#define _PRODUCE_H_

#include <pthread.h>

class Buffer;

class ProduceThread
{
    public:
        ProduceThread(Buffer &buffer);

        void start();
        static void *threadfun(void *arg);
        void run();
        void join();
private:
        pthread_t tid_;
        Buffer &buffer_;
};
#endif /*PRODUCE_H*/ 
