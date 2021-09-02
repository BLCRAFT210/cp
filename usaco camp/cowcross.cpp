#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
using namespace std;

bool sortEnd(pii a, pii b)
   return a.second < b.second;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int c,n;
   cin >> c >> n;
   vector<int> chickens(c);
   vector<pair<int,int>> cows(n);

   for (int i = 0;i<c;i++)
      cin >> chickens[i];
   sort(chickens.begin(),chickens.end());

   for (int i = 0;i<n;i++)
      cin >> cows[i].first >> cows[i].second;
   sort(cows.begin(),cows.end(),sortEnd);

   int count = 0;
   vector<bool> help(n);
   for (auto c:chickens)
   {
      for (int i = 0;i<n;i++)
         if (!help[i] && cows[i].first <= c && cows[i].second >= c)
         {
            count++;
            help[i] = true;
            break;
         }
      
   }
}