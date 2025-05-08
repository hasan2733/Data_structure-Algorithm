#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

void add_edge(vector<vector<int>>&adjmat,int u,int v,int wt)
{
        adjmat[u][v]=wt;
        adjmat[v][u]=wt;
}
void del_edge(vector<vector<int>>&adjmat,int u,int v,int wt)
{
        adjmat[u][v]=0;
        adjmat[v][u]=0;
}
int main()
{
    int vertices,edges;
    cin>>vertices>>edges;
    vector<vector<int>>adjmat(vertices,vector<int>(vertices,0));
    for(int i=0;i<edges;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(adjmat,u,v,wt);
    }
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
            cout<<setw(3)<<adjmat[i][j]<<" ";
        cout<<endl;
    }
}


/*  A graph below :
5  number of vertices
6  number of edges
0 1 2   (source,destination weight)
0 2 3
1 2 15
1 3 2
2 4 13
3 4 9
*/





