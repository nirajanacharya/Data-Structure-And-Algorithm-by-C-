/*WAP to implement priority queue using linked list */
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    int priority;
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
    void enqueue(int n, int priority)
    {
        node *newNode = new node;
        newNode->data = n;
        newNode->priority = priority;
        if(head == NULL)
        {
            head = newNode;
            head->next = NULL;
        }
        else
        {
            node *ptr = head;
            node *preptr = NULL;
            while(ptr->priority < priority)
            {
                preptr = ptr;
                if(ptr->next == NULL)
                {
                    break;
                }
                ptr = ptr->next;
            }
            if(preptr == NULL)
            {
                newNode->next = head;
                head = newNode;
            }
            else if(priority <= ptr->priority)
            {
                preptr->next = newNode;
                newNode->next = ptr;
            }
            else
            {
                newNode->next = ptr->next;
                ptr->next = newNode;
            }
        }
    }
    void dequeue()
    {
        //Sankalpa_Rijal's code
        node *ptr = head;
        cout<<endl<<"The dequeued data is: "<<head->data<<endl;
        head = head->next;
        delete ptr;
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
            int val, priority;
            char trash;
            cout<<"\nEnter push val,priority: ";
            cin>>val>>trash>>priority;
            queueobj.enqueue(val,priority);
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

