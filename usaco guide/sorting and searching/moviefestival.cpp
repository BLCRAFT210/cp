#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int n;
   cin >> n;
   vector<pair<int,int>> movies(n);
   for (int i = 0;i<n;i++)
   {
      int starttime,endtime;
      cin >> starttime >> endtime;
      movies[i] = {endtime,starttime};
   }
   sort(movies.begin(),movies.end());

   int ans = 0, lastend = 0;
   for (int i = 0;i<n;i++)
   {
      if (movies[i].second>=lastend)
      {
         ans++;
         lastend=movies[i].first;
      }
   }
   cout << ans << "\n";
}