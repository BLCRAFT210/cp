#include <iostream>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string w;
   while (cin >> w)
   {
      list<char> line;
      auto iter = line.begin();
      for (auto c:w)
      {
         if (c=='[')
            iter = line.begin();
         else if (c==']')
            iter = line.end();
         else
            line.insert(iter,c);
      }

      for (auto c:line)
         cout << c;
      cout << "\n";
   }
}