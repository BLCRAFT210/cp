#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
using namespace std;

bool AllZero(vector<int>& seq)
{
   vector<int> z(seq.size());
   return seq == z;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      vector<int> seq(n);
      for (int i = 0;i<n;i++)
         cin >> seq[i];
      set<vector<int>> history;
      history.insert(seq);
      vector<int> seq2(n);
      for (;;)
      {
         if (AllZero(seq))
         {
            cout << "ZERO\n";
            break;
         }
         for (int i = 0;i<n;i++)
            seq2[i] = abs(seq[i]-seq[(i+1)%n]);
         if (history.find(seq2) != history.end())
         {
            cout << "LOOP\n";
            break;
         }
         seq = seq2;
         history.insert(seq);
      }
   }
}