#include <bits/stdc++.h>
using namespace std;

//abdul bari yt playlist
int main() 
{
    vector<int>p ={0,1,2,5,6};
    vector<int>wt = {0,2,3,4,5};
    vector<vector<int>> k(5,vector<int>(9,0));
    
    for(int i=0;i<=4;i++)
    {
      for(int w=0;w<=8;w++)
      {
        if(w==0 || i==0)
        {
          k[i][w] = 0;
        }
        else if(wt[i]<=w)
        {
          k[i][w] = max(p[i]+k[i-1][w-wt[i]] , k[i-1][w]);
        }
        else
        {
          k[i][w] = k[i-1][w];
        }
      }
    }
    cout<<"res : "<<k[4][8]<<endl;
    
    int i=4,j=8;
    while(i>0 && j>0)
    {
      if(k[i][j]==k[i-1][j])
      {
        cout<<i<<" is not included\n";
        i--;
      }
      else
      {
        cout<<i<<" is included\n";
        j=j-wt[i];
        i--;
      }
    }
}
