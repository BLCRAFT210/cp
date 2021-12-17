#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int n,q;
   cin >> n >> q;
   vector<int> shades(n);
   for (int i = 0;i<n;i++)
   {
      char a;
      cin >> a;
      shades[i] = int(a)-65;
   }
   for (int i = 0;i<q;i++)
   {
      int left, right;
      cin >> left >> right;
      int ans = 0;
      stack<int> s;
      for (int j = 0;j<left-1;j++)
      {
         while (!s.empty() && s.top()>shades[j])
         {
            s.pop();
            ans++;
         }
         if (s.empty() || shades[j] > s.top())
         {
            s.push(shades[j]);
         }
      }
      ans += s.size();
      while (!s.empty())
         s.pop();
      for (int j = right;j<n;j++)
      {
         while (!s.empty() && s.top()>shades[j])
         {
            s.pop();
            ans++;
         }
         if (s.empty() || shades[j] > s.top())
         {
            s.push(shades[j]);
         }
      }
      cout << ans+s.size() << "\n";
   }
}