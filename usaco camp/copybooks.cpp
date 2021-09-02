#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool check(vector<int>& books, int k, int m)
{
   int pos = books.size()-1;
   int count = 0;
   while (pos>=0)
   {
      long long s = 0;
      while (pos >= 0 && s+books[pos] <= m)
      {
         s+=books[pos--];
      }
      count++;
      if (pos<0)
   }
   return count <= k;
}

int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n,k;
      cin >> n >> k;
      vector<long long> books(n);
      long long left = INT_MAX;
      long long right = 0;
      for (int i = 0;i<n;i++)
      {
         cin >> books[i];
         left = max(left,books[i]);
         right += books[i];
      }

      while (left<right)
      {
         int mid = (left+right)/2;
         if (check(books,k,mid))
            right = mid;
         else
            left = mid+1;
      }
      cout << left << "\n";
   }
}