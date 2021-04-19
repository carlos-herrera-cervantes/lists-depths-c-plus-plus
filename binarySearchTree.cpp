#include <iostream>
#include "treeNode.cpp"

using namespace std;

class BinarySearchTree
{
    TreeNode* root;
    int length;

    /**
     * Prints the elements
     * @param node TreeNode object class
     */
    void inorder(TreeNode* node)
    {
        if (!node) return;

        cout << node->data << ": ";

        if (node->left) cout << "L" << node->left->data << " ";
        if (node->rigth) cout << "R" << node->rigth->data << " ";
        
        cout << endl;

        inorder(node->left);
        inorder(node->rigth);
    }

    /** Inserts a new node
     * @param node Node object class
     * @param value Number value
     * @returns TreeNode object class
    */
    TreeNode* insert(TreeNode* node, int value)
    {
        if (!node)
        {
            node = new TreeNode();
            node->data = value;
            node->left = node->rigth = NULL;
        }
        else if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->rigth = insert(node->rigth, value);
        }

        return node;
    }

    public:

        BinarySearchTree()
        {
            root = NULL;
            length = 0;
        }

        /**
         * Prints the elements to the console
         */
        void print()
        {
            inorder(root);
            cout << endl;
        }

        /**
         * Inserts a new value
         * @param data Number value
         */
        void insert(int data)
        {
            root = insert(root, data);
            length++;
        }

        /**
         * Returns the root node of the tree
         * @returns TreeNode object class
         */
        TreeNode* getRoot()
        {
            return root;
        }
};