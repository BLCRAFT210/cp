#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   while (cin >> n)
   {
      if (n==0)
         break;
      vector<int> out(n);
      for (;;)
      {
         cin >> out[0];
         if (out[0]==0)
            break;
         for (int i = 1;i<n;i++)
            cin >> out[i];
         
         int nextc = 1;
         stack<int> s;
         int p = 0;
         while (p<n)
         {
            int target = out[p];
            if (s.size() && s.top() == target)
            {
               p++;
               s.pop();
               if (p==n)
                  cout << "Yes\n";
            }
            else
            {
               if (nextc>n)
               {
                  cout << "No\n";
                  break;
               }
               s.push(nextc++);
            }
         }
      }
      cout << "\n";
   }
}