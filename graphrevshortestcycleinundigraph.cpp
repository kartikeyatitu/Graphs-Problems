#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
template<typename T>
class Graph{
       map<T,list<T> > l;
public:

        void addegge(int x,int y)
        {

            l[x].push_back(y);
            l[y].push_back(x);
        }
         map<T,int> visited;
            for(auto x1:visited)
            {
                x1.second=INT_MAX;
            }
        void bfs(T src,int &ans)
        {

            queue<T> q;
            q.push(src);
            visited[src]=0;
            while(!q.empty())
            {
                T node=q.front();
                q.pop();
                for(auto nbrs:l[node])
                {
                    if(visited[nbrs]==INT_MAX)
                    {
                        // simple neighboy=urs not backedge
                        visited[nbrs]=visited[node]+1;
                        q.push(nbrs);
                    }
                    else if(visited[nbrs]>=visited[node])
                    {
                         ans+=min(ans,visited[nbrs]+visited[node]+1)
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
     g.addedge(1,2);
     g.addedge(1,3);
     g.addedge(2,4);
     g.addedge(2,5);
     g.addedge(4,5);
     g.addedge(5,3);
    int n=5;
    int ans=n+1;
    for(auto x:l)
    {
        g.bfs(x,ans);
    }
    if(ans==n+1)
    {
        cout<<"not present"<<endl;
    }
    else
    {
        cout<<"cycle of shortest length is"<<ans<<endl;
    }


    return 0;
}




































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
