/*WAP to implement STACK using linked list */
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int info;
    node *next;
};
class Stack
{
    node *top;
    bool IsEmpty()
    {
        if(top==NULL)
            return true;
        else
            return false;
    }
public:
    Stack():top(NULL) {}
    void push(int num)
    {
        node *temp=new node;
        if(temp==NULL)
            cout<<"\n\nFailed to initialize the new node.\n\n";
        else
        {
            temp->info=num;
            if(top==NULL)
            {
                temp->next=NULL;
                top=temp;
            }
            else
            {
                temp->next=top;
                top=temp;
            }
        }
    }
    void pop()
    {
        if(IsEmpty())
            cout<<"\n\nStack Underflow\n\n";
        else
        {
            node *temp;
            temp=top;
            cout<<"\n\nThe popped element of Stack is :  "<<top->info<<endl<<endl;
            top=top->next;
            delete temp;
        }
    }
    void peek()
    {
        if(IsEmpty())
            cout<<"\n\nStack Underflow\n\n";
        else
            cout<<"\n\nThe top element of Stack is :  "<<top->info<<endl<<endl;
    }
    void displayStack()
    {
        if(IsEmpty())
            cout<<"\n\nStack Underflow\n\n";
        else
        {
            node *temp;
            temp=top;
            cout<<"\n\nElements of Stack are: \n";
            while(temp!=NULL)
            {
                cout<<temp->info<<endl;
                temp=temp->next;
            }
            cout<<"\n\n";
        }
    }
};
int main()
{
    int choice,num;
    Stack s;
    while(1)
    {
        cout<<"1. push\n2. pop\n3. peek\n4. view stack\n5. Exit\n\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            while(1)
            {
                cout<<"\n\nEnter -1 to end push operation\nEnter the value :  ";
                cin>>num;
                if(num==-1)
                    break;
                s.push(num);
            }
            break;
        }
        case 2:
        {
            s.pop();
            break;
        }
        case 3:
        {
            s.peek();
            break;
        }
        case 4:
        {
            s.displayStack();
            break;
        }
        default :
            exit(0);
        }
    }
    return 0;
}
