#include<bits/stdc++.h>
using namespace std;
struct book
{
  string name;
  string author;
  int pages;
};

void display1(string ,string ,int);
void display2(struct book);
void display3(struct book *);
int main()
{
  struct book b1={"Learn_C++","Abid",529};
  display1(b1.name,b1.author,b1.pages);
  cout<<endl;
  display2(b1);
  cout<<endl;
  display3(&b1);
}
void display1(string x,string y, int a)
{
  cout<<"Name of the book is "<<x<<" author is "<<y<<" the number of pages of the book  is "<<a<<endl;
}
void display2(struct book x)
{
  cout<<"Name of the book is "<<x.name<<" author is "<<x.author<<" the number of pages of the book  is "<<x.pages<<endl;
}
void display3(struct book *z)
{
  cout<<"Name of the book is "<<z->name<<" author is "<<z->author<<" the number of pages of the book  is "<<z->pages<<endl;
}

