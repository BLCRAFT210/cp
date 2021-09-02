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
   
   int n;
   cin >> n;
   stack<int> s;
   stack<int> smallest;
   
   while (n--)
   {
      string a;
      cin >> a;
      if (a=="PUSH")
      {
         int x;
         cin >> x;
         if (smallest.empty() || x<smallest.top())
            smallest.push(x);
         else
            smallest.push(smallest.top());
         s.push(x);
      }

      else if (a=="POP")
      {
         if (s.empty())
            cout << "EMPTY\n";
         else
         {
            s.pop();
            smallest.pop();
         }
      }

      else
      {
         if (s.empty())
            cout << "EMPTY\n";
         else
            cout << smallest.top() << "\n";
      }
   }
}