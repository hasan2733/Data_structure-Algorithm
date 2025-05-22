#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr,int l,int r,int mid)
{
  int n1 = mid-l+1;
  int n2 = r-mid;
   vector<int>a(n1),b(n2);
   for(int i=0;i<n1;i++)
    a[i]=arr[l+i];
   for(int i=0;i<n2;i++)
    b[i]=arr[mid+1+i];
   
   int i=0,j=0,k=0;
   while(i<n1 && j<n2)
   {
     if(a[i]<b[j])
     {
       arr[k]=a[i];
       i++;k++;
     }
     else
     {
       arr[k]=b[j];
       j++;k++;
     }
   }
   while(i<n1)
   {
     arr[k]=a[i];
     i++;k++;
   }
   while(j<n2)
   {
     arr[k]=b[j];
     j++;k++;
   }
}


void Merge_Sort(vector<int>&arr,int l,int r)
{
  if(l<r)
  {
    int mid = (l+r)/2;
    Merge_Sort(arr,l,mid);
    Merge_Sort(arr,mid+1,r);
    merge(arr,l,r,mid);
  }
}


bool Binary_search(vector<int>&arr,int target)
{
  int l = 0;
  int r = arr.size()-1;
  while(l<=r)
  {
    int mid = (l+r)/2;
    if(arr[mid]==target)
     return true;
    else if (arr[mid]<target)
     l = mid+1;
    else
     r = mid-1;
  }
  return false;
}

int main() 
{
    vector<int> arr(10);
    for(int i=0;i<10;i++)
    {
      cin>>arr[i];
    }
    
    Merge_Sort(arr,0,9);
    
    for(int i=0;i<10;i++)
    {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    int target;
    cin>> target;
    
    int f = Binary_search(arr,target);
    
    if(f) 
     cout<<"Found \n";
    else
     cout<<"NOt Found \n";
    
}

// input
// 12 3 18  2  6 19 4 7 13  20
// 19
