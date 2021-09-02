#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   int n;
   cin >> n;
   vector<int> v;
   while (n--)
   {
      int x;
      cin >> x;
      v.push_back(x);
   }
   sort(v.begin(),v.end());
   int ans = -1;
   for (int i = 0;i<v.size();i++)
   {
      auto k = upper_bound(v.begin(),v.end(),v[i]+1);
      int range = k-v.begin()-i;
      ans = max(ans,range);
   }
   cout << ans << endl;
}