#include <bits/stdc++.h>
using namespace std;

void TowerOfhanoi(int n, char src , char des ,char helper)
{
  if(n==0)
  {
    return;
  }
  TowerOfhanoi(n-1,src,helper,des);
  cout<<"Move  disk "<< n <<" from "<<src <<" To " << des <<endl;
  TowerOfhanoi(n-1,helper,des,src);
}
int main() 
{
    int n;
    cin>>n;
    char a='A',b='B',c='C';
    TowerOfhanoi(n,a,c,b);
}
