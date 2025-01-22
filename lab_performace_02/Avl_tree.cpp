#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int key;
  Node* left;
  Node* right;
  int height;
};

int getHeight(Node* n)
{
  if(n == NULL)
  {
    return 0;
  }
  return n->height;
}

Node* createNode(int key)
{
  Node* n = (Node*)malloc(sizeof(Node));
  n->key = key;
  n->left = n->right = NULL;
  n->height = 1;
  return n;
}

int GetBalaceFactor(Node* n)
{
  if(n == NULL)
  {
    return 0;
  }
  return getHeight(n->left) - getHeight(n->right);
}

Node* right_rotation(Node* y)
{
  Node* x = y->left;
  Node* T2 = x->right;
  
  x->right = y;
  y->left = T2;
  
  y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
  x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
  
  return x;
}

Node* left_rotation(Node* x)
{
  Node* y = x->right;
  Node* T2 = y->left;
  
  y->left = x;
  x->right = T2;
  
  x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
  y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
  
  return y;
}

Node* insert(Node* n,int key)
{
  if(n == NULL)
  {
    return createNode(key);
  }
  if(key < n->key)
  {
    n->left = insert(n->left,key);
  }
  else if(key > n->key)
  {
    n->right = insert(n->right,key);
  }
  else
  {
   return n;
  }
  n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
  int bf = GetBalaceFactor(n);
  
  //left left
  if(bf > 1 && key < n->left->key)
  {
    return right_rotation(n);
  }
  
  // right right 
  if(bf < -1 && key > n->right->key)
  {
    return left_rotation(n);
  }
  
  // left right
  if(bf > 1 && key > n->left->key)
  {
    n->left = left_rotation(n->left);
    return right_rotation(n);
  }
  
  //right left
  if(bf < -1 && key < n->right->key)
  {
    n->right = right_rotation(n->right);
    return right_rotation(n);
  }
  return n;
}

void PreOrder(Node* n)
{
  if(n == NULL)
  {
    return;
  }
  cout<<n->key << " ";
  PreOrder(n->left);
  PreOrder(n->right);
}

Node* inorderSucceccor(Node* n)
{
  Node* curr = n;
  while(curr && curr->left != NULL)
  {
    curr= curr->left;
  }
  return curr;
}

void deleteInAvl(Node*& root, int key) 
{
    if (root==NULL)
    {
      return;
    }
    
    if (root->key > key)
    {
        deleteInAvl(root->left, key);
    } 
    else if (root->key < key)
    {
        deleteInAvl(root->right, key);
    } 
    else 
    {
        if (root->right == NULL && root->left == NULL)
        {
            free(root);
            root = NULL;
            return;
        }
        if (root->left == NULL)
        {
            Node* temp = root;
            root = root->right;
            free(temp);
        } 
        else if (root->right == NULL)
        {
            Node* temp = root;
            root = root->left;
            free(temp);
        } 
        else
        {
            Node* temp = inorderSucceccor(root->right);
            root->key = temp->key;
            deleteInAvl(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root==NULL) 
    return;

    // Update the height of the current node
    root->height = max(getHeight(root->left),getHeight(root->right));

    // Get the balance factor
    int bf = GetBalaceFactor(root);

    // If the node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (bf > 1 && GetBalaceFactor(root->left) >= 0) 
    {
      root = right_rotation(root);
    }

    // Left Right Case
    if (bf > 1 && GetBalaceFactor(root->left) < 0)
    {
      root->left = left_rotation(root->left);
      root = right_rotation(root);
    }

    // Right Right Case
    if (bf < -1 && GetBalaceFactor(root->right) <= 0)
    {
      root = left_rotation(root);
    }

    // Right Left Case
    if (bf < -1 && GetBalaceFactor(root->right) > 0) 
    {
      root->right = right_rotation(root->right);
      root = left_rotation(root);
    }
}

int main() 
{
  Node* root = NULL;
  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 3);
  root = insert(root, 4);
  root = insert(root, 5);
  root = insert(root, 6);
  root = insert(root, 8);
     
  PreOrder(root);
  
  deleteInAvl(root,4);
  cout<<endl;
  PreOrder(root);
}
