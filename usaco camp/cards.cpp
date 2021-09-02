#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void simulate(int n)
{
   vector<int> cards;
   for (int i = 1;i<n+1;i++)
   {
      cards.push_back(i);
   }
   vector<int> discarded;

   while (cards.size() > 1)
   {
      discarded.push_back(cards.front());
      cards.erase(cards.begin());
      cards.push_back(cards.front());
      cards.erase(cards.begin());
   }
   if (discarded.empty())
   {
      cout << "Discarded cards:" << endl;
   }
   else
   {
      cout << "Discarded cards: ";
      for (int i = 0;i<n-2;i++)
      {
         cout << discarded[i] << ", ";
      }
      cout << discarded.back() << endl;
   }
   cout << "Remaining card: ";
   cout << cards.front() << endl;
}

int main()
{
   int t;
   cin >> t;
   while (t!=0)
   {
      simulate(t);
      cin >> t;
   }
}