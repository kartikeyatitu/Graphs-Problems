#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
/* topological sort on directed acyclic graphs */
template<typename T>
class Graph{
     map<T,list<T> > l;
public:
     void addedge(T x,T y)
     {
         l[x].push_back(y);
     }
     void dfs_helper(T src,map<T,bool> &visited,list<T> &order)
     {

         visited[src]=true;
         for(auto nbr:l[src])
         {
             if(!visited[nbr])
             {
                 dfs_helper(nbr,visited,order);
             }
         }
         order.push_front(src);
         return;
}
     void dfs()
     {
         map<T,bool> visited;
         list<T> order;
         for(auto x:l)
         {
             T node=x.first;
             visited[node]=false;
         }
         //as there may be many independet nodes through which we can start call run dfs helper for each node
         for(auto x1:l)
         {
            T node=x1.first;
            if(!visited[node])
            {
            dfs_helper(node,visited,order);
            }
         }
         //print
         for(auto noe:order)
         {
             cout<<noe<<endl;
         }
     }

};
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      Graph<string> g;
      g.addedge("python","dataprocessing");
      g.addedge("python","pytorch");
      g.addedge("python","ml");
      g.addedge("dataprocessing","ml");
      g.addedge("pytorch","dl");
      g.addedge("ml","dl");
      g.addedge("dl","facerecog");
      g.addedge("dataset","facerecog");
       g.dfs();

      return 0;
}
