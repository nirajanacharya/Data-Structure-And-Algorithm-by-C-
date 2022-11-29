/*WAP to implement STACK using linked list */
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    node* next;
};
class Stack
{
    node *head;
public:
    Stack()
    {
        head = NULL;
    }
    void push()
    {
        int val;
        cout<<endl<<endl<<"enter the value to push: ";
        cin>>val;
        node *newNode = new node;
        newNode->data = val;
        if(head == NULL)
        {
            head = newNode;
            head->next = NULL;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void pop()
    {
        if(head == NULL)
        {
            cout<<endl<<"No value to pop."<<endl;
        }
        else
        {
            node *tmp = head;
            head = head->next;
            cout<<endl<<"the popped value: "<<tmp->data<<endl;
            delete tmp;
        }
    }
    void peek()
    {
        if(head == NULL)
        {
            cout<<endl<<"No value to peek"<<endl;
        }
        else
        {
            cout<<endl<<"The value at top: "<<head->data<<endl;
        }
    }
    void display_stack()
    {
        cout<<endl<<endl<<"Stack: "<<endl;
        node *ptr = head;
        while(ptr != NULL)
        {
            cout<<" "<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<<endl<<endl<<endl;
    }
};
int main()
{
    Stack stackobj;
    int choose;
    do
    {
        cout<<"\n\n1. Push."<<endl;
        cout<<"2. Pop."<<endl;
        cout<<"3. Peek."<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"\n\nChoose an option: ";
        cin>>choose;
        switch (choose)
        {
        case 1:
        {
            stackobj.push();
            break;
        }
        case 2:
        {
            stackobj.pop();
            break;
        }
        case 3:
        {
            stackobj.peek();
            break;
        }
        case 4:
        {
            exit(1);
            break;
        }
        default :
        {
            cout<<"Invalid input";
            break;
        }
        }
        stackobj.display_stack();
    }
    while (choose!=4);
    return 0;
}

