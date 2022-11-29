/*WAP for list implementation of QUEUE*/
#include<iostream>
#define max 5
using namespace std;
//define a Queue //
template<class T>
class Queue
{
private:
    int front,rear;
    T arr[max];
    T sign;
public:
    // constructor to initialize front and rear
    Queue(T emptysign)
    {
        front=-1;
        rear=-1;
        sign=emptysign;
        for(int i= 0; i<max; i++)
        {
            arr[i]=sign;
        }
    }
    //isEmpty to check if queue is empty
    bool  isEmpty()
    {
        if (front == - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //to check if Queue is full
    bool isFull()
    {
        if (rear == max - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //enqueue into Queue
    void enq(T data)
    {
        if(!isFull())
        {
            if(front == -1)
                front = 0;
            arr[++rear] = data;
        }
        else
        {
            cout<<"Overflow"<<endl;
        }
    }
    //dequeue from the Queue
    void deq()
    {
        if(!isEmpty())
        {
            cout << arr[front] << endl;
            arr[front++]=0;
            if(front>rear)
            {
                front=-1;
                rear=-1;
            }
        }
        else
        {
            cout<<"UnderFlow"<<endl;
        }
    }
    //display Queue
    void display()
    {
        cout<<"\n ==========="<<endl;
        cout<<"The queue is ==>\t";
        for(int i=0; i<max; i++)
        {
            cout<<arr[i]<<"\t";
        }
        if(front!=-1)
            cout<<"front:: "<<front%max<<"\tlen:: "<<rear-front+1<<endl;
        else
            cout<<"front:: "<<front%max<<"\tlen:: "<<rear-front<<endl;
        cout<<" ===========\n"<<endl;
    }
};
//driver main function
int main()
{
    Queue<int> que(0);
    char opt='a';
    int val;
    cout<<"what to do:\n"<<"d for dequeue:\n"<<"e for enqueue\n"<<"x for display\n"<<"n for end"<<endl;
    while(opt!='n')
    {
        cout<<"your choice: ";
        cin>>opt;
        switch(opt)
        {
        case 'd':
            que.deq();
            break;
        case 'e':
            cout<<"enter value:";
            cin >> val;
            que.enq(val);
            break;
        case 'x':
            que.display();
            break;
        case 'n':
            cout<<"thank you"<<endl;
            break;
        }
    }
    return 0;
}
