#include <iostream>
#include "Person.cpp"
using namespace std;


int main() 
{
    Person::initSpecialChars();
    //cout << "InitSpecialChars finished\n" << endl;
    //Person::initIdChars();
    //Person* test = new Person();

    // cout << "Id equals: " << (*test).getId() << "\n" <<endl;

    // delete test;

    cout << "Hello World\n" << endl;
} //main