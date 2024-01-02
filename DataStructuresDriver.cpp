#include <iostream>
#include <ctime>
#include "linked-list\LinkedList.cpp"
using namespace std;


int main() 
{
    srand((unsigned) time(0));
    SortedLinkedList* test = new SortedLinkedList();

    Person* Steve = new Person("Steve", 31);
    Person* Rich = new Person("Rich", 28);
    Person* Mike = new Person("Mike", 59);
    Person* Lisa = new Person("Lisa", 55);

    test -> insert(*Steve);
    test -> insert(*Rich);
    test -> insert(*Mike);
    test -> insert(*Lisa);

    test -> print();
    cout << "\n";

    test -> remove(*Steve);
    cout << "After removing Steve:" << "\n" << "\n";
    test -> print();

    test -> makeEmpty();

    delete test;
    delete Steve;
    delete Rich;
    delete Lisa;
    delete Mike;

    return 0;
} //main