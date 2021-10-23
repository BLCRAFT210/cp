#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int n;
   cin >> n;
   
   multiset<int> stacks;
   for (int i = 0;i<n;i++)
   {
      int x;
      cin >> x;
      auto j = stacks.upper_bound(x);
      if (j==stacks.end())
         stacks.insert(x);
      else
      {
         stacks.erase(j);
         stacks.insert(x);
      }
   }
   cout << stacks.size() << "\n";
}