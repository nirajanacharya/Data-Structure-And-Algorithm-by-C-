/*WAP for implementation of Circular Queue*/
#include<iostream>
#include<cstdlib>
#define capacity 4
using namespace std;
template <class X>
class Queue
{
    int front1,rear;
    X data[capacity];
public:
    Queue():front1(-1),rear(-1) {}
    void enqueue(X var)
    {
        if(IsQueuefull())
            cout<<"queue overflow"<<endl;
        else
        {
            rear=(rear+1)%capacity;
            data[rear]=var;
            if(front1 == -1)
                front1 =0;
        }
    }
    void dequeue()
    {
        if(IsEmptyQueue())
            cout<<"queue underflow"<<endl;
        else
        {
            cout<<"\ndequeued element is "<<data[front1]<<endl;
            if(front1==rear)
                front1=rear=-1;
            else
                front1=(front1+1)%capacity;
        }
    }
    bool IsEmptyQueue()
    {
        if(front1 == -1)
            return true;
        else
            return false;
    }
    bool IsQueuefull()
    {
        if((front1==0&&rear==capacity-1)||front1==rear+1)
            return true;
        else
            return false;
    }
    int Queuesize()
    {
        if(IsEmptyQueue())
            return 0;
        else
            return ((capacity-front1+rear)%capacity+1);
    }
    void Front()
    {
        if(IsEmptyQueue())
            cout<<"\nQueue underflow"<<endl;
        else
            cout<<"\nThe front element of queue is : "<<data[front1]<<endl;
    }
};
int main()
{
    Queue <int> q;
    int choice;
    while(1)
    {
        cout<<"1.Enqueue\n2.Dequeue\n3.View front element\n4.Check queue size\n5.exit\nEnter your choice  ";
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
            q.Front();
            break;
        }
        case 4:
        {
            cout<<"\nQueue size is: "<<q.Queuesize();
            break;
        }
        default:
            exit(0);
        }
        cout<<"\n\n";
    }
    return 0;
}
