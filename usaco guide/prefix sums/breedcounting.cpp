#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   freopen("bcount.in","r",stdin);
   freopen("bcount.out","w",stdout);
   
   int n,q;
   cin >> n >> q;

   vector<int> cows(n);
   for (int i = 0;i<n;i++)
      cin >> cows[i];

   vector<int> psum1(n), psum2(n), psum3(n);
   psum1[0]=cows[0]==1;
   psum2[0]=cows[0]==2;
   psum3[0]=cows[0]==3;
   for (int i = 1;i<n;i++)
   {
      psum1[i]=psum1[i-1]+(int) (cows[i]==1);
      psum2[i]=psum2[i-1]+(int) (cows[i]==2);
      psum3[i]=psum3[i-1]+(int) (cows[i]==3);
   }

   for (int i = 0;i<q;i++)
   {
      int a,b;
      cin >> a >> b;
      cout << psum1[b-1]- (a>1 ? psum1[a-2] : 0) << " " << psum2[b-1]- (a>1 ? psum2[a-2] : 0) << " " << psum3[b-1]- (a>1 ? psum3[a-2] : 0) << "\n";
   }
}