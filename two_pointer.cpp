#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
      int n,target;
      cin>>n>>target;
      vector<int>a(n);
      for(int i=0;i<n;i++) cin>>a[i];
      sort(a.begin(),a.end());
      int left = 0;
      int right = n-1;
      int flag = 0 ;
      while(left < right)
      {
        int sum = a[left] + a[right];
        if(sum==target)
        {
          flag = 1;
          break;
        }
        else if(sum > target)
        {
          right--;
        }
        else
        {
          left++;
        }
      }
      if(flag)
        cout<<"Pair Found !\n";
      else
        cout<<"Pair doesn't Found \n";
      
    }
}
