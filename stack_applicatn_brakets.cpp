#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int top=-1;
char stackk[MAX];
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
int match_char(char x,char y)
{
  if(x=='('&&y==')')
  {
    return 1;
  }
  if(x=='{'&&y=='}')
  {
    return 1;
  }
  if(x=='['&&y==']')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
void push(char ch)
{
  if(!is_full())
  {
    top++;
    stackk[top]=ch;
  }
  else
  {
    cout<<"Stack overflow"<<endl;
    exit(1);
  }
}
char pop()
{
  if(!is_empty1())
  {
    char x=stackk[top];
    top--;
    return x;
  }
  else
  {
    cout<<"stack underflow"<<endl;
    exit(1);
  }
}


int check_balance(char *s)
{
  int len=strlen(s);
  for(int i=0;i<len;i++)
  {
    if(s[i]=='['||s[i]=='{'||s[i]=='(')
    {
      push(s[i]);
    }
    if(s[i]==']'||s[i]=='}'||s[i]==')')
    {
      if(is_empty1())
      {
        cout<<"Right braket is more than left braket"<<endl;
        return 0;
      }
      else
      {
        char temp=pop();
        if(!match_char(temp,s[i]))
        {
          cout<<"Mismatch braket"<<endl;
          return 0;
        }
      }
    }
  }
  if(is_empty1())
  {
    cout<<"brakets are well balanced"<<endl;
    return 1;
  }
  else
  {
    cout<<"left braket is more than right braket"<<endl;
    return 0;
  }
}

int main() 
{
    char expr[MAX];
    cout<<"Enter the algebric expresion"<<endl;
    cin.getline(expr, MAX);
    int balanced=check_balance(expr);
    if(balanced)
    cout<<"weldone !"<<endl;
    else
    cout<<"go hell"<<endl;
}
