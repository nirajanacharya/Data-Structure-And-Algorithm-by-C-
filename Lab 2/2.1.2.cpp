/*WAP for array implementation of Linear Queue*/
#include<iostream>
using namespace std;
#define SIZE 5
class Queue
{
    int A[SIZE];
    int Front;
    int Rear;
public:
    Queue()
    {
        Front=-1;
        Rear=-1;
    }
    bool isempty()
    {
        if(Front== -1 && Rear == -1)
            return true;
        else
            return false;
    }
    bool isfull()
    {
        if(Rear == SIZE-1)
            return true;
        else
            return false;
    }
    void enqueue(int value)
    {
        if(isfull())
        {
            cout<<"queue is full"<<endl;
        }
        else
        {
            if(Front==-1)//first element is inserted
            {
                Front=0;
            }
            Rear++;
            A[Rear]= value;
            //inserting value
        }
    }
    void dequeue()
    {
        if(isempty())
        {
            cout<<"Queue is empty\n";
        }
        else if(Front==Rear) //only one element)
        {
            Front=Rear=-1;
        }
        else
        {
            Front++;
        }
    }
    void showfront()
    {
        if(isempty())
        {
            cout<<"Queue is empty\n";
        }
        else
        {
            cout<<"element at front is"<<A[Front];
        }
    }
    void showQueue()
    {
        if(isempty())
        {
            cout<<"Queue is empty\n";
        }
        else
        {
            for (int i=Front; i<=Rear; i++)
            {
                cout<<A[i]<<endl;;
            }
        }
    }
};
void menu()
{
    Queue q;
    char choice;
    while (choice!='3')
    {
        cout<<"\n\n\n\n"<<endl;
        cout<<"___________MENU___________________"<<endl;
        cout<<"1. Enqueue an element\n"<<endl;
        cout<<"2. Dequeue an element\n"<<endl;
        cout<<"3. Display all elements\n"<<endl;
        cout<<"4. Display front elements\n"<<endl;
        cout<<"5. Exit\n"<<endl;
        cout<<"enter a choice \t"<<endl;
        cin>>choice;
        if(choice=='1')
        {
            int n;
            cout<<"Enter an element to be enqueued"<<endl;
            cin>>n;
            cout<<"\n\n\n"<<endl;
            q.enqueue(n);
        }
        else if(choice=='2')
        {
            cout<<"\n\n\n"<<endl;
            q.dequeue();
        }
        else if(choice=='5')
        {
            break;
        }
        else if(choice=='3')
        {
            q.showQueue();
        }
        else if(choice=='4')
        {
            q.showfront();
        }
    }
}
int main()
{
    menu();
}

