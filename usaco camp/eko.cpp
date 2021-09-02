#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n,m;
   cin >> n >> m;
   vector<int> trees(n);
   for (int i = 0;i<n;i++)
      cin >> trees[i];
   sort(trees.begin(),trees.end(),greater<int>());

   int height = trees.front();
   while (m>0)
   {
      height--;
      auto amountOff = lower_bound(trees.begin(),trees.end(),height,greater<int>());
      m+=distance(amountOff,trees.begin());
   }

   cout << height << "\n";
}