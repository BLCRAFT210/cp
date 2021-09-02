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
   vector<long long> ids(n);
   for (int i = 0;i<n;i++)
      cin >> ids[i];
   
   vector<long long> psum(n);
   psum[0]=ids[0];
   for (int i = 1;i<n;i++)
      psum[i]=(psum[i-1]+ids[i])%7;
   
   for (int currentLen = n;currentLen>1;currentLen--) //if single doesn't count as group, change to 0
   {
      auto leftbound = psum.begin();
      auto rightbound = leftbound+currentLen-1;
      while (rightbound<psum.end())
      {
         if ((*rightbound-(leftbound>psum.begin() ? *(leftbound-1) : 0)) % 7 == 0)
         {
            cout << currentLen << "\n";
            return 0;
         }
         leftbound++;
         rightbound++;
      }
   }
   cout << 0 << "\n";
}