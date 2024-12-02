#include<bits/stdc++.h>
using namespace std;

void Bubble_sort(int arr[],int n)
{
  bool is_Swap;
  if(n==1)
  {
    return;// base case
  }
  for(int i=0;i<n-1;i++)
  {
    is_Swap=false;
    if(arr[i]>arr[i+1])
    {
      int temp=arr[i];
      arr[i]=arr[i+1];
      arr[i+1]=temp;
      is_Swap=true;
    }
  }
  if(!is_Swap)
  {
    Bubble_sort(arr,n-1);
  }
}
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)cin>>a[i];
  Bubble_sort(a,n);
  cout<<"Your sorted array is : "<<endl;
  for(int i=0;i<n;i++)cout<<a[i]<<" ";
}
