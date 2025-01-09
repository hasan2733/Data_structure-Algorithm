#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

struct MAXHEAP
{
  int size;
  int data[MAX];
};

void initialize_M_heap(MAXHEAP* h)
{
  h->size = 0;
}

void hepifyUP(MAXHEAP* h,int index)
{
  int parent = (index - 1)/2;
  while(index > 0 && h->data[index] > h->data[parent])
  {
    int temp = h->data[index];
    h->data[index] = h->data[parent];
    h->data[parent] = temp;
    
    index = parent;
    parent = (index - 1)/ 2;
  }
}

void hepifyDOWN(MAXHEAP * h,int index)
{
  int largest = index;
  int leftchild = 2*index + 1;
  int rightchild = 2*index + 2;
  
  if(leftchild < h->size && (h->data[leftchild] > h->data[largest]))
  {
    largest = leftchild;
  }
  if(rightchild < h->size && (h->data[rightchild] > h->data[largest]))
  {
    largest = rightchild;
  }
  
  if(largest != index)
  {
    int temp = h->data[index];
    h->data[index] = h->data[largest];
    h->data[largest] = temp;   
    
    hepifyDOWN(h,largest);
  }
}

void insert(MAXHEAP* h,int val)
{
  if(h->size==MAX)
  {
    cout<<"Heap Overflow \n";
    return ;
  }
  h->data[h->size]=val;
  hepifyUP(h,h->size);
  h->size++;
}

void del_heap(MAXHEAP* h)
{
  if(h->size==0)
  {
    cout<<"Heap, underflow \n";
  }
  int f = h->data[0];
  h->data[0] = h->data[h->size - 1];
  h->size--;
  hepifyDOWN(h,0);
  cout<<"We delete : "<< f <<endl;
}

void print(MAXHEAP* h)
{
  for(int i=0;i<h->size ;i++)
  {
    cout<< h->data[i] <<" ";
  }
  cout<<endl;
}
int main() 
{
   MAXHEAP h;
   initialize_M_heap(&h);
   
   insert(&h,20);
   insert(&h,15);
   insert(&h,7);
   insert(&h,8);
   insert(&h,50);
   insert(&h,18);
   insert(&h,35);
   insert(&h,45);
   print(&h);
   
   del_heap(&h);
   
   print(&h);
   
}
