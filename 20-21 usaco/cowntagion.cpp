#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int n;
   cin >> n;
   vector<vector<int>> adjmat(n);
   for (int i = 0;i<n;i++)
   {
      vector<int> a;
      adjmat[i]=a;
   }

   for (int i = 0;i<n-1;i++)
   {
      pair<int,int> p;
      cin >> p.first >> p.second;
      adjmat[p.first-1].push_back(p.second-1);
      adjmat[p.second-1].push_back(p.first-1);
   }

   int ans = 0;
   vector<bool> visited(n);
   stack<int> s;
   s.push(0);
   while (!s.empty())
   {
      int a = s.top();
      s.pop();
      if (!visited[a])
      {
         visited[a]=true;
         int numneighs=0;
         for (int i:adjmat[a])
            if (!visited[i])
            {
               numneighs++;
               s.push(i);
            }
         if (numneighs>0)
            ans+=numneighs+(int) (ceil(log2(numneighs+1)));
      }
   }

   cout << ans << endl;
}