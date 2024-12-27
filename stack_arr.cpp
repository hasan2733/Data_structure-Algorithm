#include <iostream>
using namespace std;
#define MAX 8
int stack_arr[MAX];
int top=-1;
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
void push(int data)
{
  if(!is_full())
  {
    top+=1;
    stack_arr[top]=data;
  }
  else
  {
   cout<<"Stack overflow"<<endl;
  }
}
int pop()
{
  int val;
  if(!is_empty1())
  {
    val=stack_arr[top];
    top-=1;
    return val;
  }
  else
  {
    cout<<"can't pop stack is empty"<<endl;
    return -1;
  }
}
void print()
{
  cout<<"print stack"<<endl;
  while(!is_empty1())
  {
    int data=pop();
    cout<<data<<endl;
  }
}
int peek()
{
  if(top!=-1)
  {
    return stack_arr[top];
  }
  else
  {
      return -1;
  }
}
int main() 
{
 int choice,data;
 while(1)
 {
   cout<<"press 1 for push"<<endl;
   cout<<"press 2 for pop"<<endl;
   cout<<"press 3 for print top most element"<<endl;
   cout<<"press 4 for print all the elements"<<endl;
   cout<<"press 5 for quit"<<endl;
   cin>>choice;
   switch(choice)
   {
     case 1:
      cout<<"enter the data which will be pushed"<<endl;
      cin>>data;
      push(data);
      break;
    case 2:
      data=stack_arr[top];
      cout<<"Deleted element is "<<data<<endl;
      pop();
      break;
    case 3:
      cout<<"The top most element of the stack is "<<stack_arr[top]<<endl;
      break;
    case 4:
      cout<<"The full stack is "<<endl;
      print();
      break;
    case 5:
      exit(1);
    default:
      cout<<"Wrong choice"<<endl;
   }
 }
}
