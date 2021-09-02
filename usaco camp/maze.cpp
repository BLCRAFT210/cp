#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<char>> &m)
{
   return true;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int height,width,walls;
   cin >> height >> width >> walls;
   vector<vector<char>> maze(height);

   for (int i = 0;i<height;i++)
   {
      for (int j = 0;j<width;j++)
      {
         char x;
         cin >> x;
         maze[i].push_back(x);
      }
   }
}