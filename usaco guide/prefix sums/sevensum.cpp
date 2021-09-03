#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   freopen("div7.in","r",stdin);
   freopen("div7.out","w",stdout);

   int n;
   cin >> n;
   vector<int> psum(n+1);
   psum[0]=0;
   for (int i = 1;i<n+1;i++)
   {
      int x;
      cin >> x;
      psum[i]=(psum[i-1]+x)%7;
   }

   vector<long long> first(7);
   vector<bool> firstfound(7);
   long long ans = 0;
   for (int i = 0;i<n+1;i++)
   {
      if (!firstfound[psum[i]])
      {
         firstfound[psum[i]]=true;
         first[psum[i]]=i;
      }
      else
      {
         ans=max(ans,i-first[psum[i]]);
      }
   }

   cout << ans;
}