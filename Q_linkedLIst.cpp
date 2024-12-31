#include<bits/stdc++.h>
using namespace std;

class node{
  public :
    int data;
    node *next;
  node(int val)
  {
    data=val;
    next=NULL;
  }
};

class QUEUE
{
  node* front;
  node* back;
  public:
   QUEUE()
   {
     front=NULL;
     back=NULL;
   }
   void push(int x)
   {
     node* n= new node(x);
     if(front==NULL)
     {
       back=n;
       front=n;
       return;
     }
     back->next=n;
     back=n;
   }
   int isEmpty()
   {
     if(front==NULL)
     {
       return 1;
     }
     else
     {
       return 0;
     }
   }
   void pop()
   {
     if(isEmpty())
     {
       cout<<"QUEUE underflow"<<endl;
     }
     else
     {
       node* todel=front;
       front=front->next;
       delete(todel);
     }
   }
   void peek()
   {
     if(!isEmpty())
     {
       cout<<front->data<<endl;
     }
     else
     {
       cout<<"No elements to print"<<endl;
     }
   }
};

int main()
{
  QUEUE q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.peek();
  q.pop();
  q.peek();
  q.pop();
  q.peek();
  q.pop();
  q.peek();
  q.pop();
}
