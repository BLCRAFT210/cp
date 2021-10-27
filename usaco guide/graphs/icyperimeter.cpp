#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   freopen("perimeter.in","r",stdin);
   freopen("perimeter.out","w",stdout);
   
   int n;
   cin >> n;
   char grid[n][n];

   for (int i = 0;i<n;i++)
      for (int j = 0;j<n;j++)
         cin >> grid[i][j];

   int areaanswer = 0, perimeteranswer = 0;

   set<pair<int,int>> visited;
   for (int i = 0;i<n;i++)
   {
      for (int j = 0;j<n;j++)
      {
         int area = 0, perimeter = 0;
         stack<pair<int,int>> s;
         s.push({i,j});
         while (!s.empty())
         {
            pair<int,int> p = s.top();
            s.pop();
            if (visited.find(p)==visited.end())
            {
               if (p.first<0 || p.first>=n || p.second<0 || p.second>=n || grid[p.first][p.second]=='.')
               {
                  perimeter++;
               }
               else
               {
                  area++;
                  visited.insert(p);
                  s.push({p.first+1,p.second});
                  s.push({p.first-1,p.second});
                  s.push({p.first,p.second-1});
                  s.push({p.first,p.second+1});
               }
            }
         }
         if (area>areaanswer)
         {
            areaanswer = area;
            perimeteranswer = perimeter;
         }
         else if (area == areaanswer)
            perimeteranswer = min(perimeteranswer,perimeter);
      }
   }

   cout << areaanswer << " " << perimeteranswer << "\n";
}