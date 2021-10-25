#include <bits/stdc++.h>
using namespace std;

bool test(long double t, vector<int> &p, vector<int> &s)
{
   long double mi=-1e25, ma=1e25;
   for (int i = 0;i<p.size();i++)
   {
      mi = max(mi,p[i]-s[i]*t);
      ma = min(ma,p[i]+s[i]*t);
   }
   return mi<=ma;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int n;
   cin >> n;
   vector<int> positions(n),speeds(n);
   for (int i = 0;i<n;i++)
      cin >> positions[i];
   for (int i = 0;i<n;i++)
      cin >> speeds[i];

   long double l = 0;
   long double r = 1e14;
   for (int i = 0;i<500;i++)
   {
      long double m = (l+r)/2;
      if (test(m,positions,speeds))
         r=m;
      else
         l=m;
   }
   cout.precision(12); //why do they make it this precise bruh
   cout << l << "\n";
}