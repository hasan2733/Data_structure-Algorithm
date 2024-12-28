#include<bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  node* next;
};
// node* top=NULL;
node* create_node(int data)
{
  node* n=(node*)malloc(sizeof(node));
  n->data=data;
  n->next=NULL;
  return n;
}
void push(int val,node* &top)
{
  node* n=create_node(val);
  if(n==NULL)
  {
    cout<<"stack overflow"<<endl;
    return;
  }
  if(top==NULL)
  {
    top=n;
    return;
  }
  n->next=top;
  top=n;
}
void print(node* &top)
{
  node* temp=top;
  while(temp!=NULL)
  {
    cout<<temp->data<<endl;
    temp=temp->next;
  }
}
int is_empty1(node* &top)
{
  if(top==NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int pop(node* &top)
{
  node* temp=top;
  if(is_empty1(top))
  {
    cout<<"stack underflow"<<endl;
    exit(1);
  }
  int val=temp->data;
  top=temp->next;
  free(temp);
  temp=NULL;
  return val;
}
void peek(node* &top)
{
  if(is_empty1(top))
  {
    cout<<"stack underflow"<<endl;
    exit(1);
  }
  cout<<top->data<<endl;
}
void reverse_stack(node* &top)
{
  node* top1=NULL;
  node* top2=NULL;
  while(top!=NULL)
  {
    push(pop(top),top1);
  }
  while(top1!=NULL)
  {
    push(pop(top1),top2);
  }
  while(top2!=NULL)
  {
    push(pop(top2),top);
  }
}
int main(){
  node* top=NULL;
  push(1,top);
  push(2,top);
  push(3,top);
  print(top);
  int x=pop(top);
  cout<<"The deleted element is : "<<x<<endl;
  cout<<"push 18 in the stack"<<endl;
  push(18,top);
  cout<<"The top most element is : ";
  peek(top);
  cout<<endl;
  cout<<"stack before reversing"<<endl;
  print(top);
  cout<<"Now reverse stack........"<<endl;
  reverse_stack(top);
  print(top);
}
