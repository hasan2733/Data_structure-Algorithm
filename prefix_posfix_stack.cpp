#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int stk[MAX];
int top=-1;
int is_empty1()
{
  if(top==-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int is_full()
{
  if(top==MAX-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
void push(int data)
{
  if(!is_full())
  {
    top++;
    stk[top]=data;
  }
  else
  {
    cout<<"stack overflow "<<endl;
    exit(1);
  }
}
int pop()
{
  if(is_empty1())
  {
    cout<<"stack underflow"<<endl;
  }
  else
  {
    int val=stk[top];
    top--;
    return val;
  }
}
int prefix_evalution(string s)
{
    int len=s.size();
    for(int i=len-1;i>=0;i--)
    {
      if(s[i]>='0'&&s[i]<='9')
      {
        push(s[i]-'0');
      }
      else
      {
        int op1=pop();
        int op2=pop();
        switch (s[i])
        {
          case '+':
            push(op1+op2);
            break;
          case '-':
           push(op1-op2);
           break;
          case '/':
           push(op1/op2);
           break;
          case '*':
           push(op1*op2);
           break;
          case '^':
           push(pow(op1,op2));
           break;
          default:
           cout<<"envalid notation"<<endl;
        }
      }
    }
    return stk[top];
}
int postfix_evalution(string s)
{
  int n=s.size();
  for(int i=0;i<n;i++)
  {
    if(s[i]>='0'&&s[i]<='9')
    {
      push(s[i]-'0');
    }
    else
    {
      int op1;
      int op2;
      op2=pop();
      op1=pop();
        switch (s[i])
        {
          case '+':
            push(op1+op2);
            break;
          case '-':
           push(op1-op2);
           break;
          case '/':
           push(op1/op2);
           break;
          case '*':
           push(op1*op2);
           break;
          case '^':
           push(pow(op1,op2));
           break;
          default:
           cout<<"envalid notation"<<endl;
        }      
    }
  }
  return stk[top];
}
int main() 
{
    string s;
    // cout<<"Enter an prefix expresion"<<endl;
    // cin>>s;
    // int x=prefix_evalution(s);
    // cout<<"the value of the expresion is : "<<x<<endl;
    cout<<"Enter an postfix expresion"<<endl;
    cin>>s;
    int x=postfix_evalution(s);
    cout<<"the value of the expresion is : "<<x<<endl;
}
