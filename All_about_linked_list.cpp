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
void count_num(node *&head)
{
  if(head==NULL)
  {
    cout<<"The linkedlist is empty"<<endl;
  }
  node* temp=head;
  int cnt=0;
  while(temp!=NULL)
  {
    temp=temp->next;
    cnt++;
  }
  cout<<"The length of linkedlist is : "<<cnt<<endl;
}

void delete_an_element(node *&head,int data)
{
  if(head==NULL)
  {
    return;
  }
  if(head->data==data)
  {
    node *todelete=head;
    head=head->next;
    free(todelete);
    return;
  }
  node *temp=head;
  while(temp->next->data!=data)
  {
    temp=temp->next;
  }
  node *todelete=temp->next;
  temp->next=temp->next->next;
  free(todelete);
}

void update_data(node *&head,int data,int data2)
{
  node* temp=head;
  while(temp->data!=data)
  {
    temp=temp->next;
  }
  temp->data=data2;
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
    cout<<endl;
    count_num(head);
    delete_an_element(head,5);
    display(head);
    cout<<endl;
    count_num(head);
    update_data(head,720,72);
    display(head);
    cout<<endl;
    count_num(head);
}
