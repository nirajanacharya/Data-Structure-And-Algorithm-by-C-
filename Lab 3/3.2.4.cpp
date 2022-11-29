/*WAP for list implementation of QUEUE*/
#include<iostream>
#include<cstdlib>
#define MAX 15
using namespace std;
int avail =0;
struct nodetype
{
    int info,next;
};
class Queue
{
    nodetype node[MAX];
    int Front,rear;
    int getnode()
    {
        int p;
        if(avail==-1)
        {
            cout<<"\nOverflow\n\n";
            return -1;
        }
        p=avail;
        avail=node[avail].next;
        return p;
    }
    void freenode(int p)
    {
        node[p].info=-11; /** -11 denotes empty*/
        node[p].next=avail;
        avail=p;
    }
    bool Isempty()
    {
        if(rear==-1)
            return true;
        else
            return false;
    }
public:

    Queue():Front(-1),rear(-1)
    {
        for(int i=0; i<=MAX-1; i++)
        {
            node[i].info=-11;  /** -11 denotes empty*/
            node[i].next=i+1;
        }
        node[MAX-1].next=-1;
    }
    void enqueue(int num)
    {
        int ptr;
        ptr = getnode();
        if(ptr==-1)
            cout<<"\nThere is no available node\n";
        else
        {
            node[ptr].info=num;
            node[ptr].next = -1;
            if(rear== -1)
                Front=rear= ptr;
            else
                node[rear].next = ptr;
            rear = ptr;
        }
    }
    void dequeue()
    {
        if(Isempty())
            cout<<"\nQUEUE Underflow\n";
        else
        {
            int delval,ptr;
            delval = node[Front].info;
            cout<<"\nThe dequeued element is : "<<delval<<endl;
            ptr = Front;
            Front = node[Front].next;
            if(Front==-1)
                rear = -1;
            freenode(ptr);
        }
    }
    void displayqueue()
    {
        if(Isempty())
            cout<<"\nQUEUE Underflow\n";
        else
        {
            int point=Front;
            cout<<"\nThe queue is:\n";
            while(node[point].next!=-1)
            {
                cout<<node[point].info<<"\t";
                point=node[point].next;
            }
            cout<<node[point].info<<"\n\n";
        }
    }
    void displayarr()
    {
        cout<<"\n\nIndex\tValue\tNext\n";
        for(int i=0; i<MAX; i++)
        {
            cout<<i<<"\t"<<node[i].info<<"\t"<<node[i].next<<endl;
        }
        cout<<endl;
    }
};
int main()
{
    Queue q;
    int choice,num;
    while(1)
    {
        cout<<"1. Enqueue\n2. Dequeue\n3. Display queue\n4. Display array\n5. Exit\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            while(1)
            {
                int num;
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
            q.displayqueue();
            break;
        }
        case 4:
        {
            q.displayarr();
            break;
        }
        default :
            exit(0);
        }
    }
}
