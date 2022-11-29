/*WAP for implementation of Circular Queue*/
#include <iostream>
#define MAX 4
using namespace std;
int front=-1,rear=-1,data,queue[MAX];
void push()
{
    if ((front == 0 && rear == MAX-1) || (front == rear+1))
    {
        cout<<"Queue Overflow \n";
        return;
    }
    if (front == -1 && rear==-1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == MAX - 1)
            rear = 0;
        else
            rear = rear + 1;
    }
    cout<<"Enter value to push: ";
    cin>>data;
    queue[rear] = data ;
}
void pop()
{
    if (front == -1)
    {
        cout<<"Queue Underflow\n";
        return ;
    }
    cout<<"Element dequeued from Circural queue is : "<<queue[front]<<endl;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == MAX - 1)
            front = 0;
        else
            front = front + 1;
    }
}
void display()
{
    {
        int f = front, r = rear;
        if (front == -1)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Queue elements are :\n";
        if (f <= r)
        {
            while (f <= r)
            {
                cout<<queue[f]<<" ";
                f++;
            }
        }
        else
        {
            while (f <= MAX - 1)
            {
                cout<<queue[f]<<" ";
                f++;
            }
            f = 0;
            while (f <= r)
            {
                cout<<queue[f]<<" ";
                f++;
            }
        }
        cout<<endl;
    }
}
int main()
{
    int ch;
    cout << "1) Insert element to circular queue" << endl;
    cout << "2) Delete element from circular queue" << endl;
    cout << "3) Display all the elements of ciruclar queue" << endl;
    cout << "4) Exit" << endl;
    do
    {
        cout << "Enter your choice: ";
        cin >> ch;
        cout<<endl;
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
        cout<<endl<<endl<<endl;
    }
    while (ch != 4);
    return 0;
}
