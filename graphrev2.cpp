#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
class graph{
    int v;
    list<int> *l;
public:
    //constructor
    Graph(int v)
    {
        this->v=v;
        l=new list<int> [v];
    }
    void addedge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void print()
    {
        for(int i=0;i<v;i++)
        {
            cout<<"vertex"<<i<<"->";
            for(int x:l[i])
            {
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      Graph g(4);
      g.addedge(0,1);
      g.addedge(0,2);
      g.addedge(0,1);
      g.addedge(1,2);
      g.addedge(2,3);
      g.print();

}
