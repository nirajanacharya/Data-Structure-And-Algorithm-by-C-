/*WAP for list implementation of QUEUE*/
#include<iostream>
#define max 4
using namespace std;
class Queue
{
    int avail;
    int front, rear;
    struct nodeType
    {
        int info, next;
    };
    struct nodeType node[max];
public:
    Queue()
    {
        avail=0;
        front=-1;
        rear=-1;
    }
    void initializelist()
    {
        for(int i=0; i<max; i++)
        {
            node[i].next=i+1;
            node[i].info=0;
        }
        node[max-1].next=-1;
    }
    int getnode()
    {
        int ptr;
        if (rear==max-1 && front==-1)
        {
            avail=0;
            rear=-1;
            initializelist();
        }
        ptr=avail;
        avail=node[ptr].next;
        return ptr;
    }
    void freenode(int p)
    {
        node[p].next = avail;
        avail=p;
    }
    bool isfull()
    {
        if (rear==max-1 && avail==-1)
        {
            cout<<"Overflow"<<endl;
            return true;
        }
        else
            return false;
    }
    bool isempty()
    {
        if ((rear<front)||(front>max-1))
        {
            cout<<" Queue Underflow"<<endl;
            return true;
        }
        else
            return false;
    }
    void enqueue()
    {
        int num,ptr;
        if (!(isfull()))
        {
            cout<<"Enter the number:\t";
            cin>>num;
            cout<<"\n";
            ptr=getnode();
            node[ptr].info=num;
            node[ptr].next=-1;
            //cout<<"Ptr value="<<ptr<<endl;
            cout<<node[ptr].info<<" is enqueued."<<endl;
            if (rear==-1)
            {
                front=ptr;
            }
            else
            {
                bool test=true;
                int temp=0;
                while(test)
                {
                    if (node[temp].next==-1)
                    {
                        node[temp].next=ptr;
                        test=false;
                    }
                    temp=node[temp].next;
                }
            }
            rear=ptr;
        }
    }
    void dequeue()
    {
        int delval,ptr;
        if(!isempty())
        {
            delval= node[front].info;
            cout<<delval<<" is dequeued."<<endl;
            node[front].info=0;
            ptr = front;
            front = node[front].next;
            //if(front==-1)
            //  rear = -1;
            freenode(ptr);
        }
    }
    void display()
    {
        //cout<<"--------------------------------------"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"Front"<<front<<endl;
        cout<<"Rear="<<rear<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tavail= "<<avail<<endl;
        cout<<"Node\t\t\t\t\tInfo\t\t\t\t\tNext"<<endl;
        for (int i=0; i<max; i++)
        {
            cout<<i<<"\t\t\t\t\t"<<node[i].info<<"\t\t\t\t\t"<<node[i].next<<endl;
        }
        cout<<"--------------------------------------"<<endl;
        //cout<<"--------------------------------------"<<endl;
    }
};
int main()
{
    int option;
    Queue qobj;
    qobj.initializelist();
    do
    {
        cout<<"Choose:\n1.Enqueue\n2.Dequeue\n3.Exit"<<endl;
        cin>>option;
        switch (option)
        {
        case 1:
            {
                qobj.enqueue();
                break;
            }
        case 2:
            {
                qobj.dequeue();
                break;
            }
        default:
            {
                cout<<"****************Exiting**************"<<endl;
            }
        }
        qobj.display();
    }
    while(option!=3);
    return 0;
}
