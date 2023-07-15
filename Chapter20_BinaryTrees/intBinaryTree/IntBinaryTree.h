#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H 

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
    void destroySubTree(TreeNode *);
    void deleteNode(int, TreeNode * &);
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

#endif