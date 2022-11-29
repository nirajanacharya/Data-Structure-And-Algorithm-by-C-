/*WAP to check parenthesis of algebraic expression using stack*/
#include <iostream>
#include <cstring>
#define MAXSIZE 30
using namespace std;
char expression[MAXSIZE],stack[MAXSIZE];
int top=-1;
bool isempty()
{
    if(top == -1)
        return true;
    else
        return false;
}
bool isfull()
{
    if(top == MAXSIZE)
        return true;
    else
        return false;
}
void pop()
{
    char check;
    int cl_sb=0,cr_sb=0,cl_cb=0,cr_cb=0,cl_bb=0,cr_bb=0;
    /*cl_sb count left of small barcket,cr_sb count right of small barcket*/
    /*cl_cb count left of curly barcket,cr_cb count right of curly barcket*/
    /*cl_bb count left of big barcket,cr_bb count right of big barcket*/
    while (!isempty())
    {
        check=stack[top--];
        if (check=='(')
            cl_sb++;
        if (check==')')
            cr_sb++;
        if (check=='{')
            cl_cb++;
        if (check=='}')
            cr_cb++;
        if (check=='[')
            cl_bb++;
        if (check==']')
            cr_bb++;
    }
    if ((cl_sb=cr_sb) && (cl_cb==cr_cb) && (cl_bb==cr_bb))
        cout<<"Expression is balanced.\n";
    else cout<<"Expression is not balanced.\n";
}
void push()
{
    cout<<"Enter expression: ";
    cin>>expression;
    for(int i=0; i<strlen(expression); i++)
    {
        if (!isfull())
        {
            stack[++top]=expression[i];
        }
        else
            cout<<"Expression overflow!!!";
    }
}
int main()
{
    while (1)
    {
        push();
        cout<<"\n";
        pop();
        cout<<"\n";
    }
    return 0;
}


