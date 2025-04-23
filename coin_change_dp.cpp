#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin>>n;
    double x;
    cin>>x;
    int target = round(x*100);
    vector<int>coins(n);
    for(int i=0;i<n;i++)
    {
      double val;
      cin>>val;
      coins[i] = round(val*100);
    }
    vector<int>minDP(target+1,INT_MAX);
    minDP[0] = 0;
    for(int i=1;i<=target;i++)
    {
      for(auto cn:coins)
      {
        if(cn<=i && minDP[i-cn]!=INT_MAX)
        {
          minDP[i] = min(minDP[i],minDP[i-cn]+1);
        }
      }
    }
    if(minDP[target]==INT_MAX)
    {
      cout<<"-1\n";
    }
    else
    {
      cout<<minDP[target]<<endl;
    }
}
