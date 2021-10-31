#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      int ans = 0;
      cin >> n;
      for (int i = 1;i<=n;i++)
      {
         int x;
         cin >> x;
         ans = max(ans,x-i);
      }

      cout << ans << "\n";
   }
}