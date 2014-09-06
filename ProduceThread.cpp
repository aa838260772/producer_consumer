#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include "buffer.h"
#include "ProduceThread.h"
using namespace std;
ProduceThread::ProduceThread(Buffer &buffer)
    :tid_(0),
    buffer_(buffer)
{
    ::srand(1111);
}

void ProduceThread::start()
{
    pthread_create(&tid_, NULL, threadfun, this);
}

void *ProduceThread::threadfun(void *arg)
{
    ProduceThread *pt = static_cast<ProduceThread*>(arg);
    pt->run();
    return NULL;
}

void ProduceThread::run()
{
    while(1)
    {
        int data = rand() % 1000;
        cout << "produce a data:" << data << endl; 
        buffer_.produce(data);
        sleep(5);
    }
}

void ProduceThread::join()
{
    pthread_join(tid_, NULL);
}

