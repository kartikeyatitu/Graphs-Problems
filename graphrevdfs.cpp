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
       void dfs_helper(T src,map<T,bool> &visited)
       {
              cout<<src<<" ";
              visited[src]=true;
              for(auto nbr:l[src])
              {
                  if(!visited[nbr])
                  {
                      dfs_helper(nbr,visited);
                  }
               }
       }
        void dfs(T src)
        {
           map<T,bool> visited;
          //mark all the nodes not visited at the beginig
           for(auto x:l)
           {
               T node=x.first;
               visited[node]=false;

           }
           dfs_helper(src,visited);
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
      g.addedge(3,0);
      g.dfs(0);
}
