#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   int n;
   cin >> n;
   vector<int> v;
   while (n--)
   {
      int x;
      cin >> x;
      v.push_back(x);
   }

   int Q;
   cin >> Q;
   while (Q--)
   {
      int k;
      cin >> k;
      auto p = lower_bound(v.begin(),v.end(),k);
      if (*p == k)
      {
         cout << "Yes " << p-v.begin()+1 << endl;
      }
      else
      {
         cout << "No " << p-v.begin()+1 << endl;
      }
   }
}