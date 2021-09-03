#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   freopen("stacking.in","r",stdin);
   freopen("stacking.out","w",stdout);

   int n,k;
   cin >> n >> k;

   vector<int> change(n+1);
   for (int i = 0;i<k;i++)
   {
      int left,right;
      cin >> left >> right;
      change[left-1]++;
      change[right]--;
   }

   vector<int> heights(n);
   int total = 0;
   for (int i = 0;i<n;i++)
   {
      total+=change[i];
      heights[i]=total;
   }

   sort(heights.begin(),heights.end());
   cout << heights[n/2] << "\n";
}