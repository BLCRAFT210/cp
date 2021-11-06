#include <bits/stdc++.h>
using namespace std;

vector<array<int,3>> wormholes;
vector<int> lookup;

bool test(int x) //returns true if x works as minimum width
{
   vector<vector<int>> adjmat; //initialize adjacency list
   for (int i = 0;i<lookup.size();i++)
   {
      vector<int> a;
      adjmat.push_back(a);
   }

   array<int,3> searchval = {x,0,0};
   auto iter = lower_bound(wormholes.begin(),wormholes.end(),searchval);
   //adds to adjacency list for wormholes with width x or higher
   while (iter<wormholes.end())
   {
      adjmat[(*iter)[1]].push_back((*iter)[2]);
      adjmat[(*iter)[2]].push_back((*iter)[1]);
      iter++;
   }

   vector<bool> visited(lookup.size());
   for (int i = 0;i<lookup.size();i++)
   {
      if (visited[i])
         continue;
      
      //dfs
      unordered_set<int> component;
      stack<int> s;
      s.push(i);
      while (!s.empty())
      {
         int a = s.top();
         s.pop();
         if (!visited[a])
         {
            visited[a]=true;
            component.insert(a);
            for (auto j:adjmat[a])
               s.push(j);
         }
      }

      //checks if cows in this component can be sorted - essentially same as set comparison
      for (int j:component)
      {
         if (component.find(lookup[j]) == component.end())
            return false;
      }
   }

   return true;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   freopen("wormsort.in","r",stdin);
   freopen("wormsort.out","w",stdout);

   int n,m;
   cin >> n >> m;
   vector<int> cows(n);
   lookup.resize(n); //lookup table for index of each cow
   for (int i = 0;i<n;i++)
   {
      int x;
      cin >> x;
      cows[i] = x-1; //cows and wormhole positions are 0 based
      lookup[x-1]=i;
   }

   //print -1 if sorted
   if (is_sorted(cows.begin(),cows.end()))
   {
      cout << "-1\n";
      return 0;
   }

   wormholes.resize(m);
   for (int i = 0;i<m;i++)
   {
      int x,y,w;
      cin >> x >> y >> w;
      wormholes[i]={w,x-1,y-1};
   }

   sort(wormholes.begin(),wormholes.end());

   //binary search
   int l=0, r=1e9+1;
   while (l<r)
   {
      int mid = (l+r+1)/2;
      if (test(mid))
      {
         l=mid;
      }
      else
      {
         r=mid-1;
      }
   }

   cout << l << "\n";
}