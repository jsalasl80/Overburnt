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
    struct Node * next;
    struct Node * prev;
};

template <typename Value>
class ResultsQueue{
protected:
    Node *head;
    Node *tail;
    Node<Value>* createNode(Value);
    void popFront();

public:
    ResultsQueue():
        head(nullptr),
        tail(nullptr){};

    void enqueue (Value element);
    
    Value dequeue();
    bool isEmpty();

    ~ResultsQueue(){
        while (!isEmpty()){
            popFront();
        }
    };
};

#endif //RESULTSQUEUE_H