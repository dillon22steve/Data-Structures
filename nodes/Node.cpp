#include "Person.cpp"

class Node 
{

private:
    Person* data;
    Node* next;

public:
    Node(Person* newData) {
        data = newData;
    };


    void setData(Person* newData) {
        data = newData;
    };
    Person* getData() {
        return data;
    };


    Node* getNext() {
        return next;
    };

    void setNext(Node* newNext) {
        next = newNext;
    };

};