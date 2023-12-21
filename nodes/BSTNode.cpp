#include "Node.cpp"

class BSTNode: public Node {
private:
    BSTNode* leftChild;
    BSTNode* rightChild;

public:
    BSTNode* getLeftChild() {
        return leftChild;
    };

    BSTNode* getRightChild() {
        return rightChild;
    };

};