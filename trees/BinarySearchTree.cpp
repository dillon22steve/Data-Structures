#include "..\nodes\BSTNode.cpp"
#include "Tree.cpp"
//#include "..\Person.cpp"

class BinarySearchTree: public Tree
{
private:
    bool isLeafNode(BSTNode* nodeToCheck) {
        if (nodeToCheck -> getLeftChild() == nullptr && nodeToCheck -> getRightChild() == nullptr) {
            return true;
        } else {
            return false;
        }; //if
    } //isLeafNode
    bool nodeHasOneChild(BSTNode* nodeToCheck) {
        if (nodeToCheck -> getLeftChild() == nullptr || nodeToCheck -> getRightChild() == nullptr) {
            return true;
        } else {
            return false;
        }; //if
    }; //nodeHasOneChild


    void deleteNodeWithTwoChildren(BSTNode* nodeToDelete) {
        BSTNode* hightestLeftSubtree = getHighestFromLeftSubtree(nodeToDelete -> getLeftChild());
        Person replacement = hightestLeftSubtree -> getData();
        nodeToDelete -> setData(&replacement);
        remove(replacement, (nodeToDelete -> getLeftChild()));
    }; //deleteNodeWithTwoChildren
    BSTNode* getHighestFromLeftSubtree(BSTNode* node) {
        while (node -> getRightChild() != nullptr) {
            node = node -> getRightChild();
        }; //while
        return node;
    }; //getHighestFromLeftSubtree



public:
    void insert(Person personToInsert, BSTNode* nodeToCheck) {
        if (root == nullptr) {
            root = new BSTNode(&personToInsert);
        } else {
            int compare = (nodeToCheck -> getData().compareTo(personToInsert));
            if (compare == 0) {
                //if the item is already present in the tree, return so that the tree
                //does not conatin any duplicates.
                return;
            } else if (compare < 0) {
                //if personToInsert is greater than nodeToCheck, then check the right side.
                //if the right child is null, insert. If not, then recursively call insert
                //with the right child as nodeToCheck.
                if (nodeToCheck -> getRightChild() == nullptr) {
                    nodeToCheck -> setRightChild(new BSTNode(&personToInsert));
                } else {
                    insert(personToInsert, nodeToCheck -> getRightChild());
                }; //if
            } else {
                //if personToInsert is less than nodeToCheck, then check the left side. If
                //the left child is null, insert. If not, then recursively call insert with
                //the left child as nodeToCheck.
                if (nodeToCheck -> getLeftChild() == nullptr) {
                    nodeToCheck -> setLeftChild(new BSTNode(&personToInsert));
                } else {
                    insert(personToInsert, nodeToCheck -> getLeftChild());
                }; //if
            }; //if
        }; //if
    }; //insert



    void remove(Person personToDelete, BSTNode* nodeToCheck) {
        if (nodeToCheck == nullptr) {
            return;
        } else if (nodeToCheck -> getData().equals(personToDelete)) {
            if (isLeafNode(nodeToCheck)) {
                delete nodeToCheck;
            } else if (nodeHasOneChild) {
                if (nodeToCheck -> getLeftChild() != nullptr) {
                    BSTNode* temp = nodeToCheck -> getLeftChild();
                    delete nodeToCheck -> getLeftChild();
                    nodeToCheck = temp;
                } else {
                    BSTNode* temp = nodeToCheck -> getRightChild();
                    delete nodeToCheck -> getRightChild();
                    nodeToCheck = temp;
                }; //if
            } else {
                deleteNodeWithTwoChildren(nodeToCheck);
            }; //if
        } else {
            //if this branch is reached, the person is not present in the tree.
            return;
        }; //if
    }; //remove

}; //BinarySearchTree