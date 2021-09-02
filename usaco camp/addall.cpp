#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   while (cin >> n && n)
   {
      /*if (n==1)
      {
         long long x;
         cin >> x;
         cout << x << "\n";
         cin >> n;
         continue;
      }
      vector<long long> numbers(n);
      for (int i = 0;i<n;i++)
         cin >> numbers[i];

      sort(numbers.begin(),numbers.end());

      long long total = 0;
      long long sum = numbers.front();
      numbers.erase(numbers.begin());
      for (auto i:numbers)
      {
         sum+=i;
         total+=sum;
      }
      cout << total << "\n";*/

      priority_queue<int,vector<int>,greater<int>> q;
      for (int i = 0;i<n;i++)
      {
         int x;
         cin >> x;
         q.push(x);
      }
      int total = 0;
      while (p.size()>1)
      {
         
      }
   }
}