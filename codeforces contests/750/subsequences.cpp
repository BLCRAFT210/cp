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
      cin >> n;
      long long coeff=0,power=0;
      for (int i = 0;i<n;i++)
      {
         int x;
         cin >> x;
         if (x==0)
            power++;
         if (x==1)
            coeff++;
      }
      cout << coeff*(1LL<<power) << "\n";
   }
}