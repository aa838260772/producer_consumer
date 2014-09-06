#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stddef.h>

class Node{
    friend class Queue;
    private:
    int data_;
    Node *next;
};
typedef Node *NodePtr;

class Queue{
    public:
        Queue();
        ~Queue();
        void push(int data);
        void pop();
        int top() const;
        void clear();
        bool isempty()const;
        size_t getsize() const;
    private:
        NodePtr head_;
        NodePtr tail_;
        size_t size_;
};

#endif /*QUEUE_H*/ 
