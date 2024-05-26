#ifndef RESULTSQUEUE_H
#define RESULTSQUEUE_H

#include "Includes.h"
#include "Constants.h"
#include "Customer.h"
#include "Order.h"
using namespace std;

template <typename Value>
struct Node {
    Value value;
    struct Node<Value> * next;
    struct Node<Value> * prev;
};

template <typename Value>
class ResultsQueue{
protected:
    Node<Value> *head;
    Node<Value> *tail;
    Node<Value>* createNode(Value);
    void popFront();

public:
    ResultsQueue():
        head(nullptr),
        tail(nullptr){};

    void enqueue (Value);
    
    Value dequeue();
    bool isEmpty();

    ~ResultsQueue(){
        while (!isEmpty()){
            popFront();
        }
    };
};


#endif //RESULTSQUEUE_H