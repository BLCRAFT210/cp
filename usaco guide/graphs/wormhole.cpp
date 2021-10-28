#include <bits/stdc++.h>
using namespace std;

bool test(int x,vector<int> &c,vector<pair<int,pair<int,int>>> &holes) //returns true if x works as minimum width
{
   vector<unordered_set<int>> adjmat;
   for (int i = 0;i<c.size();i++)
   {
      unordered_set<int> a;
      adjmat.push_back(a);
   }

   auto iter = lower_bound(holes.begin(),holes.end(),make_pair(x,make_pair(0,0)));
   while (iter<holes.end())
   {
      adjmat[(*iter).second.first].insert((*iter).second.second);
      adjmat[(*iter).second.second].insert((*iter).second.first);
      iter++;
   }

   unordered_set<int> visited;
   for (int i = 0;i<c.size();i++)
   {
      unordered_set<int> component;
      stack<int> s;
      s.push(i);
      while (!s.empty())
      {
         int a = s.top();
         s.pop();
         if (visited.find(a)==visited.end())
         {
            visited.insert(a);
            component.insert(a);
            for (auto j:adjmat[a])
               s.push(j);
         }
      }

      for (int j:component)
      {
         if (component.find(find(c.begin(),c.end(),j)-c.begin()) == component.end())
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
   for (int i = 0;i<n;i++)
   {
      int x;
      cin >> x;
      cows[i] = x-1;
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
      int mid = (l+r)/2;
      if (test(mid,cows,wormholes))
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