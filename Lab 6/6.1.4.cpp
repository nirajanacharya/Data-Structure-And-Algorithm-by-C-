/* Write a menu driven Program for the following operations on Binary Search Tree (BST) of Integers
i. Create a BST of N Integers: 5, 10, 25, 2, 8, 15, 24, 14, 7, 8, 35, 2
ii. Traverse the BST in Inorder, Preorder and Post Order
iii. Search the BST for a given element (KEY) and print the appropriate message
iv. Exit */
#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
class BST
{
public:
    node* root;
    BST()
    {
        root = NULL;
    }
    void insert_node(node* &tree, int val)
    {
        if(tree == NULL)
        {
            tree = new node;
            tree -> data = val;
            tree -> left = NULL;
            tree -> right = NULL;
        }
        else
        {
            if(val < tree -> data)
            {
                insert_node(tree -> left, val);
            }
            else
            {
                insert_node(tree -> right, val);
            }
        }
    }
    void preorder(struct node* tree)
    {
        if (tree != NULL)
        {
            cout << tree -> data << endl;
            preorder(tree -> left);
            preorder(tree -> right);
        }
    }
    void postorder(struct node* tree)
    {
        if (tree != NULL)
        {
            postorder(tree -> left);
            postorder(tree -> right);
            cout << tree -> data << endl;
        }
    }
    void inorder(struct node* tree)
    {
        if (tree != NULL)
        {
            inorder(tree -> left);
            cout << tree -> data << endl;
            inorder(tree -> right);
        }
    }
    void search_element(struct node* tree, int val)
    {
        if(tree == NULL)
            cout << "Data not present in tree." << endl;
        else if(tree -> data == val)
            cout << "Data found in tree." << endl;
        else
        {
            if(val < tree->data)
                search_element(tree -> left, val);
            else
                search_element(tree -> right, val);
        }
    }
};
int main()
{
    int choice = 0, val = 0;
    BST tree;
    do
    {
        cout << "Main Menu" << endl
             << "1. Insert node" << endl
             << "2. Search node" << endl
             << "3. Preorder Traversal" << endl
             << "4. Inorder Traversal" << endl
             << "5. Postorder Traversal" << endl
             << "6. Exit" << endl
             << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            cout << "Enter -1 to end." << endl;
            while(val != -1)
            {
                cout << "Enter a number: ";
                cin >> val;
                if(val != -1)
                    tree.insert_node(tree.root, val);
            }
            break;
        case 2:
            cout << "Enter the number to find: ";
            cin >> val;
            tree.search_element(tree.root, val);
            break;
        case 3:
            tree.preorder(tree.root);
            break;
        case 4:
            tree.inorder(tree.root);
            break;
        case 5:
            tree.postorder(tree.root);
            break;
        }
        cout <<"\n\n\n";
    }
    while(choice > 0 && choice < 6);
    return 0;
}
