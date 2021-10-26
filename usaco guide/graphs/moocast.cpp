#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   //freopen("moocast.in","r",stdin);
   //freopen("moocast.out","w",stdout);

   int n;
   cin >> n;
   vector<tuple<int,int,int>> cows(n);
   for (int i = 0;i<n;i++)
   {
      int x,y,z;
      cin >> x >> y >> z;
      cows[i]=make_tuple(x,y,z);
   }

   vector<vector<int>> adjmat;
   for (int i = 0;i<n;i++)
   {
      vector<int> k(n);
      for (int j = 0;j<n;j++)
      {
         if (powl(get<0>(cows[i])-get<0>(cows[j]),2)+powl(get<1>(cows[i])-get<1>(cows[j]),2)<=powl(get<2>(cows[i]),2))
            k[j]=1;
      }
      adjmat.push_back(k);
   }

   /*for (int i = 0;i<n;i++)
   {
      for (int j = 0;j<n;j++)
         cout << adjmat[i][j] << " ";
      cout << "\n";
   }*/

   int ans = 0;
   for (int i = 0;i<n;i++)
   {
      int count = 0;
      unordered_set<int> visited;
      stack<int> s;
      s.push(i);
      while (!s.empty())
      {
         int a = s.top();
         s.pop();
         if (visited.find(a)==visited.end())
         {
            count++;
            visited.insert(a);
            for (int j = 0;j<n;j++)
            {
               if (adjmat[a][j]==1)
                  s.push(j);
            }
         }
      }
      ans = max(ans,count);
   }

   cout << ans << "\n";
}