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
           map<T,int> dis;
           queue<T> q;
           for(auto node_pair:l)
           {
               T node=node_pair.first;
               dis[node]=INT_MAX;
           }
              q.push(src);
              dis[src]=0;

         while(!q.empty())
         {
             T node=q.front();
             q.pop();
            // cout<<node<<" ";
             for(auto nbrs:l[node])
             {
                 if(dis[nbrs]==INT_MAX)
                 {
                 q.push(nbrs);
                 dis[nbrs]=dis[node]+1;
                 }
             }

          }
          for(auto node_pair:l)
          {
            T node=node_pair.first;
            int di=dis[node] ;
            cout<<"node "<<node<<"  D from src   "<<di<<endl;
          }




     }

};
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      Graph<int> g;
      g.addedge(0,1);
      g.addedge(0,3);
      g.addedge(1,2);
      g.addedge(2,3);
      g.addedge(3,4);
      g.addedge(4,5);
      g.bfs(0);
}
