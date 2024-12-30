#include <bits/stdc++.h>
using namespace std;

int prec(char ch)
{
  if(ch=='^')
  {
    return 3;
  }
  else if(ch=='*'||ch=='/')
  {
    return 2;
  }
  else if(ch=='+'||ch=='-')
  {
    return 1;
  }
  return 0;
}
char associativity(char ch)
{
  if(ch=='^')
  {
    return 'R';
  }
  else
  {
    return 'L';
  }
}
void intfixToposfix(string s)
{
  char result[1000];
  char stk[1000];
  int top=-1;
  int len = s.size();
  int result_ind=-1;
  for(int i=0;i<len;i++)
  {
    char c=s[i];
    if((c>='0' && c<='9') || (c>='a' && c<='z') || (c>='A' && c<='Z'))
    {
      result[++result_ind]=c;
    }
    else if(c=='(')
    {
      stk[++top]=c;
    }
    else if(c==')')
    {
      while(top>=0 && stk[top]!='(')
      {
        result[++result_ind]=stk[top--];
      }
      top--;
    }
    else
    {
      while(top>=0 && (prec(stk[top])>prec(s[i]) || (prec(stk[top])==prec(s[i]) && associativity(s[i])=='L')))
      {
        result[++result_ind]=stk[top--];
      }
      stk[++top]=c;
    }
  }
  while(top>=0)
  {
    result[++result_ind]=stk[top--];
  }
  result[++result_ind]='\0';
  cout<<result;
}
int main() 
{
   cout<<"enter a infix expression "<<endl;
   string a;
   cin>>a;
   cout<<"here the postfix expression :  ";
   intfixToposfix(a);
}
