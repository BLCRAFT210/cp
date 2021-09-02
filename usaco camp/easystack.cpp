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
   
   int q;
   cin >> q;
   stack<int> s;

   while (q--)
   {
      int c,score;
      cin >> c;
      if (c==1)
      {
         cin >> score;
         s.push(score);
      }
      else if (c==2)
      {
         if (!s.empty())
            s.pop();
      }
      else
      {
         if (s.empty())
            cout << "Empty!\n";
         else
            cout << s.top() << "\n";
      }
   }
}