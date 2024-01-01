

class SortedLinkedList: public LinkedList
{

public:
    void insert(Person person) {
        Node* newNode = new Node(&person);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp -> getNext() != nullptr) {
                Person tempPerson = (temp -> getNext()) -> getData();
                if (person.compareTo(tempPerson) > 0) {
                    temp -> setNext(newNode);
                    return;
                } else if (temp -> getNext() == nullptr) {
                    //This branch will be reached if person is going to be inserted
                    //at the end of the list.
                    temp -> setNext(newNode);
                    return;
                } else {
                    temp = temp -> getNext();
                }; //if
            }; //while
        }; //if
    }; //insert

}; //SortedLinkedList