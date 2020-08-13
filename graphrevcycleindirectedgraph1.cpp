#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
class Graph{
     int v;
     list<int> *l;
public:
      Graph(int v)
      {
          this->v=v;
          l=new list<int> [v];
      }
      void addedge(int x,int y)
      {
        l[x].push_back(y);
      }
      bool cycle_helper(int node,bool* visited,bool* stack)
      {
          //when u visit a node
          visited[node]=true; //that node becomes visited
          stack[node]=true;// that nodes  becomes a member of the path
         for(int nbr:l[node])
         {
            if(stack[nbr]==true) // that particular neghbour of the current node is in call stack and acts as an ancestor wwhich satisfies the condition of backedge
            {
                return true;
            }
             else if(visited[nbr]==false)
             {
                  bool agaysemilega=cycle_helper(nbr,visited,stack);
                  if(agaysemilega==true)
                  {
                      return true;
                  }
             }
         }

         //  leaving a node;
         stack[node]=false;
         return false;


      }
      bool cycle()
      {
          bool *visited=new bool[v];
          bool *stack=new bool[v];
          for(int i=0;i<v;i++)
          {
              visited[i]=false;
              stack[i]=false;
          }
          return cycle_helper(0,visited,stack);


      }



};
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      Graph g(7);
      g.addedge(0,1);
      g.addedge(1,2);
      g.addedge(2,3);
      g.addedge(3,4);
      g.addedge(4,5);
      g.addedge(1,5);
      g.addedge(5,6);
      g.addedge(4,2);
     if(g.cycle())
     {
         cout<<"yes cycle is there"<<endl;
     }
     else
     {
         cout<<"no cycle is there"<<endl;
     }

      return 0;
}
