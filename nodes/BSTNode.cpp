//#include "Node.cpp"


class BSTNode: public Node {
private:
    BSTNode* leftChild;
    BSTNode* rightChild;

public:
    using Node::Node;


    BSTNode* getLeftChild() {
        return leftChild;
    }; //getLeftChild
    void setLeftChild(BSTNode* newLeft) {
        leftChild = newLeft;
    }; //setRightChild



    BSTNode* getRightChild() {
        return rightChild;
    }; //getRightChild
    void setRightChild(BSTNode* newRight) {
        rightChild = newRight;
    }; //setRightChild

}; //BSTNode