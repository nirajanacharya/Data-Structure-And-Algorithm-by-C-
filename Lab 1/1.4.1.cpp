/*WAP to convert infix to postfix using Stack*/
#include<iostream>
#include<cstring>
using namespace std;
//char stack
char stack[50];
int top = -1;
void push(char item)
{
    stack[++top] = item;
}
char pop()
{
    return stack[top--];
}
//returns precedence of operators
int precedence(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 2;
        break;
    case '*':
    case '/':
        return 3;
        break;
    case '$':
        return 4;
        break;
    case '(':
    case ')':
    case '#':
        return 1;
        break;
    }
}
//check whether the symbol is operator?
int isOperator(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '$':
    case '(':
    case ')':
        return 1;
        break;
    default:
        return 0;
    }
}
//converts infix expression to postfix
void convert(char infix[], char postfix[])
{
    int i, symbol, j = 0;
    stack[++top] = '#';
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if (isOperator(symbol) == 0)
        {
            postfix[j] = symbol;
            j++;
        }
        else
        {
            if (symbol == '(')
            {
                push(symbol);
            }
            else
            {
                if (symbol == ')')
                {
                    while (stack[top] != '(')
                    {
                        postfix[j] = pop();
                        j++;
                    }
                    pop();//pop out (.
                }
                else
                {
                    if (precedence(symbol) > precedence(stack[top]))
                    {
                        push(symbol);
                    }
                    else
                    {
                        while (precedence(symbol) <= precedence(stack[top]))
                        {
                            postfix[j] = pop();
                            j++;
                        }
                        push(symbol);
                    }
                }
            }
        }
    }
    while (stack[top] != '#')
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';//null terminate string.
}
//int stack
int stack_int[50];
int top_int = -1;
void push_int(int item)
{
    stack_int[++top_int] = item;
}
char pop_int()
{
    return stack_int[top_int--];
}
int main()
{
    char infix[50], postfix[50];
    cout << "Use '+'  ,  '-'  , '*', '/' and '$' (for exponentiation)." << endl;
    cout << "Enter Infix Expression."<<endl;
    cin >> infix;
    convert(infix, postfix);
    cout << "Infix expression is: " <<endl<< infix << endl;
    cout << "Postfix expression is: " <<endl<< postfix << endl;
    return 0;
}

