/*WAP to implement priority queue using linked list */
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int info,priority;
    node *next;
};
class PQueue
{
    node *Front,*rear;
    bool IsEmpty();
public:
    PQueue():Front(NULL),rear(NULL) {}
    void enqueue(int,int);
    void dequeue();
    void viewFront();
    void displayPQueue();
};
bool PQueue::IsEmpty()
{
    if(Front==NULL)
        return true;
    else
        return false;
}
void PQueue::enqueue(int data,int pri)
{
    node *temp=new node;
    if(temp==NULL)
        cout<<"\n\nFailed to initialize the memory for new node.\n\n";
    else
    {
        temp->info=data;
        temp->priority=pri;
        if(Front==NULL)
        {
            temp->next=Front;
            Front=rear=temp;
        }
        else if(temp->priority<Front->priority)
        {
            temp->next=Front;
            Front=temp;
        }
        else
        {
            node *ptr;
            ptr=Front;
            while(ptr->next!=NULL && ptr->next->priority<=temp->priority)
                ptr=ptr->next;
            temp->next=ptr->next;
            ptr->next=temp;
            if(temp->next==NULL)
                rear=temp;
        }
    }
}
void PQueue::dequeue()
{
    if(IsEmpty())
        cout<<"\n\nQueue underflow\n\n";
    else
    {
        node *temp;
        temp=Front;
        cout<<"\n\nThe dequeued element with priority is : \nElement = "<<Front->info<<"\tPriority = "<<Front->priority<<"\n\n";
        if(Front==rear)
            Front=rear=NULL;
        else
            Front=Front->next;
        delete temp;
    }
}
void PQueue::viewFront()
{
    if(IsEmpty())
        cout<<"\n\nQueue underflow\n\n";
    else
        cout<<"\n\nThe front element with priority is : \nElement = "<<Front->info<<"\tPriority = "<<Front->priority<<"\n\n";
}
void PQueue::displayPQueue()
{
    if(IsEmpty())
        cout<<"\n\nQueue underflow\n\n";
    else
    {
        node *temp;
        temp=Front;
        cout<<"\n\nElements of Priority Queue are : \nElement\t\tPriority\n";
        while(temp!=NULL)
        {
            cout<<temp->info<<"\t\t"<<temp->priority<<endl;
            temp=temp->next;
        }
        cout<<"\n\n";
    }
}
int main()
{
    int choice,num,priority;
    PQueue q;
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
                cout<<"\nEnter priority for "<<num<<" :  ";
                cin>>priority;
                q.enqueue(num,priority);
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
            q.viewFront();
            break;
        }
        case 4:
        {
            q.displayPQueue();
            break;
        }
        default :
            exit(0);
        }
    }
    return 0;
}
