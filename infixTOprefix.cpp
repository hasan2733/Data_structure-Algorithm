#include<bits/stdc++.h>
using namespace std;
int prec(char c)
{
  if(c=='^')
  {
    return 3;
  }
  else if(c=='/'||c=='*')
  {
    return 2;
  }
  else if(c=='+' || c=='-')
  {
    return 1;
  }
  else
  {
    return -1;
  }
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
void infixToprefix(string s)
{
  reverse(s.begin(),s.end());
  stack<char>st;
  string res;
  int n=s.size();
  for(int i=0;i<n;i++)
  {
    if((s[i]>='0'&&s[i]<='9')||(s[i]>='a' && s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
    {
      res+=s[i];
    }
    else if(s[i]==')')
    {
      st.push(s[i]);
    }
    else if(s[i]=='(')
    {
      while(!st.empty() && st.top()!=')')
      {
        res+=st.top();
        st.pop();
      }
      st.pop();
    }
    else
    {
      while(!st.empty() && (prec(st.top()) > prec(s[i])) &&(prec(st.top()==prec(s[i]))) && associativity(s[i])=='L' )
      {
        res+=st.top();
        st.pop();
      }
      st.push(s[i]);
    }
  }
  while(!st.empty())
  {
    res+=st.top();
    st.pop();
  }
  reverse(res.begin(),res.end());
  cout<<res;
}
int main()
{
  string s;
  cout<<"enter infix expression "<<endl;
  cin>>s;
  cout<<"here prefix expression :";
  infixToprefix(s);
}
