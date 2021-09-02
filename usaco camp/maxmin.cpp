#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
   int n,k;
   cin >> n >> k;
   vector<int> f(n);
   for (int i = 0;i<n;i++)
      cin >> f[i];
   sort(f.begin(),f.end());

   int minn=INT_MAX;
   for (int i = 0;i<=n-k;i++)
   {
      int t = f[i+k-1]-f[i];
      minn = min(minn,t); 
   }
   cout << minn << "\n";
}