#include "ResultsQueue.h"

template <typename Value>
bool ResultsQueue<Value>::isEmpty(){
    return head == nullptr && tail == nullptr;
}

template <typename Value>
Node<Value>* ResultsQueue<Value>::createNode(Value element){
    Node *newNode = new Node;
    newNode->value = element;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    
    return newNode;
}

template <typename Value>
void ResultsQueue<Value>::enqueue(Value element){
    Node *newNode = createNode(element);
    if (isEmpty()){
        head = tail = nullptr;
    }
    else{
        newNode -> prev = tail;
        tail -> next = newNode;
        tail = newNode;
    }
}

template <typename Value>
void ResultsQueue<Value>::popFront(){
    if(!isEmpty()){
        Node * temp = head;

        head = head -> next;

        if(head == nullptr){
            tail = nullptr;
        }
        else{
            head -> prev = nullptr;
        }

        delete temp;
    }   
}

template <typename Value>
Value ResultsQueue<Value>::dequeue(){
    Value first = head -> value;
    popFront();
    return first;
}

template class ResultsQueue<std::vector<Customer*>>;
template class ResultsQueue<Order*>;
template class ResultsQueue<int>;