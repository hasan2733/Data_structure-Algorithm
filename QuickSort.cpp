#include <iostream>
#include<vector>
using namespace std;

int partition(vector<int>&a,int st,int end)
{
   int pivot = a[end];
   int idx = st-1;
   for(int i=st;i<end;i++)
   {
     if(a[i]<=pivot)
     {
       idx++;
       swap(a[i],a[idx]);
     }
   }
   idx++;
   swap(a[end],a[idx]);
   return idx;
}
void QuickSort(vector<int>&a,int st,int end)
{
  if(st<end)
  {
   int pivotIdx = partition(a,st,end);
   QuickSort(a,st,pivotIdx-1);
   QuickSort(a,pivotIdx+1,end);
  }
}

int main() 
{
    vector<int> a  = {18,12,6,55,69,8,23};
    QuickSort(a,0,a.size()-1);
    for(int i=0;i<a.size();i++)
    {
      cout<<a[i]<<" ";
    }
}
