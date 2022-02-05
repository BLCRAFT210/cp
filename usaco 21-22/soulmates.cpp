#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int n;
   cin >> n;
   while (n--)
   {
      long long f,s;
      cin >> f >> s;
      
      int ans = 0;
      while (f!=s)
      {
         if (f>s)
         {
            if (f%2!=0)
               f++;
            else
               f/=2;
         }
         else
         {
            if (s-f>0 && s-f<4)
            {
               ans += s-f;
               break;
            }

            if (s%2!=0)
               s--;
            else
               s/=2;
         }
         ans++;
      }

      cout << ans << endl;
   }
}