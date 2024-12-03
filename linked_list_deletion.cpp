#include<bits/stdc++.h>
using namespace std;

class node
{
  public:
    int data;
    node* next;
    
    node(int val)
    {
      data=val;
      next=NULL;
    }
};
void insertAtHead(node* &head,int val)
{
  node* n=new node(val);
  n->next=head;
  head=n;
}
void insertAtTail(node* &head,int val)
{
  node* n=new node(val);
  if(head==NULL)
  {
    head=n;
    return;
  }
  node* temp=head;
  while(temp->next!= NULL)
  {
    temp=temp->next;
  }
  temp->next=n;
}
void display(node* head)
{
  if(head==NULL)
  {
    cout<<"the list is empty"<<endl;
    return;
  }
  node* temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}
bool search(node* head,int key)
{
  node* temp=head;
  while(temp!=NULL)
  {
    if(temp->data==key)
    {
      return true;
    }
    temp=temp->next;
  }
  return false;
}
void deleteAtHead(node* &head)
{
  if(head==NULL)
  {
    return;
  }
  node* to_delete=head;
  head=head->next;
  delete to_delete;
}
void deletion(node* &head,int val)
{
  if(head==NULL)
  {
    return;
  }
  if(head->data==val)
  {
    deleteAtHead(head);
    return;
  }
  node* temp=head;
  while(temp->next->data != val)
  {
    temp=temp->next;
  }
  // if(head->next==NULL)
  // {
  //   cout<<"NOT "<<endl;
  //   return;
  // }
  node* to_delete=temp->next;
  temp->next=temp->next->next;
  delete to_delete;
}


int main()
{
  node *head=NULL;
  // insertAtTail(head,12);
  // insertAtTail(head,18);
  // insertAtTail(head,22);
  // insertAtTail(head,11);
  // insertAtTail(head,10);
  // insertAtTail(head,112);
  // display(head);
  // cout<<endl;
  // insertAtHead(head,720);
  // display(head);
  // cout<<endl;
  // cout<<search(head,5)<<endl;
  // cout<<search(head,10)<<endl;
  // deletion(head,22);
  // display(head);
  // cout<<endl;
  insertAtHead(head,1);
  insertAtHead(head,2);
  deletion(head,2);
  deletion(head,1);
  display(head);
}


