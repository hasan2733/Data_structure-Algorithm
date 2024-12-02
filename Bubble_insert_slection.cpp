#include<bits/stdc++.h>
using namespace std;

void BUbble_Sort(int a[],int n)
{
  for(int i=0;i<n-1;i++)
  {
    int f=0;
    for(int j=0;j<n-1-i;j++)
    {
      if(a[j]>a[j+1])
      {
        int temp = a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
        f=1;
      }
    }
      if(f==0)
      break;
  }
}
void selection_sort(int a[],int n)
{
  for(int i=0;i<n-1;i++)
  {
    int min_IDX=i;
    for(int j=i+1;j<n;j++)
    {
      if(a[min_IDX]>a[j])
      {
        min_IDX=j;
      }
    }
    swap(a[i],a[min_IDX]);
  }
}
void insertion_sort(int arr[],int n)
{
  for(int i=1;i<n;i++)
  {
    int j=i-1;
    int key=arr[i];
    while(j>=0 && arr[j]>arr[i])
    {
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=key;
  }
// Time Complexity of Insertion Sort
// Best case: O(n) , If the list is already sorted, where n is the number of elements in the list.
// Average case: O(n 2 ) , If the list is randomly ordered
// Worst case: O(n 2 ) , If the list is in reverse order
}
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  int b[n]={9,21,6,2,18};
  BUbble_Sort(arr,n);//Time Complexity: O(n2)
  selection_sort(b,n); //Time Complexity: O(n2)
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<b[i]<<" ";
  }
  cout<<endl;
  int c[5]={5,1,19,72,14};
  insertion_sort(c,n); //Time Complexity: O(n2)
  for(int i=0;i<n;i++)
  {
    cout<<c[i]<<" ";
  }
}
