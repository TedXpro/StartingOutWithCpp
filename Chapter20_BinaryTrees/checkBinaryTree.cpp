#include <iostream>

using namespace std;

struct BinaryNode
{
    int value;
    BinaryNode *left;
    BinaryNode *right;
};

bool checkIfBinary(BinaryNode *nodePtr, int minValue, int maxValue)
{
    if (nodePtr == nullptr)
        return true;
     if (nodePtr->value > minValue && nodePtr->value <= maxValue &&
             checkIfBinary(nodePtr->left, minValue, nodePtr->value) &&
             checkIfBinary(nodePtr->right, nodePtr->value, maxValue))
        return true;
    else
        return false;
}

BinaryNode *addValue(int value)
{
    BinaryNode *nodePtr = new BinaryNode;
    nodePtr->value = value;
    nodePtr->left = nullptr;
    nodePtr->right = nullptr;

    return nodePtr;
}

int main()
{
    BinaryNode *rootNode = addValue(5);
    rootNode->left = addValue(3);
    rootNode->left->left = addValue(2);
    rootNode->left->right = addValue(4);
    rootNode->left->left->left = addValue(1);
    rootNode->left->left->right = addValue(6);
    // rootNode->left->right->left = addValue(0);
    // rootNode->left->right->right = addValue(7);

    rootNode->right = addValue(9);
    rootNode->right->left = addValue(8);
    rootNode->right->right = addValue(10);
    rootNode->right->right->right = addValue(12);
    // rootNode->right->right->right->left = addValue(-1);
    rootNode->right->right->right->right = addValue(20);

    if(checkIfBinary(rootNode,0,100))
        cout << "BST\n";
    else
        cout << "Not BST\n";

    // checkIfBinary(rootNode, -100, 100) ? cout << "its BST\n" : cout << "Its Not BST\n";
}