#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void floodfill(vector<vector<char>> &g,int row,int col)
{
   queue<pair<int,int>> q;
   q.push(make_pair(row,col));
   while (q.size())
   {
      pair<int,int> front = q.front();
      q.pop();
      if (front.first<0 || front.first>=g.size() || front.second<0 || front.second>=g[0].size() || g[front.first][front.second]=='*')
         continue;
      g[front.first][front.second]='*';
      for (int a = -1;a<2;a++)
         for (int b = -1;b<2;b++)
            q.push(make_pair(front.first+a,front.second+b));
   }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int m,n;
   cin >> m >> n;
   while (m)
   {
      vector<vector<char>> grid(m);
      for (int i = 0;i<m;i++)
      {
         for (int j = 0;j<n;j++)
         {
            char x;
            cin >> x;
            grid[i].push_back(x);
         }
      }

      int count = 0;
      for (int i = 0;i<m;i++)
      {
         for (int j = 0;j<n;j++)
         {
            if (grid[i][j]=='@')
            {
               count++;
               floodfill(grid,i,j);
            }
         }
      }
      cout << count << "\n";
      cin >> m >> n;
   }
}