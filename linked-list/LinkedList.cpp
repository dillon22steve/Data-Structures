#include "../nodes/Node.cpp"


class LinkedList
{
protected:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }; //constructor



    void remove(Person personToDelete) {
        if (isEmpty()) {
            return;
        } else if ((head -> getData()).equals(personToDelete)) {
            Node* tempPtr = head -> getNext();
            delete head;
            head = tempPtr;
        } else {
            Node* temp = head;
            Node* next =  temp -> getNext();
            while (next != nullptr) {
                //if temp's nextPtr contains the person that we want to delete, then link temp
                //with temp's next next node and delete the original next node.
                bool equal = personToDelete.equals(next -> getData());
                if (equal) {
                    temp -> setNext(next -> getNext());
                    delete next;
                    return;
                } else {
                    temp = temp -> getNext();
                    next = next -> getNext();
                }; //if
            }; //while
        }; //if
    }; //remove



    bool search(Person personToSearch) {
        Node* temp = head;
        while (temp != nullptr) {
            if ((temp -> getData()).equals(personToSearch)) {
                return true;
            }; //if
        }; //while

        return false;
    }; //search



    Node* get(Person personToGet) {
        if (isEmpty() == true) {
            return nullptr;
        } else {
            Node* tempPtr = head;
            while (tempPtr != nullptr) {
                //if the person stored in tempPtr equals the person to get, return tempPtr. 
                if ((tempPtr -> getData()).equals(personToGet)) {
                    return tempPtr;
                }; //if

                tempPtr = (*tempPtr).getNext();
            }; //while

            //If the method has reached this point, the data is not present in the list.
            return nullptr;
        }; //if
    }; //get

    Node* get(int index) {
        if (isEmpty()) {
            return nullptr;
        } else {
            Node* temp = head;
            int i = 0;
            while (temp != nullptr && i <= index) {
                temp = temp -> getNext();
                i = i + 1;
                if (i > index) {
                    return nullptr;
                }; //if
            }; //while

        //This will either return the node at index or return a null pointer if index is
        //greater than the length of the list.
        return temp;
        }; //if
    }; //get
    



    bool isEmpty() {
        return (head == nullptr);
    }; //isEmpty

    void makeEmpty() {
        Node* temp;
        while (head != NULL) {
            temp = head;
            head = head -> getNext();
            delete temp;
        }; //while
    }; //makeEmpty


    void print() {
        Node* temp = head;
        while (temp != NULL) {
            Person tempData = (*temp).getData();
            cout << "Name: " << tempData.getName() << ", age: " << tempData.getAge() << ", id: " << tempData.getId() << "\n";

            temp = (*temp).getNext();
        }; //while
    }; //print



    Node* getHead() {
        return head;
    }; //getHead

}; //LinkedList






class UnsortedLinkedList: public LinkedList
{

public :

    void insert(Person data) {
        if (head == nullptr) {
            head = new Node(&data);
        } else {
            Node* temp = new Node(&data);
            temp -> setNext(head);
            head = temp;
        }; //if
    }; //insert

}; //UnsortedLinkedList







class SortedLinkedList: public LinkedList
{

public:
    void insert(Person personToInsert) {
        Node* newNode = new Node(&personToInsert);
        if (isEmpty()) {
            head = newNode;
        } else if (personToInsert.compareTo(head -> getData()) < 0) {
            newNode -> setNext(head);
            head = newNode;
        } else {
            Node* temp = head;
            while (temp -> getNext() != nullptr) {
                Person tempPerson = (temp -> getNext()) -> getData();
                if (personToInsert.compareTo(tempPerson) < 0) {
                    newNode -> setNext(temp -> getNext());
                    temp -> setNext(newNode);
                    return;
                } else {
                    temp = temp -> getNext();
                }; //if
            }; //while


            //This will be reached if the person needs to be inserted at the end of
            //the list
            if (personToInsert.compareTo(temp -> getData()) > 0) {
                newNode -> setNext(temp -> getNext());
                temp -> setNext(newNode);
            } else {
                temp -> setNext(newNode);
            } //if
        }; //if
    }; //insert

}; //SortedLinkedList