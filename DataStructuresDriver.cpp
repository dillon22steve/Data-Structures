#include <iostream>
#include "Person.cpp"
#include "linked-list\LinkedList.cpp"
#include "linked-list\SortedLinkedList.cpp"
#include "linked-list\UnsortedLinkedList.cpp"
using namespace std;


int main() 
{
    UnsortedLinkedList* test = new UnsortedLinkedList();
    Person* testPerson = new Person("Steve", 31);
    test -> insert(*testPerson);

    cout << test -> getHead() -> getData().getName();
    delete test;
    delete testPerson;

    return 0;
} //main