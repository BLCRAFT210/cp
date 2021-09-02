#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int>& x,int k,int r)
{
   auto p1 = x.begin();
   for (int i = 0;i<k;i++)
   {
      int bomb = *p1+r;
      p1 = upper_bound(p1,x.end(),bomb+r);
      if (p1==x.end())
         return true;
   }
   return false;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n,k;
   cin >> n >> k;
   vector<int> x(n);
   for (int i = 0;i<n;i++)
      cin >> x[i];

   sort(x.begin(),x.end());

   int l=0,r=(x[n-1]-x[0])/2+1;
   while (l<r)
   {
      int mid = (l+r)/2;
      if (check(x,k,mid))
         r = mid;
      else
         l = mid+1;
   }
   cout << l << "\n";
}