/*Write a recursive program to find Greatest Common Division GCD of two numbers.*/
#include <iostream>
using namespace std;
int hcf(int n1, int n2)
{
    if (n2 != 0)
        return hcf(n2, n1 % n2);
    else
        return n1;
}
int main()
{
    int n1, n2;
    cout<<"Enter first positive integer: ";
    cin>>n1;
    cout<<"\nEnter second positive integer: ";
    cin>>n2;
    cout<<"\nG.C.D of "<<n1<<" and "<<n2<<" is "<<hcf(n1, n2)<<endl;
    return 0;
}
