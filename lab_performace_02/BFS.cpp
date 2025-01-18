#include<bits/stdc++.h>
using namespace std;

#define MAX 40

struct vertex
{
  int data;
  bool visited;
};

int que[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int adj[MAX][MAX];

vertex* vertices[MAX];
int vertex_count = 0;

void insert(int val)
{
  que[++rear] = val;
  itemCount++;
}

int del()
{
  int x = que[front];
  front++;
  itemCount--;
  return x;
}

int isEmpty()
{
  return itemCount == 0;
}

void addvertex(int val)
{
  vertex* v = (vertex*)malloc(sizeof(vertex));
  v->data = val;
  v->visited = false;
  vertices[vertex_count++] = v;
}

void addEdge(int start, int end)
{
  adj[start][end] = 1;
  adj[end][start] = 1;
}

void display_vertex(int vertex_index)
{
  cout << vertices[vertex_index]->data << " ";
}

int get_unvisited_vertex_index(int vertex_index)
{
  for(int i = 0; i < vertex_count; i++)
  {
    if(adj[vertex_index][i] == 1 && vertices[i]->visited == false)
    {
      return i;
    }
  }
  return -1;
}

void BFS()
{
  vertices[0]->visited = true;
  display_vertex(0);
  insert(0);
  int unvisitedVertex;

  while (!isEmpty())
  {
    int x = del();
    while ((unvisitedVertex = get_unvisited_vertex_index(x)) != -1)
    {
      vertices[unvisitedVertex]->visited = true;
      display_vertex(unvisitedVertex);
      insert(unvisitedVertex);
    }
  }

  // Reset visited status for all vertices after BFS completion
  for (int i = 0; i < vertex_count; i++)
  {
    vertices[i]->visited = false;
  }
}

int main()
{
   int i, j;

   // Set adjacency matrix to 0
   for(i = 0; i < MAX; i++) {
      for(j = 0; j < MAX; j++) {
         adj[i][j] = 0;
      }
   }

   // Add vertices
   addvertex(0);    //0
   addvertex(1);    //1
   addvertex(2);    //2
   addvertex(3);    //3
   addvertex(4);    //4
   addvertex(5);    //5
   addvertex(6);    //6
   
   // Add edges
   addEdge(0, 1);   
   addEdge(0, 2);   
   addEdge(1, 5);   
   addEdge(2, 3);   
   addEdge(3, 4);   
   addEdge(4, 6);
   addEdge(5, 6);
   addEdge(2, 4);

   // Run BFS
   cout << "\nBreadth First Search: ";
   BFS();
   return 0;  
}
