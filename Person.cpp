#include <iostream>
#include <ctime>
using namespace std;


class Person
{

const char idCharacters[70] = {
    '!', '@', '#', '$', '%', '&', '*', '?',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

private:

    std::string name;
    int age;
    char id[26];

public:
    Person() {
        age = 0;
        name = "";
        generateRandomId();
    }; //constructor
    Person(std::string newName, int newAge) {
        name = newName;
        age = newAge;
        generateRandomId();
    }; //constructor



    void generateRandomId() {
        srand(time(NULL));
        int range = 70;
        for (int i = 0; i < 25; i++) {
            int randIndex = (rand() % range);
            id[i] = idCharacters[randIndex];
        }; //for
        id[25] = '\0';
    }; //generateRandomId



    bool equals(Person otherPerson) {
        for (int i = 0; i < 25; i++) {
            if (id[i] != otherPerson.id[i]) {
                return false;
            }; //if
        }; //for

        return true;
    }; //equals



    int compareTo(Person otherPerson) {
        int thisSum = 0;
        int otherSum = 0;
        for (int i = 0; i < 25; i++) {
            thisSum = thisSum + id[i];
            otherSum = otherSum + otherPerson.id[i];
        }; //for

        return (thisSum - otherSum);
    }; //compareTo



    void setName(string newName) {
        name = newName;
    }; //setName
    string getName() {
        return name;
    }; //getName



    void setAge(int newAge) {
        age = newAge;
    }; //setAge
    int getAge() {
        return age;
    }; //getAge



    void setId() {
        generateRandomId();
    }; //setId
    char* getId() {
        return id;
    }; //getIde

}; //Person