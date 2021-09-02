#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

bool isPrime(int x)
{
   for (int i = 2;i<=sqrt(x);i++)
      if (x%i==0)
         return false;
   return true;
}

unordered_set<int> generateNeighbors(int x)
{
   unordered_set<int> toReturn;
   for (int i = 1;i<10;i++) //thousands
      if (i!=x/1000)
         toReturn.insert(i*1000+x%1000);
   for (int i = 0;i<10;i++) //hundreds
      if (i!=x/100%10)
         toReturn.insert(x/1000*1000+i*100+x%100);
   for (int i = 0;i<10;i++) //tens
      if (i!=x/10%10)
         toReturn.insert(x/100*100+i*10+x%10);
   for (int i = 0;i<10;i++) //ones
      if (i!=x%10)
         toReturn.insert(x/10*10+i);
   return toReturn;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int cases,start,finish;
   cin >> cases;

   while (cases--)
   {
      cin >> start >> finish;

      queue<int> q;
      q.push(start);
      set<int> visited;
      map<int,int> distance;
      distance[start] = 0;
      bool found = false;
      while (q.size())
      {
         int front = q.front();
         q.pop();
         if (front==finish)
         {
            found = true;
            break;
         }
         visited.insert(front);
         unordered_set<int> cset = generateNeighbors(front);
         for (auto i:cset)
         {
            if (visited.find(i)==visited.end() && isPrime(i))
            {
               distance[i] = distance[front]+1;
               q.push(i);
               visited.insert(i);
            }
         }
      }

      if (found)
         cout << distance[finish] << "\n";
      else
         cout << "Impossible\n";
   }
   /*unordered_set<int> temp = generateNeighbors(8765);
   for (auto i:temp)
      cout << i << " " << isPrime(i) << endl;*/
}