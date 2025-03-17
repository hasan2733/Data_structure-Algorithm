#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode
{
  char data;
  unsigned freq;
  MinHeapNode *left,*right;
  
  MinHeapNode(char data,unsigned freq)
  {
    this->data  = data;
    this->freq = freq;
    left = right = NULL;
  }
};

struct compare
{
  bool operator()(MinHeapNode* l ,MinHeapNode* r)
  {
    return (l->freq > r->freq);
  }
};

void printcodes(MinHeapNode* root,string str)
{
  if(!root)
  {
    return;
  }
  if(root->data!='$')
  {
    cout<<root->data<<" : "<< str<<endl;
  }
  printcodes(root->left,str+"0");
  printcodes(root->right,str+"1");
}

void HuffmanCodes(char data[],int freq[],int size)
{
  MinHeapNode *left,*right,*top;
  priority_queue<MinHeapNode*,vector<MinHeapNode*>,compare> minheap;
  for(int i=0;i<size;i++)
  {
    minheap.push(new MinHeapNode(data[i],freq[i]));
  }
  
  while(minheap.size() != 1)
  {
    left = minheap.top();
    minheap.pop();
    right = minheap.top();
    minheap.pop();
    
    top = new MinHeapNode('$',left->freq + right->freq);
    top->left = left;
    top->right = right;
    minheap.push(top);
  }
  printcodes(minheap.top(),"");
}

int main()
{
  char arr[] = {'_','i','n','o','g','m','e','y','t'};
  int freq[] = {8,7,5,4,4,3,2,2,1};
  
  int size = sizeof(arr)/sizeof(arr[0]);
  HuffmanCodes(arr,freq,size);
}
