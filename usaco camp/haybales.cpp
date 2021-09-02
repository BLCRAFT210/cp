#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   int n,q,x,a,b;
   cin >> n >> q;
   vector<int> haybales;
   while (n--)
   {
      cin >> x;
      haybales.push_back(x);
   }

   sort(haybales.begin(),haybales.end());

   while (q--)
   {
      cin >> a >> b;
      cout << upper_bound(haybales.begin(),haybales.end(),b) - lower_bound(haybales.begin(),haybales.end(),a) << endl;
   }
}