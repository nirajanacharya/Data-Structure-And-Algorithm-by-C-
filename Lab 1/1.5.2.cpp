//WAP to evaluate postfix expression using Stack
#include<iostream>
#include<string>
#include<cmath>
#define max 15
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
        }
        else
        {
            return data[top--];
        }
    }
    T peek()
    {
        if(top==-1)
        {
            cout<<"underflow"<<endl;
        }
        else
        {
            return data[top];
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
Stack<char>converter;
Stack<int>calculator;
// Switch cases for operator
int calculate_result(int x,int y,char symbol)
{
    switch(symbol)
    {
    case '+' :
        return x+y;
    case '-' :
        return x-y;
    case '*':
        return x*y;
    case '$':
        return pow(x,y);
    case '/':
        return x/y;
    }
    return 0;
}
//evaluation of postfix  expression
void calculate(string postfix)
{
    int a,b;
    int result=0;
    string data;
    for(int i=0; i<postfix.length(); i++)
    {
        if(postfix[i] =='*' || postfix[i] =='+' || postfix[i] =='-' || postfix[i] =='$'||postfix[i] =='/')
        {
            a=calculator.pop();
            b=calculator.pop();
            result=calculate_result(b,a,postfix[i]);
            calculator.push(result);
        }
        else
        {
            if (postfix[i]=='_') {;}
            else if (postfix[i+1] != '_')
            {
                data+=postfix[i];
            }
            else
            {
                data+=postfix[i];
                calculator.push(stof(data));
                data.clear();
            }
        }
    }
    cout<<result<<endl;
}
//precision check
int precision_check(char x)
{
    if(x=='$')
    {
        return 3;
    }
    else if(x=='*' || x=='/')
    {
        return 2;
    }
    else if(x=='+' || x=='-')
    {
        return 1;
    }
    else
    {
        return NULL;
    }
}
//infix expression to postfix expression
//12+24+45
//12_24_+_45_+
string infix_to_postfix(string expression)
{
    string postfix;
    char y;
    converter.push('(');
    for(auto x:expression)
    {
        if(x =='(')
        {
            converter.push(x);
        }
        else if(x == ')')
        {
            while(converter.peek() != '(')
            {
                y=converter.pop();
                postfix+='_';
                postfix+=y;
            }
            converter.pop();
        }
        else if(x =='*' || x =='+' || x =='-' || x =='$' || x=='/')
        {
            postfix+='_';
            if(converter.peek() =='(' )
            {
                converter.push(x);
            }
            else if(precision_check(x)>precision_check(converter.peek()))
            {
                converter.push(x);
            }
            else
            {
                y=converter.pop();
                postfix+=y;
                converter.push(x);
            }
        }
        else
        {
            postfix+=x;
        }
    }
    //cout<<"test-1:"<<postfix<<endl;
    calculate(postfix);
    return postfix;
}
//driver function
int main()
{
    string expression;
    cout<<"Enter your expression eg:(10+20) :: "<<endl;
    getline(cin,expression);
    expression+=')';
    string x=infix_to_postfix(expression);
//cout<<x<<endl;
}
