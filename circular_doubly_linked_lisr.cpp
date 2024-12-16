#include <bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  node* prev;
  node* next;
};
struct node* new_circular_doubly(int val)
{
  node* temp=(node*)malloc(sizeof(node));
  temp->data=val;
  temp->prev=temp;
  temp->next=temp;
  return temp;
}
void insert_at_beg(node* &tail,int val)
{
  node *n=new_circular_doubly(val);
  if(tail==NULL)
  {
    tail=n;
    return;
  }
  node* temp=tail->next;
  n->next=temp;
  n->prev=tail;
  tail->next=n;
  temp->prev=n;
}
void print_circular_d(node* &tail)
{
  if(tail==NULL)
  {
    cout<<"Empty"<<endl;
    return;
  }
  node* temp=tail->next;
  do
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }while(temp!=tail->next);
  cout<<endl;
}
void insert_at_end(node * &tail,int val)
{
  node* n=new_circular_doubly(val);
  if(tail==NULL)
  {
    tail=n;
    return;
  }
  node *temp=tail->next;
  n->next=temp;
  n->prev=tail;
  temp->prev=n;
  tail->next=n;
  tail=n;
}
void insert_after_pos(node* &tail,int val,int pos)
{
  node* n=new_circular_doubly(val);
  if(tail==NULL)
  {
    tail=n;
    return ;
  }
  node* temp=tail->next;
  while(pos!=1)
  {
    temp=temp->next;
    pos--;
  }
  n->next=temp->next;
  n->prev=temp;
  temp->next->prev=n;
  temp->next=n;
  if(temp==tail)
  {
    tail=tail->next;
  }
}
void del_1st_node(node * &tail)
{
  node *temp=tail->next;
  tail->next=temp->next;
  temp->next->prev=tail;
  free(temp);
}
void del_last_node(node * &tail)
{
  node *temp=tail->prev;
  temp->next=tail->next;
  tail->next->prev=temp;
  free(tail);
  tail=temp;
}
void del_at_pos(node* &tail,int pos)
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
  node *temp=tail->next;
  while(pos!=1)
  {
    temp=temp->next;
    pos--;
  }
  if(temp==tail)
  {
    del_last_node(tail);
    return;
  }
  node *temp2=temp->prev;
  temp2->next=temp->next;
  temp->next->prev=temp2;
  free(temp);
}
void update_circular_doubly(node* &tail,int pre_val,int new_val)
{
  node* temp=tail->next;
  do
  {
    if(temp->data==pre_val)
    {
      temp->data=new_val;
      return;
    }
    temp=temp->next;
  }while(temp!=tail->next);
}
int main() 
{
    node* tail=NULL;
    insert_at_beg(tail,5);
    insert_at_beg(tail,2);
    insert_at_beg(tail,9);
    print_circular_d(tail);
    insert_at_end(tail,10);
    print_circular_d(tail);
    insert_after_pos(tail,15,2);
    print_circular_d(tail);
    del_1st_node(tail);
    print_circular_d(tail);
    del_last_node(tail);
    print_circular_d(tail);
    del_at_pos(tail,3);
    print_circular_d(tail);
    update_circular_doubly(tail,15,12);
    print_circular_d(tail);
}
