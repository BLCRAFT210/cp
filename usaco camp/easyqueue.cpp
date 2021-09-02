#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int t,q;
   cin >> t;
   queue<int> s;

   while (t--)
   {
      cin >> q;
      if (q==1)
      {
         int score;
         cin >> score;
         s.push(score);
      }
      else if (q==2)
      {
         if (!s.empty())
            s.pop();
      }
      else
      {
         if (s.empty())
            cout << "Empty!\n";
         else
            cout << s.front() << "\n";
      }
   }
}