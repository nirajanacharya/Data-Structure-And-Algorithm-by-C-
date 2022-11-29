/*WAP to implement QUEUE using linked list */
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    node* next;
};
class prqueue
{
    node *head;
public:
    prqueue()
    {
        head = NULL;
    }
    void enqueue(int n)
    {
        node *ptr = head;
        node *newNode = new node;
        newNode->data = n;
        if(head == NULL)
        {
            head= newNode;
            newNode->next = NULL;
        }
        else
        {
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
    }
    void dequeue()
    {
        if(head == NULL)
        {
            cout<<endl<<endl<<"Underflow!!"<<endl;
        }
        else
        {
            node *ptr = head;
            cout<<endl<<"The dequeued data is: "<<head->data<<endl;
            head = head->next;
            delete ptr;
        }
    }
    void display_prqueue()
    {
        if(head == NULL)
        {
            cout<<"\nThe list is empty!!"<<endl;
        }
        else
        {
            cout<<endl<<endl;
            node *ptr = head;
            while(ptr != NULL)
            {
                cout<<" "<<ptr->data<<" ";
                ptr = ptr->next;
            }
            cout<<endl<<endl;
        }
    }
};
int main()
{
    prqueue queueobj;
    int choose;
    do
    {
        fflush(stdin);
        cout<<"1. Enqueue."<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"\n\n\tChoose an option: ";
        cin>>choose;
        switch (choose)
        {
        case 1:
        {
            int val;
            cout<<"\nEnter push val: ";
            cin>>val;
            queueobj.enqueue(val);
            break;
        }
        case 2:
        {
            queueobj.dequeue();
            break;
        }
        case 3:
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
        queueobj.display_prqueue();
    }
    while (choose != 3);
    return 0;
}

