#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main()
{
   int q;
   cin >> q;
   set<int> s;
   
   while (q--)
   {
      int c,x;
      cin >> c >> x;

      if (c==1)
         s.insert(x);
      else if (c==2)
         s.erase(x);
      else if (s.find(x)==s.end())
         cout << "No" << endl;
      else
         cout << "Yes" << endl;
   }
}