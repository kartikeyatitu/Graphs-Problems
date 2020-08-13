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

        //  l[y].push_back(x);

      }
       void bfs(T src ,T desti)
      {
             map<T,int> dis;
             map<T,T> parent;
             queue<T> q;
           for(auto node_pair:l)
           {
               T node=node_pair.first;
               dis[node]=INT_MAX;
           }
              q.push(src);
              parent[src]=src;
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
                 parent[nbrs]=node;
                 }
             }

          }


          T temp=desti;
          while(temp!=src)
          {
              cout<<temp<<" ";
              temp=parent[temp];

          }
          cout<<src<<endl;
          cout<<dis[desti]<<endl;




     }

};
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      int board[50];memset(board,0,sizeof(board));
      board[2]=13;
      board[5]=2;
      board[9]=18;
      board[5]=2;
      board[18]=11;
      board[25]=10;
      board[17]=-13;
      board[20]=-14;
      board[24]=-8;
      board[32]-2;
      board[4]=-22;
      Graph<int> g;
      for(int i=0;i<=36;i++)
      {
          for(int dice=1;dice<=6;dice++)
          {
              int j=i+dice;
              j+=board[j];
              if(j<=36)
              {
                  g.addedge(i,j);
              }

          }
      }
      g.addedge(36,36);

      g.bfs(0,36);
}
