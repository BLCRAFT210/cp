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

   int teams;

   for (;;)
   {
      cin >> teams;
      if (teams == 0)
         break;
      map<int,int> teamlookup;
      for (int i = 0;i<teams;i++)
      {
         int n;
         cin >> n;
         for (int j = 0;j<n;j++)
         {
            int t;
            cin >> t;
            teamlookup[t] = i;
         }
      }
      for (;;)
      {
         string command;
         cin >> command;
         if (command == "STOP")
            break;
         else if (command == "ENQUEUE")
         {
            int t;
            cin >> t;
            int teamid = teamlookup[t];

            for (auto& k : line)
            {
               if (k.first == teamid)
               {
                  k.second.push(t);
                  found = true;
                  break;
               }
            }
            if (!found)
            {
               queue<int> tq;
               tq.push(t);
               line.push
            }
         }
      }
   }

}