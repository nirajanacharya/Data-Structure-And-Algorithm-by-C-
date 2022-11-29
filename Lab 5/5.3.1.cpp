/*Write a recursive program to solve Tower of Hanoi. */
#include<iostream>
#include <cmath>
using namespace std;
void TowerOfHanoi(int num,char A,char B,char C)
{
    if(num>0)
    {
        TowerOfHanoi(num-1, A, C, B);
        cout<<"Move a disk "<<num<<" from "<<" "<<A<<" to"<<" "<<C<<endl;
        TowerOfHanoi( num-1, B, A, C);
    }
}
int main()
{
    int numOfDisk;
    cout<<"Enter the no. of disks: ";
    cin>>numOfDisk;
    cout<<endl;
    cout<<"Number of steps = "<<pow(2,numOfDisk)-1;
    cout<<endl<<endl;
    TowerOfHanoi(numOfDisk,'A','B','C');
    cout<<endl;
}
