#include "buffer.h"
#include <iostream>
using namespace std;

Buffer::Buffer(size_t size)
    :queue_(),
    mutex_(),
    full_(mutex_),
    empty_(mutex_),
    size_(size)
{
}

Buffer::~Buffer()
{
}

bool Buffer::isfull() const
{
    mutex_.lock();
    bool ret = (queue_.getsize() >= size_);
    mutex_.unlock();
    return ret;
}

bool Buffer::isempty() const
{
    mutex_.lock();
    bool ret = queue_.isempty();
    mutex_.unlock();
    return ret;
}

void Buffer::produce(int data)
{
    mutex_.lock();
    while(queue_.getsize() >= size_)
    {
        empty_.wait();
    }

    queue_.push(data);
    cout << "produce size " << queue_.getsize() << endl;
    full_.notify();
    mutex_.unlock();
}

int Buffer::consume()
{
    mutex_.lock();
    while(queue_.isempty())
    {
        full_.wait();
    }
    int ret = queue_.top();
    queue_.pop() ;
    cout << "consume size =" << queue_.getsize() << endl;

    empty_.notify();
    mutex_.unlock();
    return ret;
}







