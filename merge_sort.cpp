#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int l,int r,int mid)
{
  int n1=mid-l+1;
  int n2=r-mid;
  int a[n1],b[n2];
  for(int i=0;i<n1;i++)
  {
    a[i]=arr[l+i];
  }
  for(int i=0;i<n2;i++)
  {
    b[i]=arr[mid+1+i];
  }
  int i=0,j=0;
  while(i<n1 && j<n2)
  {
    if(a[i]<b[j])
    {
      arr[l]=a[i];
      l++;
      i++;
    }
    else if(a[i]>b[j])
    {
      arr[l]=b[j];
      l++;
      j++;
    }
  }
  while(i<n1)
  {
      arr[l]=a[i];
      l++;
      i++;
  }
  while(j<n2)
  {
      arr[l]=b[j];
      l++;
      j++;
  }
}
void mergeSort(int arr[],int l,int r)
{
  if(l<r)
  {
   int mid=(l+r)/2;
   mergeSort(arr,l,mid);
   mergeSort(arr,mid+1,r);
   merge(arr,l,r,mid);
  }
}

int main()
{
  int n;
  cout<<"Enter the size of array : "<<endl;
  cin>>n;
  int ary[n];
  for(int i=0;i<n;i++)cin>>ary[i];
  int l=0,r=n-1;
  mergeSort(ary,l,r);
  for(int i=0;i<n;i++)cout<<ary[i]<<" ";
}
