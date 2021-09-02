#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   int n, x;
   cin >> n;

   int vals[10];
   for (int i = 0;i<n;i++)
   {
      cin >> x;
      vals[i] = x;
   }

   vector<int> left,right;
   for (int a=0;a<n;a++)
   {
      for (int b=0;b<n;b++)
      {
         for (int c=0;c<n;c++)
         {
            left.push_back(vals[a]*vals[b]+vals[c]);
            if (vals[a])
            {
               right.push_back(vals[a]*(vals[b]+vals[c]));
            }
         }
      }
   }

   sort(right.begin(),right.end());
   int count = 0;

   for (int a:left)
   {
      count += upper_bound(right.begin(),right.end(),a) - lower_bound(right.begin(),right.end(),a);
   }

   cout << count << endl;
}