#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<"HOW MANY PERSON ? "<<endl;
    int n;
    cin>>n;
    string s[n][3];
    //1st index name ,2nd index id,3rd index cgpa
    for(int i=0;i<n;i++)
    {
        cout<<"Give name,id,and roll for person "<<i+1<<endl;
        for(int j=0;j<3;j++)
        {
            cin>>s[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j==0)
            {
                cout<<"The name of person "<<i+1<<" is: "<<s[i][j]<<endl;
            }
            else if(j==1)
            {
                cout<<"The id of person "<<i+1<<" is: "<<s[i][j]<<endl;
            }
            else if(j==2)
            {
                cout<<"The cgpa of person "<<i+1<<" is: "<<s[i][j]<<endl;
            }
        }
    }
    //searching ;)
    cout<<"ENTER NAME of THE PERSON..........."<<endl;
    int f;
    string trg;
    cin>>trg;
    for(int i=0;i<n;i++)
    {
     if(s[i][0]==trg)
     {
         f=i;
         break;
     }
    }
    cout<<"THE NAME IS "<<s[f][0]<<" AND ID IS "<<s[f][1]<<" CGPA IS "<<s[f][2]<<endl;
    return 0;
}
