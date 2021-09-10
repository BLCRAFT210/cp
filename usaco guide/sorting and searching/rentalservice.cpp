#include <bits/stdc++.h>
using namespace std;

template<typename T>
void printVector(vector<T>& v)
{
   for (auto i = v.begin();i<v.end();i++)
      cout << *i << " ";
   cout << endl;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   freopen("rental.in","r",stdin);
   freopen("rental.out","w",stdout);

   int n,m,r;
   cin >> n >> m >> r;

   vector<int> cows(n), rentals(r);
   vector<pair<int,int>> stores(m);

   for (int i = 0;i<n;i++)
      cin >> cows[i];
   for (int i = 0;i<m;i++)
   {
      int limit, price;
      cin >> limit >> price;
      stores[i]={price,limit};
   }
   for (int i = 0;i<r;i++)
      cin >> rentals[i];

   //sort
   sort(cows.begin(),cows.end());
   sort(stores.begin(),stores.end(),greater<>());
   sort(rentals.begin(),rentals.end(),greater<>());

   //prefix sums
   vector<int> gallonsum(n+1), storesum,rentalsum(r+1);
   for (int i = 1;i<n+1;i++)
      gallonsum[i]=gallonsum[i-1]+cows[i-1];

   for (int i = 1;i<r+1;i++)
      rentalsum[i]=rentalsum[i-1]+rentals[i-1];

   storesum.push_back(0);
   for (int i = 0;i<m;i++)
   {
      for (int j = 0;j<stores[i].second;j++)
         storesum.push_back(storesum.back()+stores[i].first);
   }

   long long ans = 0;
   //under i rented, i and above milked
   for (int i = 0;i<n;i++)
   {
      long long current = 0;
      current += (i>r ? rentalsum.back() : rentalsum[i]);
      int galloncount = gallonsum.back()-gallonsum[i];
      current += (galloncount>=storesum.size() ? storesum.back() : storesum[galloncount]);

      ans = max(ans,current);
   }

   cout << ans << endl;
}