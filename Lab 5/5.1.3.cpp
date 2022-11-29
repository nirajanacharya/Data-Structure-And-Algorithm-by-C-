/*Write a recursive program to find factorial of a given number */
#include<iostream>
using namespace std;
int factorial(int);
int main()
{
    int n, result;
    cout << "Enter a number: ";
    cin >> n;
    if(n<0)
    {
        cout<<"Error";
        return 0;
        goto D;
    }
    cout<<n;
    result = factorial(n);
    cout <<endl<< "Factorial of " << n << " = " << result;
    D:
    return 0;
}
int factorial(int n)
{
    if (n > 1)
    {
        cout<<" * "<<(n - 1);
        return n * factorial(n - 1);
    }
    else
    {
        return 1;
    }
}
