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
int main()
{
  node *head=NULL;
  insertAtTail(head,12);
  insertAtTail(head,18);
  insertAtTail(head,22);
  insertAtTail(head,11);
  insertAtTail(head,10);
  insertAtTail(head,112);
  display(head);
  cout<<endl;
  insertAtHead(head,720);
  display(head);
  cout<<endl;
  cout<<search(head,5)<<endl;
  cout<<search(head,10)<<endl;
}





//Output:
//12 18 22 11 10 112 
//720 12 18 22 11 10 112 
//0
//1
