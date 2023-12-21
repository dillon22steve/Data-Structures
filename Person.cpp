#include <random>
#include <iostream>
using namespace std;


class Person {

static char idCharacters[70];
static char specialChars[8];

private:

    char* name;
    int age;
    char id[25];

public:
    Person() {
        age = 0;
    }; //constructor
    Person(char* newName, int newAge) {
        name = newName;
        age = newAge;
        generateRandomId();
    }; //constructor


    //Initializes the array of special characters that will be added to the idCharacters array.
    static void initSpecialChars() {
        specialChars[0] = '!'; 
        specialChars[1] = '@'; 
        specialChars[2] = '#';
        specialChars[3] = '$';
        specialChars[4] = '%';
        specialChars[5] = '&';
        specialChars[6] = '*';
        specialChars[7] = '?';
    }; //initSpecialChars


    //Initializes the array of characters that will be randomly selected from to generate
    //the person object's unique id.
    static void initIdChars() {
        //adds the numbers 1 through 9 to the character array.
        for (int i = 0; i < 9; i++) {
            idCharacters[i] = i;
        }; //for

        int index = 9;
        char initialChar = 'a';

        //Adds the lowercase letters to the character array.
        for (int i = 0; i < 26; i++) {
            char charToAdd = initialChar + i;
            idCharacters[index] = charToAdd;
            index++;
        }; //for

        initialChar = 'A';
        //Adds the uppercase letters to the character array.
        for (int i = 0; i < 26; i++) {
            char charToAdd = initialChar + i;
            idCharacters[index] = charToAdd;
            index++;
        }; //for

        //Adds the special characters to the overall character array.
        // for (int i = 0; i < 9; i++) {
        //     char charToAdd = specialChars[i];
        //     idCharacters[index] = charToAdd;
        //     index++;
        // }; //for
    }; //initIdChars




    void generateRandomId() {
        int range = 70;
        for (int i = 0; i < 25; i++) {
            int randIndex = (rand() % range);
            id[i] = idCharacters[randIndex];
        }; //for
    }; //generateRandomId



    bool equals(Person otherPerson) {
        for (int i = 0; i < 25; i++) {
            if (id[i] != otherPerson.id[i]) {
                return false;
            }; //if
        }; //for

        return true;
    }; //equals



    void setName(char* newName) {
        name = newName;
    }; //setName
    char* getName() {
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