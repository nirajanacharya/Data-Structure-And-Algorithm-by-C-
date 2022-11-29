/*Write a recursive program to find Greatest Common Division GCD of two numbers.*/
#include<iostream>
using namespace std;
class GCD
{
public:
    int common_divisor(int n1,int n2)
    {
        if(n1==n2)
        {
            return n1;
        }
        else if (n1>n2)
        {
            return common_divisor(n1-n2,n2);
        }
        else
        {
            return common_divisor(n1,n2-n1);
        }
    }
};
int main()
{
    int number1,number2;
    cout<<"Enter first integer:\t";
    cin>>number1;
    cout<<"Enter second integer:\t";
    cin>>number2;
    GCD g;
    cout<<endl<<"greatest common divisor of "<<number1<<" and "<<number2<<" is "<<g.common_divisor(number1,number2);
}
