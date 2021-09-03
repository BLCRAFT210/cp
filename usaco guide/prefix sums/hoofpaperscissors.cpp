#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   freopen("hps.in","r",stdin);
   freopen("hps.out","w",stdout);

   int n;
   cin >> n;
   vector<int> hoof(n+1),paper(n+1),scissors(n+1);
   for (int i = 1;i<n+1;i++)
   {
      hoof[i]=hoof[i-1];
      paper[i]=paper[i-1];
      scissors[i]=scissors[i-1];
      string s;
      cin >> s;
      if (s=="H")
         hoof[i]++;
      else if (s=="P")
         paper[i]++;
      else
         scissors[i]++;
   }

   int ans=0;

   for (int i = 1;i<n+1;i++)
   {
      auto update = [&] (vector<int>& a,vector<int>& b)
      {
         ans=max(ans,a[i]+b[n]-b[i]);
      };

      update(hoof,paper);
      update(hoof,scissors);
      update(paper,hoof);
      update(paper,scissors);
      update(scissors,hoof);
      update(scissors,paper);
   }

   cout << ans << "\n";
}