/*WAP to implement QUEUE using linked list */
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int info;
    node *next;
};
class Queue
{
    node *Front,*rear;
    bool IsEmpty()
    {
        if(Front==NULL)
            return true;
        else
            return false;
    }
public:
    Queue()
    {
        Front=rear=NULL;
    }
    void enqueue(int num)
    {
        node *temp=new node;
        if(temp==NULL)
            cout<<"\n\nFailed to initialize the new node.\n\n";
        else
        {
            temp->info=num;
            temp->next=NULL;
            if(Front==NULL)
                Front=temp;
            else
                rear->next=temp;
            rear=temp;
        }
    }
    void dequeue()
    {
        if(IsEmpty())
            cout<<"\n\nQueue Underflow\n\n";
        else
        {
            node *temp;
            temp=Front;
            cout<<"\n\nThe dequeued element is :  "<<temp->info<<endl<<endl;
            if(Front==rear)
                Front=rear=NULL;
            else
                Front=Front->next;
            delete temp;
        }
    }
    void viewfront()
    {
        if(IsEmpty())
            cout<<"\n\nQueue Underflow\n\n";
        else
            cout<<"\n\nThe front element of queue is :  "<<Front->info<<"\n\n";
    }
    void dispalyQueue()
    {
        if(IsEmpty())
            cout<<"\n\nQueue Underflow\n\n";
        else
        {
            node *temp;
            temp=Front;
            cout<<"\n\nElements of queue are : "<<endl;
            while(temp!=NULL)
            {
                cout<<temp->info<<"\t";
                temp=temp->next;
            }
            cout<<"\n\n";
        }
    }
};
int main()
{
    int choice,num;
    Queue q;
    while(1)
    {
        cout<<"1. Enqueue\n2. Dequeue\n3. View front element\n4. View queue\n5. Exit\n\nEnter your choice :  ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            while(1)
            {
                cout<<"\nEnter -1 to finish enqueue\nEnter the value:  ";
                cin>>num;
                if(num==-1)
                    break;
                q.enqueue(num);
            }
            break;
        }
        case 2:
        {
            q.dequeue();
            break;
        }
        case 3:
        {
            q.viewfront();
            break;
        }
        case 4:
        {
            q.dispalyQueue();
            break;
        }
        default :
            exit(0);
        }
    }
    return 0;
}
