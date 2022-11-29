/*WAP to implement priority queue using linked list */
#include<iostream>
using namespace std;
class linkList
{
    struct Node
    {
        int data;
        int priority;
        Node *next;
    };
    typedef struct Node* nodeptr;
    nodeptr head;
public:
    linkList()      //constructor
    {
        head=NULL;
    }
    void enqueue(int new_data,int pi)     //insert at the rear
    {
        nodeptr p,preptr;
        nodeptr ptr=head;
        preptr=NULL;
        if(head==NULL)
        {
            nodeptr p;
            p=new Node;
            p->data= new_data;
            p->priority=pi;
            p->next=head;
            head=p;
        }
        else
        {
            while(ptr->priority<pi)
            {
                preptr=ptr;
                if(ptr->next==NULL)
                {
                    break;
                }
                ptr=ptr->next;
            }
            if(preptr==NULL)
            {
                p=new Node;
                p->next=ptr;
                p->data=new_data;
                p->priority=pi;
                head=p;
            }
            else if(ptr->priority>=pi)
            {
                p=new Node;
                preptr->next=p;
                p->next=ptr;
                p->data=new_data;
                p->priority=pi;
            }
            else
            {
                p=new Node;
                ptr->next=p;
                p->data =new_data;
                p->priority=pi;
                p->next =NULL;
            }
        }
    }
    int dequeue()            // delete from the front
    {
        nodeptr ptr=head;
        if(head!=NULL)
        {
            head=ptr->next;
            cout<<ptr->data<<" is Dequeued\n\n"<<endl;
            delete ptr;
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
        cout<<"\tadd"<<"\t\t\tprio"<<"\tdata"<<"\tnext"<<endl;
        while(p!=NULL)
        {
            cout<<"\t"<<p<<"\t\t"<<p->priority<<"\t"<<p->data<<"\t"<<p->next<<endl;
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
    int x,p;
    int choice=-1;
    while(choice!=0)
    {
        cout<<"\n\nyour Choice please: "<<endl;
        cout<<"1-Enqueue "<<endl;
        cout<<"2-Dequeue "<<endl;
        cout<<"0-Exit\n"<<endl;
        cout<<"\t\tyour choice: ";
        cin>>choice;
        system("CLS");
        cout<<"\tBEFORE LIST";
        li.display();
        switch (choice)
        {
        case 1:
            cout<<"enter data to insert: ";
            cin>>x;
            cout<<"enter priority: ";
            cin>>p;
            li.enqueue(x,p);
            break;
        case 2:
            li.dequeue();
            break;
        }
        cout<<"\tAFTER LIST";
        li.display();
    }
    cout<<"\n============X==========="<<endl;
    cout<<"\t THANK YOU "<<endl;
    return 0;
}
