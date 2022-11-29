/*WAP to reverse a list using stack*/
#include <iostream>
#define MAXSIZE 8
using namespace std;
int stack[MAXSIZE];
int top = -1,data;
int isempty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
int isfull()
{
    if(top == MAXSIZE)
        return 1;
    else
        return 0;
}
void pop()
{
    cout<<"Reverse list is \n";
    while (!isempty())
    {
        data=stack[top];
        top--;
        cout<<data<<endl;
    }
}
void push()
{
    if (!isfull())
    {
        cout<<"Enter data to push: ";
        cin>>data;
        top++;
        stack[top]=data;
    }
    else
    {
        cout<<"Could not insert data, Stack is full."<<endl;
    }
}
int main()
{
    int a;
    while(1)
    {
        cout<<"Enter following keys to perform various operations.\n";
        cout<<"1 for push item in stack.\n";
        cout<<"2 reverse your list.\n";
        cin>>a;
        if (a==1)
        {
            push();
        }
        else if (a==2)
        {
            pop();
        }
        cout<<endl<<endl;
    }
    return 0;
}
