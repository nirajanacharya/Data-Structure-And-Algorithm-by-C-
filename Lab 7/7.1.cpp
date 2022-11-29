/*WAP to implement Insertion Sorting Algorithm*/
#include<iostream>
using namespace std;
int main()
{
    int n,key =1;
    cout<<"enter number of items to be sorted:: ";
    cin>>n;
    int arr[n];
    cout<<"enter "<<n<<" items:: "<<endl;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    for(key; key<n; key++)
    {
        int temp,i=key;
        while(arr[i]<arr[i-1] && i>0)
        {
            temp=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=temp;
            i--;
        }
    }
    cout<<"the sorted array is::"<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<endl;
    return 0;
}
