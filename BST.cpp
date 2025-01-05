#include<bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  node* left;
  node* right;
};
struct node* newnode(int val)
{
  node *n=(node*)malloc(sizeof(node));
  n->data=val;
  n->left=n->right=NULL;
  return n;
}
void insertBST(node* &root,int val)
{
  if(root==NULL)
  {
    root = newnode(val);
    return;
  }
  if(root->data > val)
  {
    insertBST(root->left,val);
  }
  else
  {
    insertBST(root->right,val);
  }
}
void inOrder(node* &root)
{
  if(root==NULL)
  {
    return;
  }
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}
void searchInBST(node* &root,int key)
{
  if(root==NULL)
  {
    cout<<"Key doesn't exit \n";
    return;
  }
  if(root->data==key)
  {
    cout<<"Key is found \n";
    return;
  }
  if(root->data < key)
  {
    searchInBST(root->right,key);
  }
  else
  {
    searchInBST(root->left,key);
  }
}
node* inOrderS(node* root)
{
  while(root !=NULL && root->left !=NULL)
  {
    root=root->left;
  }
  return root;
}
void deleteBST(node *&root,int key)
{
  if(root == NULL)
  {
    return;
  }
  if(root->data < key)
  {
    deleteBST(root->right,key);
  }
  else if(root->data > key)
  {
    deleteBST(root->left,key);
  }
  else
  {
    if(root->left==NULL && root->right == NULL)
    {
      free(root);
      root=NULL;
      return;
    }
    if(root->right==NULL)
    {
      node* temp=root;
      root=root->left;
      free(temp);
    }
    else if(root->left==NULL)
    {
      node* temp=root;
      root=root->right;
      free(temp);
    }
    else
    {
      node* temp=inOrderS(root->right);
      root->data=temp->data;
      deleteBST(root->right,temp->data);
    }
  }
}
int main()
{
  node* root=NULL;
  insertBST(root,4);
  insertBST(root,2);
  insertBST(root,3);
  insertBST(root,1);
  insertBST(root,7);
  insertBST(root,6);
  insertBST(root,5);
  inOrder(root);
  int n;
  cout<<"\nEnter the key \n";
  cin>>n;
  searchInBST(root,n);
  cout<<"After deletion : \n";
  deleteBST(root,4);
  inOrder(root);
  
}
