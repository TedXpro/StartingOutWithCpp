#include <iostream>

using namespace std;

class IntBinaryTree
{
private:
    struct BinaryNode
    {
        int value;
        BinaryNode *right;
        BinaryNode *left;
    };

    BinaryNode *rootNode;

    void insertNode(BinaryNode *&, BinaryNode *&);
    // void insertNode(BinaryNode *, BinaryNode *);
    void displayInOrder(BinaryNode *&) const;
    void displayPreOrder(BinaryNode *&) const;
    void displayPostOrder(BinaryNode *&) const;
    void deleteNode(int, BinaryNode *&);
    void makeDeletion(BinaryNode *&);
    void deleteAllTree(BinaryNode *&);

public:
    IntBinaryTree()
    {
        rootNode = nullptr;
    }

    ~IntBinaryTree()
    {
        deleteAllTree(rootNode);
    }
    void insert(int);
    void displayInOrder();
    void displayPreOrder();
    void displayPostOrder();
    void deleteElement(int);
    bool checkElement(int);
};

int menu();

int main()
{
    int choice = menu();

    if (choice == 7)
    {
        cout << "Thank you for using\n";
        return 0;
    }

    IntBinaryTree binaryNumber;
    do
    {
        if (choice == 1)
        {
            cout << "Enter your number: ";
            cin >> choice;
            binaryNumber.insert(choice);
            cout << endl;
        }
        else if (choice == 2)
        {
            cout << "\nDisplaying in INORDER:\n\t";
            binaryNumber.displayInOrder();
            cout << endl;
        }
        else if (choice == 3)
        {
            cout << "\nDisplaying in PREORDER:\n\t";
            binaryNumber.displayPreOrder();
            cout << endl;
        }
        else if (choice == 4)
        {
            cout << "\nDisplaying in POSTORDER:\n\t";
            binaryNumber.displayPostOrder();
            cout << endl;
        }
        else if (choice == 5)
        {
            cout << "Enter the number to be deleted: ";
            cin >> choice;
            binaryNumber.deleteElement(choice);
            cout << endl;
        }
        else if (choice == 6)
        {
            cout << "Enter the number: ";
            cin >> choice;

            if (binaryNumber.checkElement(choice))
                cout << "\nThe number " << choice << " EXISTS in the Tree.\n\n";
            else
                cout << "\nThe number " << choice << " DOESN'T EXIST in the Tree.\n\n";
        }

        choice = menu();
    } while (choice != 7);

    cout << "Thank you for using.\n";
    return 0;
}

int menu()
{
    int choice;
    cout << "Welcome to BinaryTree!\n";
    cout << "1. Insert\n";
    cout << "2. Preview IN ORDER\n";
    cout << "3. Preview PRE ORDER\n";
    cout << "4. Preview POST ORDER\n";
    cout << "5. Delete\n";
    cout << "6. Search for element\n";
    cout << "7. EXIT\n";
    cout << "Enter Your Choice: ";
    cin >> choice;

    while (choice > 7 || choice < 1)
    {
        cout << "Enter your choice between 1-7: ";
        cin >> choice;
    }
    return choice;
}

void IntBinaryTree::deleteAllTree(BinaryNode *&nodePtr)
{
    if (nodePtr != nullptr)
    {
        if (nodePtr->left != nullptr)
            deleteAllTree(nodePtr->left);
        if (nodePtr->right != nullptr)
            deleteAllTree(nodePtr->right);
        delete nodePtr;
    }
}

/**
 * this function checks for the exisitence of an
 * element in the tree.
 * @param number holds the number to be checked.
 */
bool IntBinaryTree::checkElement(int number)
{
    BinaryNode *nodePtr = rootNode;

    while (nodePtr != nullptr)
    {
        if (nodePtr->value < number)
            nodePtr = nodePtr->right;
        else if (nodePtr->value > number)
            nodePtr = nodePtr->left;
        else
            return true;
    }
    return false;
}

/**
 * used for interaction with user, and
 * call the deletenode function.
 * @param number holds the number to be deleted (if it exists);
 */
void IntBinaryTree::deleteElement(int number)
{
    if (rootNode == nullptr)
    {
        cout << "The tree is empty\n";
        return;
    }
    if (checkElement(number))
        deleteNode(number, rootNode);
    else
        cout << "the number doesn't exist in the tree.\n";
}

/**
 * Traverse the tree to find the element to be deleted.
 * @param number holds the number to be deleted(if it exists);
 * @param nodePtr holds the pointer to traverse the tree.
 */
void IntBinaryTree::deleteNode(int number, BinaryNode *&nodePtr)
{
    if (nodePtr->value > number)
        deleteNode(number, nodePtr->left);
    else if (nodePtr->value < number)
        deleteNode(number, nodePtr->right);
    else
    {
        makeDeletion(nodePtr);
        cout << number << " has succesfully been deleted.\n";
    }
}

/**
 * Actually deletes the node from the tree.
 * @param nodePtr holds the node to be deleted from the tree.
 */
void IntBinaryTree::makeDeletion(BinaryNode *&nodePtr)
{
    BinaryNode *temp = nullptr;

    if (nodePtr->left == nullptr)
    {
        temp = nodePtr;
        nodePtr = nodePtr->right;
        delete temp;
    }
    else if (nodePtr->right == nullptr)
    {
        temp = nodePtr;
        nodePtr = nodePtr->left;
        delete nodePtr;
    }
    else
    {
        temp = nodePtr->right;

        while (temp->left != nullptr)
            temp = temp->left;

        temp->left = nodePtr->left;
        temp = nodePtr;
        nodePtr = nodePtr->right;
        delete temp;
    }
}

/**
 * used to call the overloaded funtion by passing the
 * root nodeptr as an argument.
 */
void IntBinaryTree::displayPostOrder()
{
    if (rootNode == nullptr)
        cout << "The Tree is empty.\n";
    else
    {
        displayPostOrder(rootNode);
        cout << endl;
    }
}

/**
 * This function will display the elements after traversing from left
 * to right only to display if the right value points to null or reached
 * a left value where both right and left point to null.
 * @param nodePtr holds the nodes to be printed.
 */
void IntBinaryTree::displayPostOrder(BinaryNode *&nodePtr) const
{
    if (nodePtr != nullptr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << " ";
    }
}

/**
 * used to call the overloaded funtion by passing the
 * root nodeptr as an argument.
 */
void IntBinaryTree::displayPreOrder()
{
    if (rootNode == nullptr)
        cout << "The Tree is empty.\n";
    else
    {
        displayPreOrder(rootNode);
        cout << endl;
    }
}

/**
 * This function displays the elements by traversing the tree
 * from left to right only to display when it encounters a node.
 * @param nodePtr holds the nodes to be printed.
 */
void IntBinaryTree::displayPreOrder(BinaryNode *&nodePtr) const
{
    if (nodePtr != nullptr)
    {
        cout << nodePtr->value << " ";
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

/**
 * used to call the overloaded funtion by passing the
 * root nodeptr as an argument.
 */
void IntBinaryTree::displayInOrder()
{
    if (rootNode == nullptr)
        cout << "The Tree is empty.\n";
    else
    {
        displayInOrder(rootNode);
        cout << endl;
    }
}

/**
 * this function will display elements in an orderly manner.
 * @param nodePtr holds the nodes to be printed.
 */
void IntBinaryTree::displayInOrder(BinaryNode *&nodePtr) const
{
    if (nodePtr != nullptr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << " ";
        displayInOrder(nodePtr->right);
    }
}

/**
 * assigns new Node for the new value and calls the
 * insertNode function;
 * @param number holds the new number to be added.
 */
void IntBinaryTree::insert(int number)
{
    BinaryNode *newNode = new BinaryNode;
    newNode->value = number;
    newNode->left = newNode->right = nullptr;

    cout << "Inserting " << newNode->value << endl;

    insertNode(rootNode, newNode);
}

// void IntBinaryTree::insertNode(BinaryNode *nodePtr, BinaryNode *newNode)
// {
//     if(nodePtr == nullptr)
//         nodePtr = newNode;
//     else if(nodePtr->value > newNode->value)
//         insertNode(nodePtr->left, newNode);
//     else
//         insertNode(nodePtr->right, newNode);
// }

/**
 * This function traverses thru the tree to find 
 * the exact position to insert the new node.
 * @param nodePtr holds the nodes that are already 
 * in the tree.
 * @param newNode holds the new Node to be added.
*/
void IntBinaryTree::insertNode(BinaryNode *&nodePtr, BinaryNode *&newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode;
    else if (nodePtr->value > newNode->value)
        insertNode(nodePtr->left, newNode);
    else
        insertNode(nodePtr->right, newNode);
}