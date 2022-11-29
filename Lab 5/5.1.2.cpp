/*Write a recursive program to find factorial of a given number*/
#include<iostream>
using namespace std;
class factorial
{
public:
    unsigned long long int fact(int n)
    {
        if(n==1)
        {
            return 1;
        }
        else
        {
            return n*fact(n-1);
        }
    }
};
int main()
{
    int number;
    cout<<"Enter any integer:\t";
    cin>>number;
    factorial f;
    cout<<endl<<"Factorial of "<<number<<" is "<<f.fact(number);
}
