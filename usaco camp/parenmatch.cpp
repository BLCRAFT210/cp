#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;

   string x;
   getline(cin,x);
   while (n--)
   {
      getline(cin,x);
      stack<int> s;
      bool broken = false;
      for (auto c:x)
      {
         if (c=='(')
            s.push(0);
         else if (c=='[')
            s.push(1);
         else if (c==')')
         {
            if (s.empty() || s.top() != 0)
            {
               cout << "No\n";
               broken = true;
               break;
            }
            else
               s.pop();
         }
         else
         {
            if (s.empty() || s.top() != 1)
            {
               cout << "No\n";
               broken = true;
               break;
            }
            else
               s.pop();
         }
      }

      if (!broken)
      {
         if (s.empty())
            cout << "Yes\n";
         else
            cout << "No\n";
      }
   }
}