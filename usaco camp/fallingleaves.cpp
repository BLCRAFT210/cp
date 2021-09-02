#include <iostream>
#include <map>
using namespace std;

struct Node
{
   int data;
   Node* left;
   Node* right;
};

Node* newNode(int val)
{
   Node* node = new Node();
   node->data = val;
   node->left = NULL;
   node->right = NULL;
   return node;
}

void readIn(Node* root)
{
   int left,right;
   cin >> left;
   if (left != -1)
   {
      root->left = newNode(left);
      readIn(root->left);
   }
   cin >> right;
   if (right != -1)
   {
      root->right = newNode(right);
      readIn(root->right);
   }
}

map<int,int> counts;
void countLeaves(Node* root,int pos)
{
   if (root==NULL) return;
   counts[pos]+=root->data;
   countLeaves(root->left,pos-1);
   countLeaves(root->right,pos+1);
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int x;
   int caseNum = 0;
   while (cin >> x && x!=-1)
   {
      cout << "Case " << ++caseNum << ":\n";
      Node* root = newNode(x);
      readIn(root);
      counts.clear();
      countLeaves(root,0);
      bool first = true;
      for (auto i:counts)
      {
         if (!first) cout << " ";
         first = false;
         cout << i.second;
      }
      cout << "\n\n";
   }
}