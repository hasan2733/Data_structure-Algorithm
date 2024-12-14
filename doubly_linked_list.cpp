#include<bits/stdc++.h>
using namespace std;

struct node
{
  node* prev;
  int data;
  node *next;
};
struct node* new_node(int val)
{
  struct node* n = (node*)malloc(sizeof(node));
  n->prev=NULL;
  n->data=val;
  n->next=NULL;
  return n;
}
void insert_at_beginning(node * &head,int val)
{
  node* n=new_node(val);
  if(head==NULL)
  {
    head=n;
  }
  else
  {
  head->prev=n;
  n->next=head;
  head=n;
  }
}
void insert_at_tail(node* &head,int val)
{
  node* n=new_node(val);
  node* temp=head;
  while(temp->next!= NULL)
  {
    temp=temp->next;
  }
  temp->next=n;
  n->prev=temp;
}
void insert_after_given_pos(node* &head,int pos,int val)
{
  node* n=new_node(val);
  node* temp=head;
  while(pos!=1)
  {
    temp=temp->next;
    pos--;
  }
  if(temp->next==NULL)
  {
    n->prev=temp;
    temp->next=n;
  }
  else
  {
  node* temp2=temp->next;
  n->prev=temp;
  n->next=temp2;
  temp->next=n;
  temp2->prev=n;
  }
}
void insert_before_given_pos(node *&head,int pos,int val)
{
  node* n=new_node(val);
  node* temp=head;
  if(pos==1)
  {
    insert_at_beginning(head,val);
  }
  else
  {
  pos--;
  while(pos!=1)
  {
    temp=temp->next;
    pos--;
  }
  node* temp2=temp->next;
  n->prev=temp;
  n->next=temp2;
  temp->next=n;
  temp2->prev=n;
  }
}
void display(node* &head)
{
  node* temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}
void create_list(node* &head)
{
  int n,val,i;
  cout<<"Enter the length of doubly linked list : "<<endl;
  cin>>n;
  if(n==0)
  {
    return ;
  }
  cout<<"Enter the element of 1 : "<<endl;
  cin>>val;
  head=new_node(val);
  for(i=1;i<n;i++)
  {
    cout<<"Enter the element of "<<i+1<<" : "<<endl;
    cin>>val;
    insert_at_tail(head,val);
  }
}
void delete_1st_node(node *&head)
{
  node* temp=head;
  head=head->next;
  free(temp);
  head->prev=NULL;
}
void delete_last_node(node * &head)
{
  node* temp=head;
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  node* temp2=temp->prev;
  free(temp);
  temp2->next=NULL;
}
void delete_at_dif_position(node* &head,int pos)
{
  if(pos==1)
  {
    delete_1st_node(head);
    return;
  }
  node* temp=head;
  while(pos!=1)
  {
    temp=temp->next;
    pos--;
  }
  if(temp->next==NULL)
  {
    delete_last_node(head);
    return;
  }
  node* temp2=temp->prev;
  temp2->next=temp->next;
  temp->next->prev=temp2;
  free(temp);
}
void reverse_doubly_linked_list(node* &head)
{
  node* temp=head;
  node* temp2=head->next;
  temp->prev=temp2;
  temp->next=NULL;
  while(temp2!=NULL)
  {
    temp2->prev=temp2->next;
    temp2->next=temp;
    temp=temp2;
    temp2=temp->prev;
  }
  head=temp;
}
int main()
{
  node* head=NULL;
  insert_at_beginning(head,2);
  insert_at_beginning(head,1);
  display(head);
  insert_at_tail(head,3);
  display(head);
  insert_after_given_pos(head,2,10);
  display(head);
  insert_before_given_pos(head,4,5);
  display(head);
  delete_1st_node(head);
  display(head);
  delete_last_node(head);
  display(head);
  delete_at_dif_position(head,3);
  display(head);
  insert_at_beginning(head,1);
  cout<<"Given linked list"<<endl;
  display(head);
  cout<<"reversed linked list "<<endl;
  reverse_doubly_linked_list(head);
  display(head);
  node* new_head=NULL;
  create_list(new_head);
  display(new_head);
}
