#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
   int f,s,g,u,d;
   cin >> f >> s >> g >> u >> d;
   queue<int> q;
   q.push(s);
   vector<bool> visited(f+1);
   vector<int> distance(f+1);
   bool found = false;
   while (q.size())
   {
      int front = q.front();
      q.pop();
      if (front==g)
      {
         found = true;
         break;
      }
      visited[front]=true;
      int n1 = front+u;
      if (n1<=f && !visited[n1])
      {
         distance[n1] = distance[front] + 1;
         q.push(n1);
         visited[n1] = true;
      }

      int n2 = front-d;
      if (n2>0 && !visited[n2])
      {
         distance[n2] = distance[front]+1;
         q.push(n2);
         visited[n2] = true;
      }
   }
   if (found)
      cout << distance[g] << "\n";
   else
      cout << "use the stairs\n";
}