#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int t;
   cin >> t;
   vector<int> x,ps,psmin;
   while (t--)
   {
      int n;
      cin >> n;
      x.resize(n);
      ps.resize(n);
      int sumOfPositive = 0;
      int maxEl = INT_MIN;
      for (int i = 0;i<n;i++)
      {
         cin >> x[i];
         ps[i] = x[i]+((i>0)?ps[i-1]:0);
         psmin[i] = (i==0 ? 0:min(psmin[i-1],ps[i-1]));
         if (x[i]>0)
            sumOfPositive += x[i];
         maxEl = max(x[i],maxEl);
      }

      int maxInterSum = INT_MIN;
      for (int i = 0;i<n;i++)
      {
         int interSum = ps[i] - psmin[i];
         maxInterSum = max(interSum,maxInterSum);
      }
      cout << maxInterSum << " ";
      if (sumOfPositive==0)
         cout << maxEl << "\n";
      else
         cout << sumOfPositive << "\n";
   }
}