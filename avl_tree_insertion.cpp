#include <bits/stdc++.h>
using namespace std;

struct node 
{
  int data;
  node* left;
  node* right;
  int height;
};

node* create_node(int val)
{
  node* n = (node*)malloc(sizeof(node));
  n->data = val;
  n->left = NULL;
  n->right = NULL;
  n->height = 1;
  return n ;
}

int getHeight(node* n)
{
  if(n == NULL)
  {
    return 0;
  }
  return n->height;
}

int getBlancefactor(node* n)
{
  if(n==NULL)
  {
    return 0;
  }
  return getHeight(n->left) - getHeight(n->right);
}

node* rr_rotation(node* y)
{
  node* x = y->left;
  node* t2 = x->right;
  
  y->left = t2;
  x->right = y;
  
  y->height = max(getHeight(y->left) , getHeight(y->right)) + 1;
  x->height = max(getHeight(x->left) , getHeight(x->right)) + 1;
  
  return x;
}

node* ll_rotation(node* x)
{
  node* y = x->right;
  node* t2 = y->left;
  
  y->left = x;
  x->right = t2;
  
  x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
  y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
  
  return y;
}

node* insert(node* n, int val)
{
  if(n == NULL)
  {
    return create_node(val);
  }
  if(val < n->data)
  {
    n->left = insert(n->left , val);
  }
  else if(val > n->data)
  {
    n->right = insert(n->right , val);
  }
  else
  {
    return n;
  }
  
  n->height = 1 + max(getHeight(n->left),getHeight(n->right));
  
  int bf = getBlancefactor(n);
  
  // left left
  if(bf > 1 && val < n->left->data )
  {
    return rr_rotation(n);
  }
  //right right case
  if(bf < -1 && val > n->right->data)
  {
    return ll_rotation(n);
  }
  
  // left right
  if(bf > 1 && val > n->left->data)
  {
    n->left = ll_rotation(n->left);
    return rr_rotation(n);
  }
  
  //right left
  if(bf < -1 && val < n->right->data)
  {
    n->right = rr_rotation(n->right);
    return ll_rotation(n);
  }
  return n;
}

void preOrder(node* n)
{
  if(n != NULL)
  {
    cout<<n->data<<" ";
    preOrder(n->left);
    preOrder(n->right);
  }
}
int main() 
{
    node* root = NULL;
    
     root = insert(root, 10);
     root = insert(root, 20);
     root = insert(root, 30);
     root = insert(root, 40);
     root = insert(root, 50);
     root = insert(root, 25);
     
     preOrder(root);
}
