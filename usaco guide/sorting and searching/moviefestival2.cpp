#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int n,k;
   cin >> n >> k;

   vector<pair<int,int>> movies(n);
   for (int i = 0;i<n;i++)
      cin >> movies[i].second >> movies[i].first;
   sort(movies.begin(),movies.end());

   int ans = 0;
   multiset<int> endtimes;
   for (int i = 0;i<k;i++)
      endtimes.insert(0);
   for (int i = 0;i<n;i++)
   {
      auto j = endtimes.upper_bound(movies[i].second);
      if (j!=begin(endtimes))
      {
         ans++;
         endtimes.erase(--j);
         endtimes.insert(movies[i].first);
      }
   }

   cout << ans << "\n";
}