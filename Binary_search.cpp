#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> arr,int n,int target)
{
  // time complexity is O(logn)
  int left=0;
  int right=n-1;
  while(left<=right)
  {
    int mid=(left +right)/2;
    if(arr[mid]>target)
    {
      right=mid-1;
    }
    else if(arr[mid]<target)
    {
      left=mid +1;
    }
    else
    {
      return mid;
    }
  }
  return -1;
}
int recursive_binary_search(vector<int>b ,int n,int target2,int left,int right)
{
  if(left <= right)
  {
    int mid= (left + right)/2;
    if(b[mid]>target2)
    {
      recursive_binary_search(b,n,target2,left,mid-1);
    }
    else if(b[mid] < target2)
    {
      recursive_binary_search(b,n,target2,mid+1,right);
    }
    else
    {
      return mid;
    }
  }
  return -1;
}
int main()
{
  int n;
  cout<<"Enter the size of array : "<<endl;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a.begin(),a.end());
  int target;
  cout<<"Enter your target : "<<endl;
  cin>>target;
  int Bs=binary_search(a,n,target);
  if(Bs == -1)
  {
    cout<<"Element is not found ;) "<<endl;
  }
  else
  {
    cout<<"The element is found !! " <<endl;
    cout<<"The element is : "<< a[Bs]<<endl;
  }
  vector<int>b(n);
  for(int i=0;i<n;i++)cin>>b[i];
  sort(b.begin(),b.end());
  int target2;
  cout<<"Enter your target : "<<endl;
  cin>>target2;
  int left=0,right=n-1;
  int r_Bs= recursive_binary_search(b,n,target2,left,right);
  if(r_Bs==-1)
  {
    cout<<"Element is not found !! "<<endl;
  }
  else
  {
    cout<<"Element is found ans it is :  "<<b[r_Bs]<<endl;
  }
  
}
