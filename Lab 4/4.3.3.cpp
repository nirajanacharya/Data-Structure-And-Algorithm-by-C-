/*WAP to implement doubly linked list */
#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node * next;
    struct node * prev;
};
struct node * start;
struct node * newnode,* temp,* ptr;
void insert_end();
void creation()
{
        newnode = new node;
        cout<<"Enter the data for the list(insert -1 to end the list): ";
        cin>>newnode->data;
        newnode->prev=NULL;
        newnode->next=NULL;
        if (start==NULL)
        {
            start=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    do{
        insert_end();
    }while (newnode->data!=-1);
}
void insert_end()
{
    newnode=new node;
    cout<<"Enter the data to be stored at the end: "<<endl;
    cin>>newnode->data;
    if (newnode->data!=-1)
    {
        newnode->next=NULL;
        newnode->prev=NULL;
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->prev=ptr;
    }
}
void insert_begin()
{
    newnode = new node;
    cout<<"Enter the data to be inserted at the beginning"<<endl;
    cin>>newnode->data;
    newnode->prev=NULL;
    newnode->next=start;
    start->prev=newnode;
    start=newnode;
}
void insert_afternode()
{
    int val;
    newnode = new node;
    cout<<"Enter after which value you want to insert: "<<endl;
    cin>>val;
    cout<<"Enter the new data you want to insert: "<<endl;
    cin>>newnode->data;
    ptr=start;
    while(ptr->data!=val)
    {
        ptr=ptr->next;
        if(ptr==NULL)
        {
            cout<<"error data not found";
        }
    }
    newnode->next=ptr->next;
    newnode->prev=ptr;
    ptr->next->prev=newnode;
    ptr->next=newnode;
}
void insert_beforenode()
{
    int val;
    newnode = new node;
    cout<<"Enter before which value you want to insert: "<<endl;
    cin>>val;
    cout<<"Enter the new data you want to insert: "<<endl;
    cin>>newnode->data;
    ptr=start;
    while(ptr->data!=val)
    {
        ptr=ptr->next;
        if(ptr==NULL)
        {
            cout<<"error data not found";
        }
    }
    newnode->next=ptr;
    newnode->prev=ptr->prev;
    ptr->prev->next=newnode;
    ptr->prev=newnode;
}
void del_end()
{
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    cout<<"The deleted value is: "<<ptr->data;
    ptr->prev->next=NULL;
    delete ptr;
}
void del_begin()
{
    ptr=start->next;
    delete start;
    start=ptr;
    ptr->prev=NULL;
}
void del_node()
{
    int val;
    cout<<"Enter the value of node which you want to delete: "<<endl;
    cin>>val;
    ptr=start;
    while(ptr->data!=val)
    {
        ptr=ptr->next;
    }
    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
    delete ptr;
}
void del_after ()
{
    int val;
    cout<<"Enter the value of node after which you want to delete: "<<endl;
    cin>>val;
    ptr=start;
    while(ptr->data!=val)
    {
        ptr=ptr->next;
    }
    temp=ptr->next;
    ptr->next=temp->next;
    temp->next->prev=ptr;
    delete temp;
}
void display_list()
{
    ptr=start;
    cout<<"\n\nThe list is: "<<endl;
    cout<<"\t\t\t"<<ptr->data<<endl;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
        if (ptr->data==-1)
            break;
        cout<<"\t\t\t"<<ptr->data<<endl;
    }
}
int main()
{
    start=NULL;
    int choice=0,c=0;
    while(choice!=10){
        c++;
        cout<<"\n\nyour Choice please: "<<endl;
        if (c==1){cout<<"0-Creating a new list "<<endl;}
        cout<<"1-Inserting in front of list "<<endl;
        cout<<"2-Inserting at the end "<<endl;
        cout<<"3-Inserting after value a node "<<endl;
        cout<<"4-Inserting before value a node"<<endl;
        cout<<"5-Delete from front "<<endl;
        cout<<"6-Delete from the last "<<endl;
        cout<<"7-Delete a node"<<endl;
        cout<<"8-Delete after value a node"<<endl;
        cout<<"10-Exit.\n"<<endl;
        cout<<"\t\tyour choice: ";
        cin>>choice;
        switch (choice){
        case 0:
            creation();
            break;
        case 1:
            insert_begin();
            break;
        case 2:
            insert_end();
            break;
        case 3:
            insert_afternode();
            break;
        case 4:
            insert_beforenode();
            break;
        case 5:
            del_begin();
            break;
        case 6:
            del_end();
            break;
        case 7:
            del_node();
            break;
        case 8:
            del_after();
            break;
        }
        display_list();
    }
    cout<<"THANK YOU";
}
