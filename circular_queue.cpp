#include <bits/stdc++.h>
using namespace std;

struct queue1
{
  int size;
  int front;
  int c_size;
  int *arr;
};


struct queue1* MY_queue(int c)
{
  queue1* n = (queue1*)malloc(sizeof(queue1));
  n->arr = (int* )malloc(sizeof(int) * c);
  n->size = c;
  n->front = 0;
  n->c_size = 0;
  return n;
}


int GetRear(queue1* q)
{
  if(q->c_size == 0)
  {
    cout<<"Queue is empty \n";
    return -1;
  }
  int rear = (q->front + q->c_size -1) % q->size;
  return q->arr[rear];
}


int GetFront(queue1* q)
{
  if(q->c_size==0)
  {
    cout<<"Queue is empty \n";
    return -1;
  }
return q->arr[q->front];
}

void push(queue1* q,int val)
{
  if(q->size==q->c_size)
  {
    return;
  }
  int rear = (q->front + q->c_size) % q->size;
  q->c_size++;
  q->arr[rear] = val;
}

void pop(queue1* q)
{
  if(q->c_size==0)
  {
    return ;
  }
  int res = q->arr[q->front];
  q->front = (q->front + 1) % q->size;
  q->c_size--;
  cout<<res <<" ";
}


int main() 
{
    queue1 *q = MY_queue(6);
    push(q,1);
    push(q,2);
    push(q,3);
    push(q,4);
    push(q,5);
    push(q,6);
    
    int c= GetFront(q);
    cout<<c<<endl;
    
    int d =GetRear(q);
    cout<<d<<endl;
    
    
    pop(q);
    pop(q);
    pop(q);
    pop(q);
    pop(q);
    pop(q);
}
