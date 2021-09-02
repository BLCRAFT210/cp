#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Node
{
   int depth;
   int left;
   int right;
};

vector<Node> tree;

void printOut(int root)
{
   if (root==-1) return;
   printOut(tree[root].left);
   cout << root << " ";
   printOut(tree[root].right);
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;
   tree.resize(n+1);
   tree[1].depth = 1;
   for (int i = 1;i<n+1;i++)
   {
      cin >> tree[i].left >> tree[i].right;
      if (tree[i].left != -1)
         tree[tree[i].left].depth = tree[i].depth+1;
      if (tree[i].right != -1)
         tree[tree[i].right].depth = tree[i].depth+1;
   }

   int q;
   cin >> q;
   while (q--)
   {
      int k;
      cin >> k;
      for (int i = 1;i<n+1;i++)
         if (tree[i].depth%k==0)
            swap(tree[i].left,tree[i].right);
      
      printOut(1);
      cout << "\n";
   }
}