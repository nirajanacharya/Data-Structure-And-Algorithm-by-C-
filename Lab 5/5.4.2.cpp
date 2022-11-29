/*Write a recursive program to find Greatest Common Division GCD of two numbers.*/
#include <iostream>
using namespace std;
int gcd(int num1, int num2)
{
    if (num2 == 0)
        return num1;
    else
        return gcd(num2, (num1 % num2));
}
int main()
{
    int num1, num2;
    cout << "Enter two numbers : ";
    cin >> num1 >> num2;
    cout << "GCD of " << num1 << " and " << num2 << " is : " << gcd(num1, num2);
    cout << endl;
}
