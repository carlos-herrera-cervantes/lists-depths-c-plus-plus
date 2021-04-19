#include <vector>
#include <iostream>
#include "binarySearchTree.cpp"
#include "linkedList.cpp"
#include "treeNode.cpp"

using namespace std;

/**
 * Creates a level-linked list from a binary search tree
 * @param root TreeNode object class
 * @param lists List of linked list
 * @param level Level number of binary search tree
 */
void createLevelLinkedList(TreeNode* root, vector<LinkedList> *lists, int level)
{
    if (!root) return;

    LinkedList list;

    if (lists->size() == level)
    {
        list.insert(root->data);
        lists->push_back(list);
    }
    else
    {
        list = lists->at(level);
        list.insert(root->data);
        lists->at(level) = list;
    }

    createLevelLinkedList(root->left, lists, level + 1);
    createLevelLinkedList(root->rigth, lists, level + 1);
}

/**
 * Executes the task to create a list of linked list
 * @param root TreeNode object class
 * @returns List of linked list
 */
vector<LinkedList> executeTask(TreeNode* root)
{
    vector<LinkedList> lists;
    createLevelLinkedList(root, &lists, 0);
    return lists;
}

int main()
{
    BinarySearchTree binarySearchTree;

    binarySearchTree.insert(4);
    binarySearchTree.insert(2);
    binarySearchTree.insert(10);

    vector<LinkedList> lists = executeTask(binarySearchTree.getRoot());

    for (auto& it : lists)
    {
        it.print_all();
        cout << "\n";
    }

    return 0;
}