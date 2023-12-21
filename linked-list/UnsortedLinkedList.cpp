#include "nodes/Node.cpp"

class UnsortedLinkedList
{
private:
    Node* head;

public :
    UnsortedLinkedList() {
        head = nullptr;
    }; //constructor



    Node* get(Person personToGet) {
        if (isEmpty() == true) {
            return nullptr;
        } else {
            Node* tempPtr = head;
            while (tempPtr != nullptr) {
                Person* tempPerson = (*tempPtr).getData();
                if ((*tempPerson).equals(personToGet)) {
                    return tempPtr;
                }; //if

                tempPtr = (*tempPtr).getNext();
            }; //while

            //If the method has reached this point, the data is not present in the list.
            return nullptr;
        }; //if
    }; //get

    Node* get(int index) {
        if (head == nullptr) {
            return nullptr;
        } else {
            Node* temp = head;
            int i = 0;
            while (temp != nullptr && i <= index) {
                temp = (*temp).getNext();
                i = i + 1;
                if (i > index) {
                    return nullptr;
                }; //if
            }; //while

        return temp;
        }; //if
    }; //get



    void insert(Person data) {
        if (head == nullptr) {
            head = new Node(&data);
        } else {
            Node* temp = new Node(&data);
            temp -> setNext(head);
            head = temp;
        }; //if
    }; //insert



    bool search(Person personToSearchFor) {
        Node* temp = head;
        while (temp != nullptr) {
            Person* tempPerson = (*temp).getData();
            if ((*tempPerson).equals(personToSearchFor)) {
                return true;
            }; //if
        }; //while

        return false;
    }; //search



    void remove(Person personToDelete) {
        if (head == nullptr) {
            return;
        } else if ((*(*head).getData()).equals(personToDelete)) {
            //if the head node contains the data we want to delete, then set head to
            //head's next pointer and delete the original head.
            Node* temp = (*head).getNext();
            delete head;
            head = temp;
        } else {
            Node* temp = head;
            while ((*temp).getNext() != nullptr) {
                //if the person stored in temp's next pointer equals the person we
                //are looking to delete, then link temp with its next next pointer
                //and delete the original next pointer.
                Person* tempPerson = (*((*temp).getNext())).getData();
                if ((*tempPerson).equals(personToDelete)) {
                    Node* tempNext = (*temp).getNext();
                    (*temp).setNext((*tempNext).getNext());
                    delete tempNext;
                }; //if
            }; //while
        }; //if
    }; //remove



    void makeEmpty() {
        Node* temp;
        while (temp != nullptr) {
            temp = head;
            head = head -> getNext();
            delete temp;
        }; //while
    }; //makeEmpty
    bool isEmpty() {
        return (head == nullptr);
    }; //isEmpty



    Node* getHead() {
        return head;
    }; //getHead

}; //UnsortedLinkedList