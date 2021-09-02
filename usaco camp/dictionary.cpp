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

   set<string> dict;
   string word;
   while (cin >> word)
   {
      string output;
      for (auto k:word)
      {
         if (isalpha(k))
            output += tolower(k);
         else
         {
            if (output.size())
               dict.insert(output);
            output = "";
         }
      }
      if (output.size())
         dict.insert(output);
   }
   for (auto x:dict)
      cout << x << "\n";
}