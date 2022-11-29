/*Write a recursive program to find N terms Fibonacci series */
#include <iostream>
using namespace std;
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return (fib(n-1) + fib(n-2));
}
int main()
{
    int number, count = 0;
    cout << "Enter number of terms in series : ";
    cin >> number;
    cout << endl;
    while (count < number)
    {
        cout << fib(count) << " ";
        ++count;
    }
    cout << endl;
}
