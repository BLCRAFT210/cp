#include <bits/stdc++.h>
using namespace std;

bool test(int x,vector<int> &l,vector<pair<int,pair<int,int>>> &holes) //returns true if x works as minimum width
{
   vector<vector<int>> adjmat; //initialize adjacency list
   for (int i = 0;i<l.size();i++)
   {
      vector<int> a;
      adjmat.push_back(a);
   }

   auto iter = lower_bound(holes.begin(),holes.end(),make_pair(x,make_pair(0,0)));
   //adds to adjacency list for wormholes with width x or higher
   while (iter<holes.end())
   {
      adjmat[(*iter).second.first].push_back((*iter).second.second);
      adjmat[(*iter).second.second].push_back((*iter).second.first);
      iter++;
   }

   vector<bool> visited(l.size());
   for (int i = 0;i<l.size();i++)
   {
      if (visited[i])
         continue;
      
      //dfs
      set<int> component;
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
         if (component.find(l[j]) == component.end())
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
   vector<int> lookup(n); //lookup table for index of each cow
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

   vector<pair<int,pair<int,int>>> wormholes(m);
   for (int i = 0;i<m;i++)
   {
      int x,y,w;
      cin >> x >> y >> w;
      wormholes[i]={w,{x-1,y-1}};
   }

   sort(wormholes.begin(),wormholes.end());

   //binary search
   int l=0, r=1e9+1;
   while (l<r)
   {
      int mid = (l+r+1)/2;
      if (test(mid,lookup,wormholes))
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