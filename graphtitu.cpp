#include<bits/stdc++.h>
using namespace std;
//using hashmap
//assuming its a bidirectional edge
class graph{
    // adjlistl
      unordered_map<string,list<pair<string,int> > l;
public:
    void addedge(string x,string y,bool bidir,int wt)
     {
         l[x].push_back(make_pair(y,wt));
         if(bidir)
         {
             l[y].push_back(make_pair(x,wt));
         }


     }
     void print()
     {
         for(auto p:l)
         {
             string city=p.first;
             list<pair<string,int> > nebors=p.second;
             cout<<city<<"->";
             for(auto nbr:nebors)
             {
                cout<<nbr.first<<" "<<nbr.second<<",";
             }
             cout<<endl;
         }


     }
};
int main()
{
   graph g;
   g.addedge("A", "B", true, 20);
   g.addedge("B", "D",true,40);
   g.addedge("A" ,"C",true,10);
   g.addedge("C" ,"D",true,40);
   g.addedge("A", "D",false,50);
   //g.addedge("" "",true)
   return 0;
}
