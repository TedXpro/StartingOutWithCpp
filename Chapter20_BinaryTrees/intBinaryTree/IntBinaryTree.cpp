#include <iostream>

using namespace std;

class IntBinaryTree
{
private:
    struct TreeNode
    {
        int value;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode *root;

    void insert(TreeNode *&, TreeNode *&);
    void destroySubTree(TreeNode *&);
    void deleteNode(int, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void displayInOrder(TreeNode *) const;
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;

public:
    IntBinaryTree()
    {
        root = nullptr;
    }

    ~IntBinaryTree()
    {
        destroySubTree(root);
    }

    void insertNode(int);
    bool searchNode(int);
    void remove(int);
    void displayInOrder() const
    {
        displayInOrder(root);
    }

    void displayPreOrder() const
    {
        displayPreOrder(root);
    }

    void displayPostOrder() const
    {
        displayPostOrder(root);
    }
};

int main()
{
    IntBinaryTree binaryNumber;

    binaryNumber.remove(0);

    binaryNumber.insertNode(5);
    binaryNumber.insertNode(2);
    binaryNumber.insertNode(1);
    binaryNumber.insertNode(4);
    binaryNumber.insertNode(3);
    binaryNumber.insertNode(8);
    binaryNumber.insertNode(7);
    binaryNumber.insertNode(11);
    binaryNumber.insertNode(13);
    binaryNumber.insertNode(20);
    binaryNumber.insertNode(12);
 
    cout << "\ndisplaying in order\n";
    binaryNumber.displayInOrder();
 
    binaryNumber.remove(0);
    // binaryNumber.insertNode(0);
    cout << "\ndisplaying in order\n";
    binaryNumber.displayInOrder();

    cout << "\ndisplaying post order\n";
    binaryNumber.displayPostOrder();
    
    cout << "\ndisplaying pre order\n";
    binaryNumber.displayPreOrder();
}

/**
 * This function inserts new value to the binary tree.
 * calls the insert method.
 * @param number holds the new value to be added to
 * the binary tree.
 */
void IntBinaryTree::insertNode(int number)
{
    TreeNode *newNode = nullptr;

    newNode = new TreeNode;

    newNode->value = number;
    newNode->left = newNode->right = nullptr;

    insert(root, newNode);
}

/**
 * This function puts the new node at the right position.
 * @param nodePtr is the one to be compared with.
 * @param newNode is the one that is placed in the right position.
 */
void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode;
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
}

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    }
}

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        cout << nodePtr->value << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << endl;
    }
}

bool IntBinaryTree::searchNode(int number)
{
    TreeNode *nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->value == number)
            return false;
        else if (nodePtr->value < number)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

void IntBinaryTree::remove(int number)
{
    deleteNode(number, root);
}

void IntBinaryTree::deleteNode(int number, TreeNode *&nodePtr)
{
    if (number < nodePtr->value)
        deleteNode(number, nodePtr->left);
    else if (number > nodePtr->value)
        deleteNode(number, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr)
{
    TreeNode *tempNodePtr = nullptr;

    if (nodePtr == nullptr)
        cout << "Cannot delete empty node.\n";
    else if (nodePtr->right == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
    else
    {
        tempNodePtr = nodePtr->right;

        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;

        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;

        delete tempNodePtr;
    }
}

void IntBinaryTree::destroySubTree(TreeNode *& nodePtr)
{
    if(nodePtr)
    {
        if(nodePtr->left)
            destroySubTree(nodePtr->left);
        if(nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;     
    }
}