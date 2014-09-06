#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <vector>
#include "buffer.h"
#include "ProduceThread.h"
#include "ConsumeThread.h"

class Factory
{
    public:
        Factory(size_t bufferSize_,
                size_t producerNum,
                size_t consumerNum);
        void start();
    private:
        Buffer buffer_;
        size_t producerNum_;
        size_t consumerNum_;
        std::vector<ProduceThread> produceThreads_;
        std::vector<ConsumeThread> consumeThreads_;
};
#endif /*FACTORY_H*/ 
