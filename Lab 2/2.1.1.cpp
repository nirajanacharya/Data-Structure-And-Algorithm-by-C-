/*WAP for array implementation of Linear Queue*/
#include <iostream>
#include <cstdlib>
#define  capacity 9
using namespace std;
template <class X>
class Queue
{
private:
    X data[capacity];
    int front1,rear;
    bool IsEmpty()
    {
        if(front1>rear || front1==-1)
            return true;
        else
            return false;
    }
    bool IsFull()
    {
        if(rear==(capacity-1))
            return true;
        else
            return false;
    }
public:
    Queue():front1(-1),rear(-1) {}
    void enqueue(X var)
    {
        if(IsFull())
            cout<<endl<<"Queue overflow"<<endl;
        else
        {
            if(front1 == -1)
                front1 =0;
            data[++rear]=var;
        }
    }
    void dequeue()
    {
        if(IsEmpty())
            cout<<"\nQueue underflow"<<endl;
        else
            cout<<"\nThe dequeued element is :  "<<data[front1++]<<endl;
    }
    void Front()
    {
        if(IsEmpty())
            cout<<"\nQueue underflow"<<endl;
        else
            cout<<"\nThe front element of queue is : "<<data[front1]<<endl;
    }
};
int main()
{
    Queue <int>Q1;
    int choice;
    while(1)
    {
        cout<<"1.Enqueue\n2.Dequeue\n3.View front element\n4.exit\nEnter your choice  ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            cout<<"Enter the value:  ";
            cin>>choice;
            Q1.enqueue(choice);
            break;
        }
        case 2:
            Q1.dequeue();
            break;
        case 3:
            Q1.Front();
            break;
        default:
            exit(0);
        }
        cout<<"\n\n";
    }
    return 0;
}
