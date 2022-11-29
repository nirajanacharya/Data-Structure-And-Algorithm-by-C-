/*Write a recursive program to find N terms Fibonacci series */
#include<iostream>
using namespace std;
class fibonacci
{
public:
    int nth_term(int n)
    {
        if(n==1)
        {
            return 1;
        }
        else if (n==0)
        {
            return 0;
        }
        else
        {
            return(nth_term(n-1)+nth_term(n-2));
        }
    }
};
int main()
{
    int number;
    cout<<"Enter any integer:\t";
    cin>>number;
    fibonacci f;
    cout<<endl<<number<<"th term of fibonacci series is "<<f.nth_term(number);
}
