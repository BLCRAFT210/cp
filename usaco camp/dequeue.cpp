#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int t;
   cin >> t;
   while (t--)
   {
      int n,k;
      cin >> n >> k;
      vector<int> x(n);
      for (int i = 0;i<n;i++)
         cin >> x[i];
      deque<int> de;
      for (int i = 0;i<k;i++)
      {
         while (de.size() && x[de.back()] <= x[i])
            de.pop_back();
         de.push_back(i);
      }

      cout << x[de.front()] << " ";
      for (int i = k;i<n;i++)
      {
         if (de.front() == i-k)
            de.pop_front();

         while (de.size() && x[de.back()] <= x[i])
            de.pop_back();
         de.push_back(i);
         cout << x[de.front()] << " ";
      }
      cout << "\n";
   }
}