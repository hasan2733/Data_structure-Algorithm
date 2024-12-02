#include<bits/stdc++.h>
using namespace std;

class abid
{
  public:
    string name;
    int id;
  private:
    int age;
    char bg;
  public:
    void setAge(int n)
    {
      age=n;
    }
    void setBg(char b)
    {
      bg=b;
    }
    int getAge()
    {
      return age;
    }
    char getBg()
    {
      return bg;
    }
};
int main()
{
  class abid s;
  cout<<"Enter name : "<<endl;
  cin>>s.name;
  cout<<"Enter id : "<<endl;
  cin>>s.id;
  int x;
  cout<<"Enter age : "<<endl;
  cin>>x;
  s.setAge(x);
  char ch;
  cout<<"Enter Blood group : "<<endl;
  cin>>ch;
  s.setBg(ch);
  cout<<"The name is : "<<s.name<<" id is : "<<s.id<<" age is : "<<s.getAge()<<" Blood gruop is : "<<s.getBg();
}

