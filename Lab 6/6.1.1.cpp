/* Write a menu driven Program for the following operations on Binary Search Tree (BST) of Integers
i. Create a BST of N Integers: 5, 10, 25, 2, 8, 15, 24, 14, 7, 8, 35, 2
ii. Traverse the BST in Inorder, Preorder and Post Order
iii. Search the BST for a given element (KEY) and print the appropriate message
iv. Exit */
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int info;
    node *left,*right;
};
class BST
{
public:
    node *root;
    BST():root(NULL) {}
    node * GetRoot();
    void AddNewKey(node* &,int&);
    void InorderTransvere(node *);
    void PreorderTransvere(node *);
    void PostorderTransvere(node *);
    void SearchKey(node *,int&);
    void DeleteKey(node* &,int&);
    node * FindLargestNode(node* &);
};
node * BST::GetRoot()
{
    return root;
}
void BST::AddNewKey(node* &r,int &val)
{
    if(r==NULL)
    {
        node *temp=new node;
        if(temp==NULL)
            cout<<"\nFailed to initialize memory for new node\n\n";
        else
        {
            temp->info=val;
            r=temp;
            r->left=r->right=NULL;
        }
    }
    else
    {
        if(val<r->info)
            AddNewKey(r->left,val);
        else
            AddNewKey(r->right,val);
    }
}
void BST::PreorderTransvere(node *r)
{
    if(r!=NULL)
    {
        cout<<r->info<<"\t";
        PreorderTransvere(r->left);
        PreorderTransvere(r->right);
    }
}
void BST::InorderTransvere(node *r)
{
    if(r!=NULL)
    {
        InorderTransvere(r->left);
        cout<<r->info<<"\t";
        InorderTransvere(r->right);
    }
}
void BST::PostorderTransvere(node *r)
{
    if(r!=NULL)
    {
        PostorderTransvere(r->left);
        PostorderTransvere(r->right);
        cout<<r->info<<"\t";
    }
}
void BST::SearchKey(node *r,int &val)
{
    if(r==NULL)
        cout<<"\n\nThere is no "<<val<<"  in BST\n\n";
    else if(r->info==val)
        cout<<"\n\n"<<val<<"  is present in BST.\n\n";
    else
    {
        if(val<r->info)
            SearchKey(r->left,val);
        else
            SearchKey(r->right,val);
    }
}
void BST::DeleteKey(node* &r,int &val)
{
    if(r==NULL)
        cout<<"\n\n"<<val<<"  is not present in the BST.\n";
    else if(val<r->info)
        DeleteKey(r->left,val);
    else if(val>r->info)
        DeleteKey(r->right,val);
    else if(r->left && r->right)
    {
        node *t;
        t=FindLargestNode(r->left);
        r->info=t->info;
        DeleteKey(r->left,t->info);
    }
    else
    {
        node *t;
        t=r;
        if(r->left==NULL &&r->right==NULL)
            r=NULL;
        else if(r->left!=NULL)
            r=r->left;
        else
            r=r->right;
        delete t;
    }
}
node * BST::FindLargestNode(node* &l)
{
    if(l->right==NULL)
        return l;
    else
        return FindLargestNode(l->right);
}
int main()
{
    BST test;
    int choice,num;
    while(1)
    {
        cout<<"1. Create BST\n2. Add New Key\n3. Preorder Transverse\n4. Inorder Transvere\n5. Postorder Transverse\n6. Search Key\n7. Delete Key\n8. Exit\nEnter your choice :  ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            cout<<"\nEnter -1 to end\nEnter the key value:   ";
            cin>>num;
            while(num!=-1)
            {
                test.AddNewKey(test.root,num);
                cin>>num;
            }
            cout<<"\n\n";
            break;
        }
        case 2:
        {
            cout<<"\nEnter the key value:   ";
            cin>>num;
            test.AddNewKey(test.root,num);
            cout<<"\n\n";
            break;
        }
        case 3:
        {
            cout<<"\n\nThe preorder transversal is as follows: \n";
            test.PreorderTransvere(test.GetRoot());
            cout<<"\n\n";
            break;
        }
        case 4:
        {
            cout<<"\n\nThe inorder transversal is as follows: \n";
            test.InorderTransvere(test.root);
            cout<<"\n\n";
            break;
        }
        case 5:
        {
            cout<<"\n\nThe postorder transversal is as follows: \n";
            test.PostorderTransvere(test.GetRoot());
            cout<<"\n\n";
            break;
        }
        case 6:
        {
            cout<<"\n\nEnter the key value which you want  to search :   ";
            cin>>num;
            test.SearchKey(test.GetRoot(),num);
            break;
        }
        case 7:
        {
            cout<<"\n\nThe preorder transversal is as follows: \n";
            test.PreorderTransvere(test.GetRoot());
            cout<<"\n\n\nEnter the key value which you want  to delete :   ";
            cin>>num;
            test.DeleteKey(test.root,num);
            cout<<"\n\nThe preorder transversal is as follows: \n";
            test.PreorderTransvere(test.GetRoot());
            cout<<"\n\n\n";
            break;
        }
        default :
            exit(0);
        }
    }
    return 0;
}
