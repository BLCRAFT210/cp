#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int t;
   while (t--)
   {
      int n,c;
      cin >> n >> c;
      vector<int> stalls(n);
      for (int i = 0;i<n;i++)
         cin >> stalls[i];
      
      sort(stalls.begin(),stalls.end());

      
   }
}