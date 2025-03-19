#include<bits/stdc++.h>
using namespace std;

#define N 8 
#define INF INT_MAX

int ShortestPath(int graph[N][N])
{
  int dist[N];
  dist[N-1]=0;
  for(int i=N-2;i>=0;i--)
  {
    dist[i]=INF;
    for(int j=0;j<N;j++)
    {
      if(graph[i][j]==INF)
       continue;
      
      dist[i] = min(dist[i],graph[i][j]+dist[j]);  
    }
  }
  return dist[0];
}
/*  Ex: for i is equal 2 posible cases (i,j) form
 1)(2,2) INF
 2)(2,3) INF
 3)(2,4)  dis = min (INF, graph val at (2,4) + 4 to end) 
                          thats (9+18)=27
 4)(2,5) dis = min(27,5+13) = 18
 5)(2,6) dis =min(18,16+2) =18
 6)(2,7) INF
 
 So, minimum distance of 2 is 18
*/
int main()
{                                //use adjacancy matrix
      int graph[N][N] =
      {{INF, 1, 2, 5, INF, INF, INF, INF},
       {INF, INF, INF, INF, 4, 11, INF, INF},
       {INF, INF, INF, INF, 9, 5, 16, INF},
       {INF, INF, INF, INF, INF, INF, 2, INF},
       {INF, INF, INF, INF, INF, INF, INF, 18},
       {INF, INF, INF, INF, INF, INF, INF, 13},
       {INF, INF, INF, INF, INF, INF, INF, 2},
      {INF, INF, INF, INF, INF, INF, INF, INF}};
      
      cout<<ShortestPath(graph);
}
