#include <bits/stdc++.h>
using namespace std;

bool test(long long d,vector<pair<int,int>> &p, long long delx, long long dely) //returns true if d days works
{
   long long currx = p.back().first*(d/(p.size()-1)) + p[d%(p.size()-1)].first;
   long long curry = p.back().second*(d/(p.size()-1)) + p[d%(p.size()-1)].second;
   return abs(currx-delx)+abs(curry-dely) <= d;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   long long xchange,ychange;
   cin >> xchange >> ychange;
   long long x,y;
   cin >> x >> y;
   xchange = x-xchange;
   ychange = y-ychange;
   int n;
   cin >> n;
   vector<pair<int,int>> psum(n+1);
   for (int i = 1;i<n+1;i++)
   {
      char a;
      cin >> a;
      if (a=='U')
         psum[i]={psum[i-1].first,psum[i-1].second+1};
      else if (a=='D')
         psum[i]={psum[i-1].first,psum[i-1].second-1};
      else if (a=='L')
         psum[i]={psum[i-1].first-1,psum[i-1].second};
      else
         psum[i]={psum[i-1].first+1,psum[i-1].second};
   }

   long long l = 0;
   long long r = 1e18;
   long long ans = -1;
   while (l<r)
   {
      long long m = (l+r)/2;
      if (test(m,psum,xchange,ychange))
      {
         ans = m;
         r=m;
      }
      else
         l=m+1;
   }
   cout << ans << endl;
}