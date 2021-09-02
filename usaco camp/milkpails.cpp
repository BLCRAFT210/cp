#include <bits/stdc++.h>
using namespace std;

bool visited[101][101];
int x,y,k,m;
int ans = INT_MAX;

void dfs(int cx,int cy, int curStep);
void visit(int mx,int my,int step)
{
   if (!visited[mx][my])
   {
      visited[mx][my] = true;
      dfs(mx,my,step);
      visited[mx][my] = false;
   }
}

void dfs(int cx,int cy, int curStep)
{
   if (curStep>k)
      return;
   int error = abs(m-cx-cy);
   ans = min(ans,error);
   visit(x,cy,curStep+1);
   visit(cx,y,curStep+1);
   visit(0,cy,curStep+1);
   visit(cx,0,curStep+1);
   int pour = min(cx,y-cy);
   visit(cx-pour,cy+pour,curStep+1);
   pour = min(cy,x-cx);
   visit(cx+pour,cy-pour,curStep+1);
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   cin >> x >> y >> k >> m;
   visited[0][0] = true;
   dfs(0,0,0);
   cout << ans << "\n";
}