/*Write a recursive program to solve Tower of Hanoi. */
#include <iostream>
using namespace std;
void Hanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        cout << "Move Disk 1 from " << from <<  " to " << to <<endl;
        return;
    }
    Hanoi(n - 1, from, aux, to);
    cout << "Move Disk " << n << " from " << from << " to " << to << endl;
    Hanoi(n - 1, aux, to, from);
}
int main()
{
    int no_of_discs;
    cout << "Enter number of discs : ";
    cin >> no_of_discs;
    cout << endl;
    Hanoi(no_of_discs, 'A','C', 'B');
}
