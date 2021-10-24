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
      int a,b,c,ans;
      cin >> a >> b >> c;
      if (a==0 && b%2==1 && c==0)
         ans=2;
      else if (a==0 && b==0 && c%2==1)
         ans=3;
      else
         ans=(a%2+(b%2)*2+(c%2)*3)%2;
      cout << ans << "\n";
   }
}