/*WAP to reverse a list using stack*/
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
    T pop()
    {
        if(top==-1)
        {
            cout<<"underflow"<<endl;
            return -1;
        }
        else
        {
            return data[top--];
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
    int list[5];
    int revlist[5];
    cout<<"enter 5 integers for your list: ";
    for(int i=0; i<5; i++)
    {
        cin>>list[i];
        arr.push(list[i]);
    }
    for(int i=0; i<5; i++)
    {
        revlist[i]=arr.pop();
    }
    cout<<"its reverse is::"<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<revlist[i]<<endl;
    }
    return 0;
}
