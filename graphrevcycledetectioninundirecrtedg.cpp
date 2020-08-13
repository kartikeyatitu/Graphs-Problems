#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
template<typename T>
class Graph
{
    map<T,list<T>> l;
public:
     void addege(T x,T y,bool bidir)
     {
         l[x].push_back(y);
         if(bidir)
         {
             l[y].push_back(x);
         }

     }
     bool dfscycle_helper(T src,map<T,bool> &visited,T parent)
    {
        visited[src]=true;
         for(auto nbr:l[src])
         {

            if(!visited[nbr])
            {
                bool agaymila=dfscycle_helper(nbr,visited,src);
                if(agaymila)
                {
                    return true;
                }

            }
            else if(visited[nbr]==true and nbr!=parent)
            {
                return true;
            }
        }
        return false;
    }
    bool dfscycle()
    {
        map<T,bool> visited;

        for(auto x:l)
         {
            visited[x.first]=false;
         }

        return  dfscycle_helper(0,visited,-1);
    }



};
int main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       Graph<int> g;
       g.addege(0,1,true);
       g.addege(1,2,true);
       g.addege(2,3,true);
       g.addege(3,4,true);
      /* g.addege(4,0,true);*/
       if(g.dfscycle()==true)
       {

           cout<<"contains cycle"<<endl;
       }
       else
       {

           cout<<"does not contain cycle"<<endl;
       }

       return  0;

}

