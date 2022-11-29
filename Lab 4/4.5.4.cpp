/*WAP to implement STACK using linked list */
#include<iostream>
using namespace std;
class linkList
{
    struct Node
    {
        int data;
        Node *next;
    };
    typedef struct Node* nodeptr;
    nodeptr head;
public:
    linkList()      //constructor
    {
        head=NULL;
    }
    void push(int new_data)    // insert at the top
    {
        nodeptr p;
        p=new Node;
        p->data= new_data;
        p->next=head;
        head=p;
    }
    int pop()            // delete from the top
    {
        nodeptr ptr=head;
        if(head!=NULL)
        {
            head=ptr->next;
            cout<<ptr->data<<" is popped\n\n"<<endl;
            delete ptr;
            return ptr->data;
        }
        else
        {
            cout<<"Empty\n\n"<<endl;
            return -1;
        }
    }
    int peek()            // delete from the front
    {
        nodeptr ptr=head;
        if(head!=NULL)
        {
            cout<<ptr->data<<" is in top\n\n"<<endl;
            return ptr->data;
        }
        else
        {
            cout<<"Empty\n\n"<<endl;
            return -1;
        }
    }
    void display()      // display the list
    {
        nodeptr p=head;
        cout<<"\n\t=================X================"<<endl;
        cout<<"\taddress"<<"\t\tdata"<<"\tnext"<<endl;
        while(p!=NULL)
        {
            cout<<"\t"<<p<<"\t"<<p->data<<"\t"<<p->next<<endl;
            p=p->next;
        }
        if(head==NULL)
        {
            cout<<"\tEmpty"<<endl;
        }
        cout<<"\tthats it"<<endl;
        cout<<"\t=================X================\n"<<endl;
    }
};
int main()
{
    linkList li;
    int x,a;
    int choice=-1;
    while(choice!=0)
    {
        cout<<"\n\nyour Choice please: "<<endl;
        cout<<"1-push "<<endl;
        cout<<"2-pop "<<endl;
        cout<<"3-peek "<<endl;
        cout<<"0-Exit\n"<<endl;
        cout<<"\t\tyour choice: ";
        cin>>choice;
        system("CLS");
        cout<<"\tBEFORE LIST";
        li.display();
        switch (choice)
        {
        case 1:
            cout<<"enter data to push: ";
            cin>>x;
            li.push(x);
            break;
        case 2:
            li.pop();
            break;
        case 3:
            li.peek();
            break;
        }
        cout<<"\tAFTER LIST";
        li.display();
    }
    cout<<"\n============X==========="<<endl;
    cout<<"\t THANK YOU "<<endl;
    return 0;
}
