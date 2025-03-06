#include<iostream>
#include<vector>
using namespace std;
vector<bool>check(100,false);
vector<double>res(100,0);

double factorial(int n)
{
    if(n==1 || n==0)
    {
        return 1;
    }
    if(check[n])
    {
        return res[n];
    }
    res[n] = n*factorial(n-1);
    check[n] = true;
    return res[n];
}

int main()
{
    vector<double>a;
    a.push_back(3);
    a.push_back(6);
    a.push_back(5);
    a.push_back(12);
    a.push_back(9);
    a.push_back(13);

    int n = a.size();

    for(int i=0;i<n;i++)
    {
        cout<<"Factorial of " << a[i] <<" is : "<<factorial(a[i])<<endl;
    }
}
