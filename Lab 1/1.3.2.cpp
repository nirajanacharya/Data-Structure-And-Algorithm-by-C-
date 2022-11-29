/*WAP to check parenthesis of algebraic expression using stack*/
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
            //cout<<"underflow"<<endl;
            return '0';
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
        if(top==-1)
        {
            cout<<"expression is correct"<<endl;
        }
        else
        {
            cout<<"error in expression: "<<top+1<<" \")\" is missing"<<endl;
        }
    }
};
int main()
{
    Stack<char> arr;
    char test;
    string exp;
    cout<<"enter an expression: ";
    getline(cin,exp);
    int i=0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
        {
            arr.push(exp[i]);
        }
        else if(exp[i]==')')
        {
            test=arr.pop();
            if(test=='0')
            {
                cout<<"No \"(\" to pop !!empty Stack"<<endl;
            }
        }
        i++;
    }
    arr.display();
    return 0;
}
