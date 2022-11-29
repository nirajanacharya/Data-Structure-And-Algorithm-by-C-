/*WAP to implement QUEUE using linked list */
#include<iostream>
using namespace std;
class Queue
{
    struct node
    {
        int data;
        struct node * next;
    };
public:
    struct node * start;
    struct node * newnode,* temp,* ptr,*Front,*Rear;
    void creation()
    {
        Front=Rear=NULL;
        newnode = new node;
        cout<<"Enter the data for the queue(insert -1 to end the ): ";
        cin>>newnode->data;
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
        do
        {
            enqueue();
            Front= start;
        }
        while (newnode->data!=-1);
    }
    void enqueue()
    {
        newnode=new node;
        cout<<"Enter the data to be stored in the queue: ";
        cin>>newnode->data;
        if (newnode->data!=-1)
        {
            ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->next=NULL;
            Rear=newnode;
        }
    }
    void dequeue()
    {
        ptr=start->next;
        delete start;
        start=ptr;
        Front=start;
    }
    void display_queue()
    {
        ptr=start;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"\n\nThe queue is: "<<endl;
        cout<<"\t\t"<<ptr->data;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            cout<<"\t"<<ptr->data;
        }
        cout<<endl;
        cout<<"Front: "<<Front->data<<endl;
        cout<<"Rear: "<<Rear->data<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
    }
};
int main()
{
    class Queue q;
    q.start=NULL;
    int choice=0,c=0;
    while(choice!=10)
    {
        c++;
        cout<<"\n\nyour Choice please: "<<endl;
        if (c==1)
        {
            cout<<"0-Creating a new queue "<<endl;
        }
        cout<<"1-Enqueue "<<endl;
        cout<<"2-Dequeue "<<endl;
        cout<<"10-Exit.\n"<<endl;
        cout<<"\t\tyour choice: ";
        cin>>choice;
        switch (choice)
        {
        case 0:
            q.creation();
            break;
        case 1:
            q.enqueue();
            break;
        case 2:
            q.dequeue();
            break;
        }
        q.display_queue();
    }
    cout<<"THANK YOU";
}
