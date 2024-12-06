#include <bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  node *next;
};
struct node* newNode(int data)
{
  node *temp=(node*)malloc(sizeof(node));
  temp->data=data;
  temp->next=NULL;
  return temp;
}
void insertAt_fornt(node *&head,int data)
{
  node *n=newNode(data);
  n->next=head;
  head=n;
}
void display(node *head)
{
  node *temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}
void insertAt_tail(node *&head,int data)
{
  node *n=newNode(data);
  if(head==NULL)
  {
    head=n;
    return;
  }
  node* temp=head;
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=n;
}

void insertat_Pos(node *&head,int data,int pos)
{
  node *temp=head;
  node* n=newNode(data);
  if(pos==1)
  {
    n->next=head;
    head=n;
    return;
  }
  pos--;
  while(pos!=1)
  {
    temp=temp->next;
    pos--;
  }
  n->next=temp->next;
  temp->next=n;
}
int main() 
{
    node *head=NULL;
    
    insertAt_fornt(head,5);
    insertAt_fornt(head,18);
    insertAt_fornt(head,29);
    insertAt_tail(head,720);
    insertat_Pos(head,66,2);
    display(head);
}
