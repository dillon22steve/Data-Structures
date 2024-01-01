#include "../Person.cpp"

class Node 
{

private:
    Person* data;
    Node* next;

public:
    Node(Person* newData) {
        data = newData;
        next = nullptr;
    }; //constructor


    void setData(Person* newData) {
        data = newData;
    }; //setData
    Person getData() {
        return *data;
    }; //getData


    Node* getNext() {
        return next;
    }; //getNext

    void setNext(Node* newNext) {
        next = newNext;
    }; //setNext

}; //Node