#include<bits/stdc++.h>
using namespace std;

#define MAX 100

class queuee
{
  int *arr;
  int front;
  int back;
  
  public:
   queuee()
   {
     arr=new int[MAX];
     front=-1;
     back=-1;
   }
   
   void enqueue(int x)
   {
     if(!isFull())
     {
       arr[++back]=x;
       if(front==-1)
       {
         front++;
       }
     }
     else
     {
       cout<<"Queue overflow"<<endl;
     }
   }
   void removee()
   {
     if(!isEmpty())
     {
       front++;
     }
     else
     {
       cout<<"Queue underflow"<<endl;
     }
   }
   void peek()
   {
     if(!isEmpty())
     {
       cout<<arr[front]<<endl;
     }
     else
     {
       cout<<"Queue is empty"<<endl;
     }
   }
   int isEmpty()
   {
     if(front==-1 || back<front)
     {
       return 1;
     }
     else
     {
       return 0;
     }
   }
   int isFull()
   {
     if(back==MAX-1)
     {
       return 1;
     }
     else
     {
       return 0;
     }
   }
   
};
int main()
{
  queuee q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.peek();
  q.removee();
  q.peek();
  q.removee();
  q.peek();
  q.removee();
  q.peek();
  q.removee();
}
