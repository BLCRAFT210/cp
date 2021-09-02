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

   int q;
   bool reversed = false;
   cin >> q;
   deque<int> s;
   while (q--)
   {
      string c;
      cin >> c;

      if (c=="reverse")
         reversed = !reversed;
      else if (c=="toFront")
      {
         int score;
         cin >> score;
         reversed ? s.push_back(score) : s.push_front(score);
      }
      else if (c=="front")
      {
         if (s.empty())
            cout << "No job for Ada?\n";
         else
         {
            cout << (reversed ? s.back() : s.front()) << "\n";
            reversed ? s.pop_back() : s.pop_front();
         }
      }
      else if (c=="back")
      {
         if (s.empty())
            cout << "No job for Ada?\n";
         else
         {
            cout << (!reversed ? s.back() : s.front()) << "\n";
            !reversed ? s.pop_back() : s.pop_front();
         }
      }
   }
}