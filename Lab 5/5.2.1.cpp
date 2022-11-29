/*Write a recursive program to find N terms Fibonacci series */
#include<iostream>
using namespace std;
int genFibonacci(int n)
{
    int fibo[n+2];
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    return fibo[n];
}
int main ()
{
    int i,n;
    cout << "Enter number of terms: ";
    cin >>n;
    cout<<endl;
    for(i=0;i<=n;i++)
    {
      cout<<genFibonacci(i)<<endl;
    }
    cout<<endl;
    return 0;
}
