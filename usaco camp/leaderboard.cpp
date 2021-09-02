#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n,m;
   cin >> n;
   vector<int> leaderboard;

   for (int i = 0;i<n;i++)
   {
      int x;
      cin >> x;
      leaderboard.push_back(x);
   }

   reverse(leaderboard.begin(),leaderboard.end());
   leaderboard.resize(unique(leaderboard.begin(),leaderboard.end())-leaderboard.begin());
   //sort(leaderboard.begin(),leaderboard.end());

   cin >> m;
   for (int i = 0;i<m;i++)
   {
      int x;
      cin >> x;
      auto k = lower_bound(leaderboard.begin(),leaderboard.end(),x);
      if (k == leaderboard.end())
         cout << 1 << "\n";
      else if (*k == x)
         cout << distance(k, leaderboard.end()) << "\n";
      else
         cout << distance(k, leaderboard.end())+1 << "\n";
   }
}