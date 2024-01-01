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
        if (head == nullptr) {
            return;
        } else if ((head -> getData()).equals(personToDelete)) {
            Node* tempPtr = head -> getNext();
            delete head;
            head = tempPtr;
            delete tempPtr;
        } else {
            Node* temp = head;
            while (temp -> getNext() != nullptr) {
                //if temp's nextPtr contains the person that we want to delete, then link temp
                //with temp's next next node and delete the original next node.
                if (personToDelete.compareTo((temp -> getNext()) -> getData())) {
                    temp -> setNext((temp -> getNext()) -> getNext());
                    delete (temp -> getNext());
                    delete temp;
                    return;
                } else {
                    temp = temp -> getNext();
                }; //if
            }; //while

            //if this line is reached, the person is not present in the list.
            delete temp;
        }; //if
    }; //remove



    bool search(Person personToSearch) {
        Node* temp = head;
        while (temp != nullptr) {
            if ((temp -> getData()).equals(personToSearch)) {
                delete temp;
                return true;
            }; //if
        }; //while

        delete temp;
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
            delete tempPtr;
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
                temp = temp -> getNext();
                i = i + 1;
                if (i > index) {
                    delete temp;
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
        while (temp != nullptr) {
            temp = head;
            head = head -> getNext();
            delete temp;
        }; //while
    }; //makeEmpty



    Node* getHead() {
        return head;
    }; //getHead

}; //LinkedList