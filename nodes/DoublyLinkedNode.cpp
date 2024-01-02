//#include "Node.cpp"

class DoublyLinkedNode: public Node {

private:
    Node* back;

public:
    Node* getBack() {
        return back;
    }; //getBack
    void setBack(Node* newBack) {
        back = newBack;
    }; //setBack

}; //DoublyLinkedNode