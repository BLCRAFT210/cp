#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x)
{
   if (x==0 || x==1)
      return false;
   for (int i = 2;i<=sqrt(x);i++)
      if (x%i==0)
         return false;
   return true;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   vector<unordered_set<int>> primes(17);
   for (int i = 1;i<=16;i++)
   {
      unordered_set<int> temp;
      for (int j = 1;j<=16;j++)
         if (isPrime(i+j))
            temp.insert(j);
      primes[i]=temp;
   }

   bool newline = false;
   int n;
   int casenum = 1;
   while (cin >> n)
   {
      if (!newline)
         newline = true;
	   else
	  	   cout << "\n";
      cout << "Case " << casenum << ":\n";
      stack<vector<int>> s;
      s.push({1});
      while (s.size())
      {
         set<vector<int>> visited;
         vector<int> f = s.top();
         s.pop();
         if (f.size()==n && isPrime(f.front()+f.back()))
         {
            bool first = true;
            for (auto i:f)
            {
               if (first)
               {
                  cout << i;
                  first = false;
               }
               else
                  cout << " " << i;
            }
            cout << "\n";
            continue;
         }
         for (auto i:primes[f.back()])
         {
            if (i<=n && find(f.begin(),f.end(),i)==f.end())
            {
               vector<int> tempv = f;
               tempv.push_back(i);
               s.push(tempv);
            }
         }
      }
      casenum++;
   }
}