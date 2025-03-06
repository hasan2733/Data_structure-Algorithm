#include <iostream>
#include<vector>
using namespace std;
vector<bool>check(100,false);
vector<long long>res(100,0);
long long fib(int n)
{
  if(n<=1)
  {
    return n;
  }
  if(check[n])
  {
    return res[n];
  }
  res[n] = fib(n-2)+fib(n-1);
  check[n] = true;
  return res[n];
}
int main() 
{
    vector<long long>a;
    a.push_back(16);
    a.push_back(19);
    a.push_back(5);
    a.push_back(22);
    a.push_back(108);
    a.push_back(17);
    
    for(int i=0;i<a.size();i++)
    {
      cout<<"Fibonacci of : "<<a[i]<<" is -> "<<fib(a[i])<<endl;
    }
}
