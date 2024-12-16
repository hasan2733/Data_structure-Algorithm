#include<bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  node* next;
};
struct node* new_single_circular_linked_list(int val)
{
  node* temp=(node*)malloc(sizeof(node));
  temp->data=val;
  temp->next=temp;
  return temp;
}
void add_in_the_beg(node* &tail,int val)
{
  node* temp=tail;
  node* n=new_single_circular_linked_list(val);
  if(tail==NULL)
  {
    tail=n;
    n->next=tail;
  }
  else
  {
  n->next=temp->next;
  temp->next=n;
  }
}
void print_s_circular(node* &tail)
{
  node *temp=tail->next;
  do
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }while(temp!=tail->next);
}
void add_to_end(node* &tail,int val)
{
  node *n= new_single_circular_linked_list(val);
  n->next=tail->next;
  tail->next=n;
  tail=n;
}
void add_after_pos(node* &tail,int val,int pos)
{
  node* n=new_single_circular_linked_list(val);
  node* temp=tail->next;
  while(pos!=1)
  {
    temp=temp->next;
    pos--;
  }
  n->next=temp->next;
  temp->next=n;
  if(temp==tail)
  {
    tail=temp->next;
  }
} 
void del_1st_node(node* &tail)
{
  node* temp=tail->next;
  tail->next=temp->next;
  free(temp);
}
void del_last_node(node* &tail)
{
  node* temp=tail->next;
  while(temp->next!=tail)
  {
    temp=temp->next;
  }
  temp->next=tail->next;
  free(tail);
  tail=temp;
}
void del_at_pos(node * &tail,int pos)
{
  if(pos==0)
  {
    return;
  }
  if(pos==1)
  {
    del_1st_node(tail);
    return;
  }
  node* temp=tail->next;
  pos--;
  while(pos!=1)
  {
    temp=temp->next;
    pos--;
  }
  if(temp->next==tail)
  {
    del_last_node(tail);
    return;
  }
  node *temp2=temp->next;
  temp->next=temp2->next;
  free(temp2);
}
int main()
{
  node* tail=NULL;
  add_in_the_beg(tail,5);
  add_in_the_beg(tail,4);
  print_s_circular(tail);
  add_to_end(tail,10);
  cout<<endl;
  print_s_circular(tail);
  add_after_pos(tail,12,3);
  cout<<endl;
  print_s_circular(tail);
  del_1st_node(tail);
  cout<<endl;
  print_s_circular(tail);
  add_in_the_beg(tail,1);
  del_last_node(tail);
  cout<<endl;
  print_s_circular(tail);
  del_at_pos(tail,2);
  cout<<endl;
  print_s_circular(tail);
}
