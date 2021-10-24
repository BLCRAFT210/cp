#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   freopen("cardgame.in","r",stdin);
   freopen("cardgame.out","w",stdout);

   int n;
   cin >> n;
   vector<int> bessiecards(n);
   set<int> lowerhalf,upperhalf;
   for (int i = 0;i<n;i++)
      cin >> bessiecards[i];

   int count = 0;
   for (int i = 1;i<2*n+1;i++)
      if (find(bessiecards.begin(),bessiecards.end(),i) == bessiecards.end())
         if (count<n/2)
         {
            lowerhalf.insert(i);
            count++;
         }
         else
            upperhalf.insert(i);

   //score for greater card
   int ans = 0;
   for (int i = 0;i<n/2;i++)
   {
      auto f = upperhalf.upper_bound(bessiecards[i]);
      if (f!=upperhalf.end())
      {
         upperhalf.erase(f);
         ans++;
      }
      else
         upperhalf.erase(upperhalf.begin());
   }

   //score for lower card
   for (int i = n/2;i<n;i++)
   {
      auto f = lowerhalf.upper_bound(bessiecards[i]);
      if (f!=lowerhalf.begin())
      {
         lowerhalf.erase(--f);
         ans++;
      }
      else
         lowerhalf.erase(--lowerhalf.end());
   }

   cout << ans << "\n";
}