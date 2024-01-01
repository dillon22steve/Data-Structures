

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