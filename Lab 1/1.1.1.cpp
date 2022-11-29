/*WAP to show array implementation of stack.*/
#include <iostream>
using namespace std;
int MAXSIZE = 8;
int stack[8];
int top = -1;
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
int peek()
{
    cout<<stack[top]<<endl;
}
void pop()
{
    int data;
    if(!isempty())
    {
        data = stack[top];
        top--;
        cout<<data<<endl;
    }
    else
    {
        cout<<"Could not retrieve data, Stack is empty."<<endl;
    }
}
void push()
{
    int data;
    if (!isfull())
    {
        cout<<"Enter data to push: ";
        cin>>data;
        top++;
        stack[top] = data;
    }
    else
    {
        cout<<"Could not insert data, Stack is full."<<endl;
    }
}
int main()
{
    int a;
    char choice;
    while(1)
    {
        cout<<"Enter followng keys to perform varous operations.\n";
        cout<<"1 for push item in stack.\n";
        cout<<"2 for pop item from stack.\n";
        cout<<"3 for peek first element in stack.\n";
        cin>>a;
        if (a==1)
        {
            push();
        }
        else if (a==2)
        {
            pop();
        }
        else if (a==3)
        {
            peek();
        }
    }
    return 0;
}
