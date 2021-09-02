#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int cases,n,l;
   cin >> cases;
   for (int c = 0;c<cases;c++)
   {
      cin >> n >> l;
      int count = 0;
      vector<int> items(n);
      for (int i = 0;i<n;i++)
         cin >> items[i];
      sort(items.begin(),items.end());

      while (items.size())
      {     
         auto match = upper_bound(items.begin(),items.end(),l-items.front());

         if (match==items.begin())
         {
            count++;
            items.erase(items.begin());
         }
         else if (*match+items.front()<=l)
         {
            count++;
            items.erase(match);
            items.erase(items.begin());
         }
         else
         {
            count++;
            if (match-1!=items.begin())
               items.erase(match-1);
            items.erase(items.begin());
         }
      }

      cout << count << "\n";
      if (c<cases-1)
         cout << "\n";
   }
}