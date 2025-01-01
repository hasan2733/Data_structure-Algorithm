#include <bits/stdc++.h>
using namespace std;

class que
{
  stack<int>st1;
  stack<int>st2;
  public:
   void push(int x)
   {
     st1.push(x);
   }
   int isEmpty()
   {
     if(st1.empty() && st2.empty())
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
       cout<<"QUEUE is empty \n";
       return;
     }
     if(st2.empty())
     {
       while(!st1.empty())
       {
         st2.push(st1.top());
         st1.pop();
       }
     }
       int topval=st2.top();
       st2.pop();
       cout<< topval<<endl;
   }
};
class stk{
  int n;
  queue<int>q1;
  queue<int>q2;
  
  public:
   stk()
   {
     n=0;
   }
   void push(int x)
   {
     q2.push(x);
     while(!q1.empty())
     {
       q2.push(q1.front());
       q1.pop();
     }
     queue<int>temp;
     temp=q2;
     q2=q1;
     q1=temp;
     n++;
   }
   void pop()
   {
     q1.pop();
     n--;
   }
   void top()
   {
     cout<<q1.front()<<endl;
   }
   void size()
   {
     cout<<n<<endl;
   }
};
int main() 
{
    que q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    stk s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.top();
    cout<<"size : ";
    s.size();
    s.pop();
    s.top();
    cout<<"size : ";
    s.size();
    s.pop();
    s.top();
    cout<<"size : ";
    s.size();
    s.pop();
}
