#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
template<typename T>
class Graph{
      map<T,list<T> > l;
public:

       void addedge(int x,int y)
      {
          l[x].push_back(y);

          l[y].push_back(x);

      }
       void bfs(T src)
      {
           map<T,bool> visited;
           queue<T> q;
           q.push(src);
           visited[src]=true;
         while(!q.empty())
         {
             T node=q.front();
             q.pop();
             cout<<node<<" ";
             for(auto nbrs:l[node])
             {
                 if(!visited[nbrs])
                 {
                 q.push(nbrs);
                 visited[nbrs]=true;
                 }


             }




         }




     }

};
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      Graph<int> g;
      g.addedge(0,1);
      g.addedge(1,2);
      g.addedge(2,3);
      g.addedge(3,4);
      g.addedge(4,5);
      g.bfs(0);
}
