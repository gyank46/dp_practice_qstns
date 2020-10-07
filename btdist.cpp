#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
Node* findi(Node *root,int a)
{
    Node *lefty=NULL,*righty=NULL;
    if(root->data==a)
    {
        // cout<<"found "<<root->data<<" "<<a<<endl;
        return root;
    }
    if(root->left)
        lefty=findi(root->left,a);
    if(root->right)
        righty=findi(root->right,a);
    if(!lefty&&!righty)
        return NULL;
    if(lefty&&!righty)
        return lefty;
    if(!lefty&&righty)
        return righty;
    return NULL;
}
void assignp(Node *root,unordered_map<Node*,Node*> &parent)
{
    if(root->left)
    {
        parent[root->left]=root;
        assignp(root->left,parent);
    }
    if(root->right)
    {
        parent[root->right]=root;
        assignp(root->right,parent);
    }
}
void finddist(Node *root,unordered_map<int,int> &dist,unordered_map<int,int> &visited,unordered_map<Node*,Node*> &parent)
{
    if(root->left&&visited.find(root->left->data)==visited.end())
    {
        visited[root->left->data]=1;
        dist[root->left->data]=dist[root->data]+1;
        finddist(root->left,dist,visited,parent);
    }
    if(root->right&&visited.find(root->right->data)==visited.end())
    {
        visited[root->right->data]=1;
        dist[root->right->data]=dist[root->data]+1;
        finddist(root->right,dist,visited,parent);
    }
    if(parent.find(root)!=parent.end()&&visited.find(parent[root]->data)==visited.end())
    {
        visited[parent[root]->data]=1;
        dist[parent[root]->data]=dist[root->data]+1;
        finddist(parent[root],dist,visited,parent);
    }

}
int findDist(Node* root, int a, int b)
{
    // Your code here
    // cout<<root->data<<endl;
    if(root==NULL)
        return 0;
    if(a==b)
        return 0;
    unordered_map<int,int> visited;
    unordered_map<Node*,Node*> parent;
    assignp(root,parent);
    unordered_map<int,int> dist;
    Node *temp=NULL;
    temp=findi(root,a);
    // cout<<"here"<<endl;
    // cout<<temp->data<<endl;
    dist[a]=0;
    visited[a]=1;
    finddist(temp,dist,visited,parent);
    return dist[b];
}
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */

int findDist(Node* ,int ,int );
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     int a,b;
     cin>>a>>b;
     cout<<findDist(root,a,b)<<endl;
  }
  }
  return 0;
}
