/*Write a recursive program to solve Tower of Hanoi*/
#include<bits/stdc++.h>
using namespace std;
void tower(int n,string s,string a, string d)
{
   if(n==1)
   {
       cout<<s<<" to "<<d<<endl;
       return;
   }
   tower(n-1,s,d,a);

   cout<<s<<"   to   "<<d<<endl;
   tower(n-1,a,s,d);
}
int main()
{
    int n;
    cout<<"enter no. of disks  ";
    cin>>n;
    tower(n,"source","auxillary","destination");
}
