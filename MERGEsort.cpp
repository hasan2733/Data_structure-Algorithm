#include <iostream>
#include<vector>
using namespace std;

void Merge(vector<int>&a,int st,int mid,int end)
{
  vector<int>temp;
  int i=st;
  int j=mid+1;
  while(i<=mid && j<=end)
  {
    if(a[i]<=a[j])
    {
      temp.push_back(a[i]);
      i++;
    }
    else
    {
      temp.push_back(a[j]);
      j++;
    }
  }
  while(i<=mid)
  {
    temp.push_back(a[i]);
    i++;
  }
  while(j<=mid)
  {
    temp.push_back(a[j]);
    j++;
  }
  for(int idx=0;idx<temp.size();idx++)
  {
    a[st+idx]=temp[idx];
  }
}
void mergeSort(vector<int>&a,int st,int end)
{
  if(st<end)
  {
    int mid = st + (end-st)/2;
    mergeSort(a,st,mid);
    mergeSort(a,mid+1,end);
    Merge(a,st,mid,end);
  }
}


int main() 
{
    vector<int>b = {19,21,38,12,46,18};
    mergeSort(b,0,b.size()-1);
    for(int i=0;i<b.size();i++)
    {
      cout<<b[i]<<" ";
    }
}
