#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
using namespace std;

int main()
{
   int q;
   cin >> q;
   map<string,int> scores;

   while (q--)
   {
      int c,score;
      string name;
      cin >> c >> name;
      if (c==1)
      {
         cin >> score;
         scores[name]+=score;
      }
      else if (c==2)
      {
         scores.erase(name);
      }
      else
      {
         cout << scores[name] << endl;
      }
   }
}