#include <bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  node* left;
  node* right;
};

node* newnode(int val)
{
  node* n=(node*)malloc(sizeof(node));
  n->data=val;
  n->left=n->right=NULL;
  return n;  
}
void inorderTraversal(node* root)
{
  if(root==NULL)
  {
    return;
  }
  inorderTraversal(root->left);
  cout<<root->data<<" ";
  inorderTraversal(root->right);
}

void preorderTraversal(node *root)
{
  if(root==NULL)
  {
    return;
  }
  cout<<root->data<<" ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void postorderTraversal(node *root)
{
  if(root==NULL)
  {
    return;
  }
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout<<root->data<<" ";
}
int main() 
{
    node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(6);
    root->right->right=newnode(7);
    cout<<"In Order Traversal : "<<endl;
    inorderTraversal(root);
    cout<<endl;
    cout<<"Pre Order Traversal : "<<endl;
    preorderTraversal(root);
    cout<<endl;
    cout<<"Post Order Traversal : "<<endl;
    postorderTraversal(root);
}
