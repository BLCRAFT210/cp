#include <bits/stdc++.h>
using namespace std;

int prefixsum[4][100002];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int n,q;
   cin >> n >> q;
   for (int i = 1;i<=n;i++)
   {
      int b;
      cin >> b;
      for (int j = 1;j<4;j++)
         prefixsum[j][i] = prefixsum[j][i-1] + (j==b ? 1 : 0);
   }

   for (int i = 0;i<q;i++)
   {
      int a,b;
      cin >> a >> b;
      for (int j = 1;j<4;j++)
      {
         cout << prefixsum[j][b]-prefixsum[j][a-1];
         if (j!=3)
            cout << " ";
      }
      cout << "\n";
   }
}