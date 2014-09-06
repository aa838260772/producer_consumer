#ifndef _BUFFER_H_
#define _BUFFER_H_

#include "queue.h"
#include "MutexLock.h"
#include "Condition.h"

class Buffer
{
    public:
        Buffer(size_t size);
        ~Buffer();

        bool isempty() const;
        bool isfull() const;

        void produce(int data);
        int consume(); 

    private:
        Queue queue_;
        mutable MutexLock mutex_;

        Condition full_;
        Condition empty_;
        size_t size_;
};

#endif /*BUFFER_H*/ 
