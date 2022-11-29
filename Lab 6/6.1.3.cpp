/* Write a menu driven Program for the following operations on Binary Search Tree (BST) of Integers
i. Create a BST of N Integers: 5, 10, 25, 2, 8, 15, 24, 14, 7, 8, 35, 2
ii. Traverse the BST in Inorder, Preorder and Post Order
iii. Search the BST for a given element (KEY) and print the appropriate message
iv. Exit */
#include<iostream>
using namespace std;
class BST
{
    struct Node
    {
        int data;
        Node *left;
        Node *right;
    };
    typedef struct Node* nodeptr;
public:
    nodeptr root;
    BST()      //constructor
    {
        root=NULL;
    }
    void create()            // create BST having some data
    {
        int val=0;
        cout<<"insert and end with -1"<<endl;
        cin>>val;

        while(val!=-1)
        {
            ins(root,val);
            cin>>val;
        }
    }
    void search_ele(nodeptr ptr,int data)   //search element
    {
        if(ptr==NULL || data==ptr->data)
        {
            if(ptr==NULL)
                cout<<endl<<"DATA NOT FOUND"<<endl;
            else
            {
                cout<<"= "<<ptr->data<<endl;
                cout<<"sucessfully found"<<endl;
            }
        }
        else
        {
            if(data<ptr->data)
            {
                cout<<"->L";
                search_ele(ptr->left,data);
            }
            else
            {
                cout<<"->R";
                search_ele(ptr->right,data);
            }
        }
    }
    void ins(nodeptr &ptr,int new_data)     //insert at the last
    {
        nodeptr p;
        if(ptr==NULL)
        {
            p=new Node;
            p->data=new_data;
            p->left=NULL;
            p->right=NULL;
            ptr=p;
        }
        else
        {
            if(new_data < ptr->data)
                ins(ptr->left,new_data);
            else
                ins(ptr->right,new_data);
        }
    }
    nodeptr find_largest(nodeptr &ptr)  // largest in the tree
    {
        if(ptr->right==NULL)
            return ptr;
        else
            return find_largest(ptr->right);
    }
    void del_data(nodeptr &ptr,int old_data)     // delete the specified data
    {
        if(ptr==NULL)
        {
            cout<<"Val not found"<<endl;
        }
        else if(old_data<ptr->data)
            del_data(ptr->left,old_data);
        else if(old_data>ptr->data)
            del_data(ptr->right,old_data);
        else if(ptr->left && ptr->right)
        {
            nodeptr p=find_largest(ptr->left);
            ptr->data=p->data;
            del_data(ptr->left,p->data);
        }
        else
        {
            nodeptr p=ptr;
            if(ptr->left==NULL && ptr->right==NULL)
                ptr=NULL;
            else if(ptr->left!=NULL)
                ptr=ptr->left;
            else
                ptr=ptr->right;
            delete p;
        }
    }
    void display_pre(nodeptr ptr)      // display Preorder
    {
        if(ptr!=NULL)
        {
            cout<<"->"<<ptr->data;
            display_pre(ptr->left);
            display_pre(ptr->right);
        }
    }
    void display_post(nodeptr ptr)      // display postorder
    {
        if(ptr!=NULL)
        {
            display_post(ptr->left);
            display_post(ptr->right);
            cout<<"->"<<ptr->data;
        }
    }
    void display_in(nodeptr ptr)      // display inorder
    {
        if(ptr!=NULL)
        {
            display_in(ptr->left);
            cout<<"->"<<ptr->data;
            display_in(ptr->right);
        }
    }
};
int main()
{
    BST tree;
    int x,a;
    int choice=0;
    while(choice!=7)
    {
        cout<<"\n\nyour Choice please: "<<endl;
        cout<<"0-create "<<endl;
        cout<<"1-inserting in Tree "<<endl;
        cout<<"2-Search"<<endl;
        cout<<"3-Display preorder"<<endl;
        cout<<"4-Display postorder"<<endl;
        cout<<"5-Display Inorder"<<endl;
        cout<<"6-Delete element"<<endl;
        cout<<"7-Exit\n"<<endl;
        cout<<"\t\tyour choice: ";
        cin>>choice;
        system("CLS");
        if(choice!=3)
        {
            cout<<"pre-order Display"<<endl;
            if(tree.root!=NULL)
                tree.display_pre(tree.root);
            else
                cout<<"empty"<<endl;
        }
        cout<<"\n\n"<<endl;
        switch (choice)
        {
        case 0:
            tree.create();
            cout<<"\n\npre-order Display"<<endl;
            if(tree.root!=NULL)
                tree.display_pre(tree.root);
            else
                cout<<"empty"<<endl;
            break;
        case 1:
            cout<<"enter data to insert: ";
            cin>>x;
            tree.ins(tree.root,x);
            cout<<"\n\npre-order Display"<<endl;
            if(tree.root!=NULL)
                tree.display_pre(tree.root);
            else
                cout<<"empty"<<endl;
            break;
        case 2:
            cout<<"enter data to search: ";
            cin>>x;
            cout<<"Root";
            tree.search_ele(tree.root,x);
            cout<<"\n\npre-order Display"<<endl;
            if(tree.root!=NULL)
                tree.display_pre(tree.root);
            else
                cout<<"empty"<<endl;
            break;
        case 3:
            cout<<"PreOrder Display"<<endl;
            tree.display_pre(tree.root);
            break;
        case 4:
            cout<<"PostOrder Display"<<endl;
            tree.display_post(tree.root);
            break;
        case 5:
            cout<<"InOrder Display"<<endl;
            tree.display_in(tree.root);
            break;
        case 6:
            cout<<"enter data to delete: ";
            cin>>x;
            tree.del_data(tree.root,x);
            cout<<"\n\npre-order Display"<<endl;
            if(tree.root!=NULL)
                tree.display_pre(tree.root);
            else
                cout<<"empty"<<endl;
            break;
        case 7:
            break;
        }
    }
    cout<<"\n============X==========="<<endl;
    cout<<"\t THANK YOU "<<endl;
    return 0;
}

