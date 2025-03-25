#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int main()
{
    int n,w;
    cin>>n>>w;
    vector<double>val(n),wt(n);
    for(int i=0; i<n; i++)
    {
        cin>>val[i]>>wt[i];
    }
    vector<pair<double,double>>profit(n);
    for(int i=0; i<n; i++)
    {
        double x = val[i]/wt[i];
        profit[i].first = x;
        profit[i].second = wt[i];
    }
    sort(profit.rbegin(),profit.rend());
    int k = w;
    double sum=0;
    for(int i=0; i<n; i++)
    {
        int b = profit[i].second;
        if(b<=k)
        {
            sum+=b*profit[i].first;
            k-=b;
        }
        else
        {
            sum+=k*profit[i].first;
            break;
        }
    }
    cout<<sum<<endl;
}
