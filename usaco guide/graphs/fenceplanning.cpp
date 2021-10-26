#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   //freopen("fenceplan.in","r",stdin);
   //freopen("fenceplan.out","w",stdout);

   int n,m;
   cin >> n >> m;
   vector<pair<int,int>> coordinates(n);
   for (int i = 0;i<n;i++)
      cin >> coordinates[i].first >> coordinates[i].second;
   
   vector<unordered_set<int>> adjmat;

   for (int i = 0;i<n;i++)
   {
      unordered_set<int> a;
      adjmat.push_back(a);
   }

   for (int i = 0;i<m;i++)
   {
      int a,b;
      cin >> a >> b;
      adjmat[a-1].insert(b-1);
      adjmat[b-1].insert(a-1);
   }

   unordered_set<int> visited;
   vector<vector<pair<int,int>>> groups;
   for (int i = 0;i<n;i++)
   {
      if (visited.find(i)!=visited.end())
         continue;
      stack<int> s;
      s.push(i);
      vector<pair<int,int>> g;
      while (!s.empty())
      {
         int a = s.top();
         s.pop();
         if (visited.find(a)==visited.end())
         {
            g.push_back(coordinates[a]);
            visited.insert(a);
            for (auto j:adjmat[a])
               s.push(j);
         }
      }
      if (!g.empty())
         groups.push_back(g);
   }

   int ans = INT_MAX;
   for (auto g:groups)
   {
      int l=INT_MAX,r=INT_MIN,u=INT_MIN,d=INT_MAX;
      for (auto i:g)
      {
         l=min(l,i.first);
         r=max(r,i.first);
         u=max(u,i.second);
         d=min(d,i.second);
      }

      ans = min(ans,2*(r-l+u-d));
   }

   cout << ans << "\n";
}