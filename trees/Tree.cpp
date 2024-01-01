#include "..\nodes\BSTNode.cpp"
//#include "..\Person.cpp"

class Tree 
{
protected:
    BSTNode* root;

public:
    Tree() {
        root = nullptr;
    }; //constructor



    bool search(Person personToSearch, BSTNode* nodeToSearch) {
        if (nodeToSearch == nullptr) {
            return false;
        } else {
            int compare = (nodeToSearch -> getData().compareTo(personToSearch));
            if (compare == 0) {
                return true;
            } else if (compare < 0) {
                search(personToSearch, nodeToSearch -> getRightChild());
            } else {
                search(personToSearch, nodeToSearch -> getLeftChild());
            }; //if
        } //if
    }; //search



    bool isEmpty() {
        return (root == nullptr);
    }; //isEmpty

    void deleteTree(BSTNode* node) {
        if (node == nullptr) {
            return;
        } else {
            deleteTree(node -> getLeftChild());
            deleteTree(node -> getRightChild());
            delete node;
        }; //if
    }; //makeEmpty

}; //Tree