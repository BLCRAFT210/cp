#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
using namespace std;

string toLowest(string x)
{
   for (auto& c:x)
      c = tolower(c);
   sort(x.begin(),x.end());
   return x;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   string word;
   set<string> dict;
   while (cin >> word)
   {
      if (word == "#")
         break;
      dict.insert(word);
   }

   map<string,int> freq;
   for (auto w:dict)
      freq[toLowest(w)]++;

   for (auto w:dict)
   {
      if (freq[toLowest(w)] == 1)
         cout << w << "\n";
   }
}