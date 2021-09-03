#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   freopen("maxcross.in","r",stdin);
   freopen("maxcross.out","w",stdout);

   int n,k,b;
   cin >> n >> k >> b;
   vector<int> signals(n,1);

   for (int i = 0;i<b;i++)
   {
      int x;
      cin >> x;
      signals[x-1]=0;
   }

   vector<int> psum(n+1);
   for (int i = 1;i<n+1;i++)
      psum[i]=psum[i-1]+signals[i-1];

   int ans = b;
   for (int i = 0;i<n+1-k;i++)
      ans = min(ans,k-psum[i+k]+psum[i]);

   cout << ans << "\n";
}