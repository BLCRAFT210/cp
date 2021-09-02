#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   int n;
   cin >> n;
   vector<int> v;
   while (n--)
   {
      int x;
      cin >> x;
      v.push_back(x);
   }

   int a;
   cin >> a;
   v.erase(v.begin()+a-1);

   int b;
   cin >> a >> b;
   v.erase(v.begin()+a-1,v.begin()+b-1);

   cout << v.size() << endl;
   for (auto i:v)
   {
      cout << i << " ";
   }
   cout << endl;
}