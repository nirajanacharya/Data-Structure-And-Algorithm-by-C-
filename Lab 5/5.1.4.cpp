/*Write a recursive program to find factorial of a given number */
#include <iostream>
using namespace std;
long long factorial (int number)
{
    if (number == 1)
        return 1;
    else
        return number * factorial(number - 1);
}
int main()
{
    int number;
    cout << "Enter the number : ";
    cin >> number;
    long long result = factorial(number);
    cout << "Factorial of " << number << " is : " << result << endl;
}
