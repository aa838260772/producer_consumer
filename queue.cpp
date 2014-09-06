#include "queue.h"
#include <assert.h>

Queue::Queue()
    :head_(NULL), tail_(NULL), size_(0)
{
}

Queue::~Queue()
{
    clear();
}

void Queue::push(int data){
    NodePtr pt = new Node;
    pt->data_ = data;
    pt->next = NULL;
    if(isempty()){
        tail_ = head_ = pt;
    }else
    {
        tail_->next = pt;
        tail_ = pt;
    }
    size_++;
}

void Queue::pop(){
    assert(!isempty());
    NodePtr pt = head_;
    head_ = head_->next;
    delete pt;
    size_--;
}

int Queue::top() const
{
    assert(!isempty());
    return head_->data_;
}

void Queue::clear()
{
    while(!isempty())
    {
        pop();
    }
}

bool Queue::isempty()const
{
    return head_ == NULL;
}

size_t Queue::getsize() const 
{
    return size_;
}
