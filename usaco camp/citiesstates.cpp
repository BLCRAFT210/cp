#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;

   map<string,int> m;

   int count = 0;
   while (n--)
   {
      string c,s;
      cin >> c >> s;
      c = c.substr(0,2);
      if (c!=s)
      {
         count += m[s+c];
         m[c+s]++;
      }
   }
   cout << count << "\n";
}