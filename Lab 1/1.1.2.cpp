/*WAP to show array implementation of stack.*/
#include<iostream>
#define max 10
using namespace std;
template<class T>
class Stack
{
    T data[max];
    int top;
public:
    Stack():top(-1) {}
    void push(T value)
    {
        if(top==max-1)
        {
            cout<<"overflow"<<endl;
        }
        else
            data[++top]=value;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"underflow"<<endl;
        }
        else
        {
            cout<<data[top--]<<" is poped" <<endl;
        }
    }
    void peek()
    {
        if(top==-1)
        {
            cout<<"underflow"<<endl;
        }
        else
        {
            cout<<data[top]<<" is in top"<<endl;
        }
    }
    void display()
    {
        cout<<"------------------XX---------------"<<endl;
        for(int i=top; i>-1; i--)
        {
            cout<<data[i]<<endl;
        }
        cout<<"------------------XX---------------"<<endl;
    }
};
int main()
{
    Stack<int> arr;
    int val;
    int choice=-1;
    while(choice!=0)
    {
        cout<<"choose::"<<endl;
        cout<<"\t1-push"<<endl;
        cout<<"\t2-pop"<<endl;
        cout<<"\t3-peek"<<endl;
        cout<<"\t4-display stack"<<endl;
        cout<<"\t0-exit"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"enter a value: ";
            cin>>val;
            arr.push(val);
            break;
        case 2:
            arr.pop();
            break;
        case 3:
            arr.peek();
            break;
        case 4:
            arr.display();
            break;
        case 0:
            cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
            cout<<"\tTHANKS"<<endl;
            cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
            break;
        }
    }
    return 0;
}
