#include <iostream>
#include <stack>

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

    void search(int num, TreeNode *nodeptr, bool &status){
        if(nodeptr == nullptr)
            return;
        else if(nodeptr->value == num){
            status = true;
        }
        else if(nodeptr->value > num)
            search(num, nodeptr->left, status);
        else
            search(num, nodeptr->right, status);
    }
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
    // bool searchNode(int);
    void remove(int);
    void displayInOrder() 
    {
        if(root == nullptr)
            return;
        TreeNode *current = root;
        stack<TreeNode*> s;

        while(current != nullptr || !s.empty()){
            while(current != nullptr){
                s.push(current);
                current = current->left;
            }

            current = s.top();
            s.pop();
            cout << current->value << " ";
            current = current->right;
        }

    }

    void displayPreOrder() 
    {
        if(root == nullptr)
            return;
        stack<TreeNode *> s;
        s.push(root);

        while(!s.empty()){
            TreeNode *current = s.top();
            s.pop();
            cout << current->value << " ";

            if(current->right != nullptr)
                s.push(current->right);
            if(current->left != nullptr)
                s.push(current->left);
        }
        

        // displayPreOrder(root);
    }

    void displayPostOrder() const
    {
        displayPostOrder(root);
    }

    bool searchNode(int num){
        bool status = false;
        search(num, root, status);

        return status;
    }
};

int main()
{
    IntBinaryTree binaryNumber;
    cout << "hello\n";

    binaryNumber.remove(0);
    cout << "hello\n";

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
    cout << endl;
    binaryNumber.remove(0);
    // binaryNumber.insertNode(0);
    cout << "\ndisplaying in order\n";
    binaryNumber.displayInOrder();
    cout << endl;

    cout << "\ndisplaying post order\n";
    binaryNumber.displayPostOrder();
    cout << endl;

    cout << "\ndisplaying pre order\n";
    binaryNumber.displayPreOrder();
    cout << endl;

    if(binaryNumber.searchNode(20))
        cout << "the value exists in a tree.\n";
    else
        cout << "The value doesnt exist in a tree.\n";
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
        cout << nodePtr->value << " ";
        displayInOrder(nodePtr->right);
    }

}

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        cout << nodePtr->value << " ";
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
        cout << nodePtr->value << " ";
    }
}

// bool IntBinaryTree::searchNode(int number)
// {
//     TreeNode *nodePtr = root;

//     while (nodePtr)
//     {
//         if (nodePtr->value == number)
//             return true;
//         else if (nodePtr->value < number)
//             nodePtr = nodePtr->left;
//         else
//             nodePtr = nodePtr->right;
//     }
//     return false;
// }

void IntBinaryTree::remove(int number)
{
    deleteNode(number, root);
}

void IntBinaryTree::deleteNode(int number, TreeNode *&nodePtr)
{
    if(nodePtr == nullptr){
        cout << "the value doesnt exist in the tree.\n";
        return;
    }
    else if (number < nodePtr->value)
        deleteNode(number, nodePtr->left);
    else if (number > nodePtr->value)
        deleteNode(number, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr)
{
    TreeNode *tempNodePtr = nullptr;

    if (nodePtr->right == nullptr)
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