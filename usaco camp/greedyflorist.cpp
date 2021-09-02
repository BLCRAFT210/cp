#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n,k;
   cin >> n >> k;
   vector<int> prices(n);

   for (int i = 0;i<n;i++)
      cin >> prices[i];
   sort(prices.begin(),prices.end(),greater<int>());

   int sum = 0;
   for (int i = 0;i<n;i++)
      sum += prices[i]*(i/k+1);
   cout << sum << "\n";
}